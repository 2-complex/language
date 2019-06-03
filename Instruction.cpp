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
        result += (*itr)->toString() + "\n";
    }

    return result;
}

MemoryFrame::MemoryFrame(
    std::shared_ptr<object::Object> obj,
    std::shared_ptr<class MemoryFrame> next)
    : obj(obj)
    , next(next)
{
}

ReturnFrame::ReturnFrame(
    const Location& location,
    class ReturnFrame* next)
    : location(location)
    , next(next)
{
}

TempFrame::TempFrame(
    std::shared_ptr<object::Node> node,
    class TempFrame* next)
    : node(node)
    , next(next)
{
}

std::string Underscore::toString() const
{
    return "_";
}

void Underscore::execute(Machine& machine)
{
    machine.temp = new TempFrame(machine.mem->obj, machine.temp);
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
    machine.temp->node = source->getMapping(index);
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
    return "PROCEDURE\n" + procedure->toString() + "END\n";
}

void ConstructFunction::execute(Machine& machine)
{

    ++machine.location.index;
}

Location::Location(std::shared_ptr<Procedure>& procedure, size_t index)
    : procedure(procedure)
    , index(index)
{
}

Machine::Machine(const Location& startingLocation)
    : location(startingLocation)
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
    printf( "exectue: %s\n", location.procedure->instructions[location.index]->toString().c_str() );
    location.procedure->instructions[location.index]->execute(*this);
    printf( "%s", toString().c_str() );

    return location.index < location.procedure->instructions.size();
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
    std::string result = "m:\n";

    for( TempFrame* f = temp; f; f=f->next )
    {
        result += std::string("    ") + f->node->toString() + "\n";
    }

    return result;
}

}
