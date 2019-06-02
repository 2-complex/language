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

    TempFrame* b = machine.temp;
    machine.temp = machine.temp->next;
    delete b;

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

    ++machine.location.index;
}

std::string Call::toString() const
{
    return "call";
}

void Call::execute(Machine& machine)
{
}

std::string Negative::toString() const
{
    return "neg";
}

void Negative::execute(Machine& machine)
{

    ++machine.location.index;
}

std::string Negation::toString() const
{
    return "not";
}

void Negation::execute(Machine& machine)
{

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

    ++machine.location.index;
}

std::string Begin::toString() const
{
    return "(";
}

void Begin::execute(Machine& machine)
{

    ++machine.location.index;
}

std::string End::toString() const
{
    return ")";
}

void End::execute(Machine& machine)
{

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
}

bool Machine::step()
{
    location.procedure->instructions[location.index]->execute(*this);
    //printf( "%s", toString().c_str() );

    return location.index < location.procedure->instructions.size();
}

const object::Node* Machine::top()
{
    return temp->node.get();
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

Universe::Universe(Machine& machine)
    : machine(machine)
{
}

object::Node* Universe::setMapping(object::Node* key, object::Node* value)
{
    return nullptr;
}

object::Node* Universe::getMapping(object::Node* key)
{
    return nullptr;
}

std::string Universe::toString() const
{
    return "UNIVERSE";
}

}
