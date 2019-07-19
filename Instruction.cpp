#include "Instruction.h"
#include "Machine.h"

namespace instruction
{

std::string Underscore::toString() const
{
    return "_";
}

void Underscore::execute(Machine& machine)
{
    machine.temp = new TempFrame(machine.mem->node, machine.temp);
    ++machine.location.index;
}

Push::Push(std::shared_ptr<INode> node)
    : node(node)
{
}

std::string Push::toString() const
{
    return node->toString();
}

void Push::execute(Machine& machine)
{
    machine.temp = new TempFrame(node, machine.temp);
    ++machine.location.index;
}

std::string Pop::toString() const
{
    return ",";
}

void Pop::execute(Machine& machine)
{
    machine.popTemp();
    ++machine.location.index;
}

Operation::Operation(const std::string& name)
    : name(name)
{
    // op = operationNameToFunc[name];
}

std::string Operation::toString() const
{
    return name;
}

void Operation::execute(Machine& machine)
{
    INode* newNode = op(
        machine.temp->next->node.get(),
        machine.temp->node.get()
    );

    machine.popTemp();
    machine.temp->node.reset(newNode);

    ++machine.location.index;
}

OperationAndAssign::OperationAndAssign(const std::string& name)
    : name(name)
{
}

std::string OperationAndAssign::toString() const
{
    return name;
}

void OperationAndAssign::execute(Machine& machine)
{
    ++machine.location.index;
}

std::string Assign::toString() const
{
    return "=";
}

void Assign::execute(Machine& machine)
{
    machine.temp->next->next->node->setMapping(
        machine.temp->next->node, machine.temp->node);

    machine.popTemp();
    machine.popTemp();

    ++machine.location.index;
}

std::string Call::toString() const
{
    return "call";
}

void Call::execute(Machine& machine)
{
    std::shared_ptr<INode> source = machine.temp->next->node;
    std::shared_ptr<INode> index = machine.temp->node;
    machine.popTemp();

    std::shared_ptr<INode> newNode;
    for( std::shared_ptr<MemoryFrame> f = machine.mem; !newNode && f; f = f->next )
    {
        newNode = f->node->getMapping(index);
    }

    // Before I wrote this, and expressed contrition in a comment,
    // Now I can't remember why I did it.
    if( newNode )
    {
        machine.temp->node = newNode;
    }
    else
    {
        machine.popTemp();
    }

    ++machine.location.index;
}

std::string Negative::toString() const
{
    return "neg";
}

void Negative::execute(Machine& machine)
{
    machine.temp->node = std::shared_ptr<INode>(machine.temp->node->Negative());
    ++machine.location.index;
}

std::string Negation::toString() const
{
    return "not";
}

void Negation::execute(Machine& machine)
{
    machine.temp->node = std::shared_ptr<INode>(machine.temp->node->Negation());
    ++machine.location.index;
}


ConstructArray::ConstructArray(int size)
    : size(size)
{
}

std::string ConstructArray::toString() const
{
    return "array : " + std::to_string(size);
}

void ConstructArray::execute(Machine& machine)
{
    std::vector<object::Key> value(size);

    for( size_t i = 0; i < size; ++i )
    {
        value[size-i-1] = machine.temp->node;
        machine.popTemp();
    }

    machine.temp = new TempFrame(std::shared_ptr<INode>(new object::Array()), machine.temp);

    ++machine.location.index;
}

std::string Begin::toString() const
{
    return "(";
}

void Begin::execute(Machine& machine)
{
    std::shared_ptr<object::Object> newObjectPtr = std::shared_ptr<object::Object>(
        new object::Object);

    machine.mem = std::shared_ptr<MemoryFrame>(
        new MemoryFrame(newObjectPtr, machine.mem));

    ++machine.location.index;
}

std::string End::toString() const
{
    return ")";
}

void End::execute(Machine& machine)
{
    machine.mem = machine.mem->next;

    ++machine.location.index;
}

ConstructFunction::ConstructFunction(std::shared_ptr<instruction::Procedure> procedure)
    : procedure(procedure)
{
}

std::string ConstructFunction::toString() const
{
    return "{" + procedure->toString() + "}";
}

void ConstructFunction::execute(Machine& machine)
{
    machine.temp = new TempFrame(
        std::shared_ptr<INode>(
            new StackFunction(
                machine,
                procedure,
                machine.mem)), machine.temp);

    ++machine.location.index;
}

StackFunction::StackFunction(
    Machine& machine,
    std::shared_ptr<Procedure> procedure,
    std::shared_ptr<MemoryFrame> memoryFrame)
    : machine(machine)
    , procedure(procedure)
    , memoryFrame(memoryFrame)
{
}

std::shared_ptr<INode> StackFunction::getMapping(
    std::shared_ptr<INode> argument)
{
    machine.ret = new ReturnFrame(machine.location, machine.ret);
    machine.location = instruction::Location(procedure, -1);
    machine.mem = std::shared_ptr<MemoryFrame>(new MemoryFrame(argument, machine.mem));
    return nullptr;
}

}
