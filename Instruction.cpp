#include "Instruction.h"

#include "objects.h"
#include "code.h"

#include <unordered_map>

namespace instruction
{

Instruction::Instruction()
{
}

Instruction::~Instruction()
{
}

Procedure::~Procedure()
{
    for( std::vector<instruction::Instruction*>::iterator itr = instructions.begin();
        itr != instructions.end();
        ++itr )
    {
        delete *itr;
    }
}

std::string Procedure::toString() const
{
    std::string result;

    for( std::vector<instruction::Instruction*>::const_iterator itr = instructions.begin();
        itr != instructions.end();
        ++itr )
    {
        result += (*itr)->toString();
    }

    return result;
}

MemoryFrame::MemoryFrame(
    std::shared_ptr<object::Node> node,
    std::shared_ptr<class MemoryFrame> next)
    : node(node)
    , next(next)
{
}

std::string MemoryFrame::toString() const
{
    return node->toString();
}

ReturnFrame::ReturnFrame(
    const Location& location,
    class ReturnFrame* next)
    : location(location)
    , next(next)
{
}

std::string ReturnFrame::toString() const
{
    return location.toString();
}

TempFrame::TempFrame(
    std::shared_ptr<object::Node> node,
    class TempFrame* next)
    : node(node)
    , next(next)
{
}

std::string TempFrame::toString() const
{
    return node->toString();
}

std::string Underscore::toString() const
{
    return "_";
}

void Underscore::execute(Machine& machine)
{
    machine.temp = new TempFrame(machine.mem->node, machine.temp);
    ++machine.location.index;
}

Push::Push(std::shared_ptr<object::Node> node)
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

struct OperationNameToFunc : public std::unordered_map<std::string, OperationFunction>
{
    OperationNameToFunc()
    {
        (*this)["and"] = object::fAnd;
        (*this)["or"] = object::fOr;
        (*this)["+"] = object::fPlus;
        (*this)["-"] = object::fMinus;
        (*this)["*"] = object::fTimes;
        (*this)["/"] = object::fDividedBy;
        (*this)["%"] = object::fMod;
        (*this)["=="] = object::fEquals;
        (*this)["!="] = object::fNotEquals;
        (*this)["<"] = object::fLessThan;
        (*this)[">"] = object::fGreaterThan;
        (*this)["<="] = object::fLessThanOrEqualTo;
        (*this)[">="] = object::fGreaterThanOrEqualTo;
    }
} operationNameToFunc;


Operation::Operation(const std::string& name)
    : name(name)
{
    op = operationNameToFunc[name];
}

std::string Operation::toString() const
{
    return name;
}

void Operation::execute(Machine& machine)
{
    object::Node* newNode = op(
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
    std::shared_ptr<object::Node> source = machine.temp->next->node;
    std::shared_ptr<object::Node> index = machine.temp->node;
    machine.popTemp();

    std::shared_ptr<object::Node> newNode = source->getMapping(index);

    // Sorry : (
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
    machine.temp->node = std::shared_ptr<object::Node>(machine.temp->node->Negative());
    ++machine.location.index;
}

std::string Negation::toString() const
{
    return "not";
}

void Negation::execute(Machine& machine)
{
    machine.temp->node = std::shared_ptr<object::Node>(machine.temp->node->Negation());
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

    machine.temp = new TempFrame(std::shared_ptr<object::Node>(
        new object::Array(value)), machine.temp);

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
        std::shared_ptr<object::Node>(
            new StackFunction(
                machine,
                procedure,
                machine.mem)), machine.temp);

    ++machine.location.index;
}

Location::Location(std::shared_ptr<Procedure> procedure, size_t index)
    : procedure(procedure)
    , index(index)
{
}

std::string Location::toString() const
{
    return procedure->toString() + "(" + std::to_string(index) + ")";
}

Machine::Machine()
    : location(std::shared_ptr<Procedure>(new Procedure), -1)
    , temp(nullptr)
    , ret(nullptr)
{
    mem.reset(new MemoryFrame(
        std::shared_ptr<object::Object>(
            new object::Object),
            nullptr));
}

bool Machine::step()
{
    if( location.index < location.procedure->instructions.size() )
    {
        printf( "exectue:\n" );
        printf( "%s\n", location.procedure->instructions[location.index]->toString().c_str() );
        location.procedure->instructions[location.index]->execute(*this);
        printf( "%s", toString().c_str() );
    }

    if( location.index < location.procedure->instructions.size() )
    {
        return true;
    }
    else
    {
        if( ret )
        {
            location = ret->location;
            ++location.index;
            ReturnFrame* b = ret;
            ret = ret->next;
            mem = mem->next;
            delete b;
            return true;
        }
    }

    return false;
}

void Machine::popTemp()
{
    TempFrame* b = temp;
    temp = temp->next;
    delete b;
}

object::Node* Machine::top() const
{
    if( temp )
    {
        return temp->node.get();
    }

    return nullptr;
}

std::string Machine::toString() const
{
    std::string result = "";

    result += "machine:\n";

    for( TempFrame* f = temp; f; f=f->next )
    {
        result += std::string("    ") + f->toString() + "\n";
    }

    result += "memory-stack:\n";

    for( std::shared_ptr<MemoryFrame> f = mem; f; f=f->next )
    {
        result += std::string("    ") + f->toString() + "\n";
    }

    result += "return-stack:\n";

    for( ReturnFrame* f = ret; f; f=f->next )
    {
        result += std::string("    ") + f->toString() + "\n";
    }

    return result;
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

std::shared_ptr<object::Node> StackFunction::getMapping(
    std::shared_ptr<object::Node> argument)
{
    machine.ret = new ReturnFrame(machine.location, machine.ret);
    machine.location = instruction::Location(procedure, -1);
    machine.mem = std::shared_ptr<MemoryFrame>(new MemoryFrame(argument, machine.mem));
    return nullptr;
}

}
