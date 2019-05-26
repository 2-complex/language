#include "Instruction.h"

#include "objects.h"
#include "code.h"

namespace instruction
{

Instruction::Instruction()
{
}

Instruction::~Instruction()
{
}

std::string Procedure::toString() const
{
    std::string result;

    for( std::vector< instruction::Instruction* >::const_iterator itr = instructions.begin();
        itr != instructions.end();
        itr++ )
    {
        result += (*itr)->toString() + "\n";
    }

    return result;
}

std::string Underscore::toString() const
{
    return "_";
}

void Underscore::execute(Machine& machine) const
{
}

Push::Push(object::Node* n)
    : n(n)
{
}

std::string Push::toString() const
{
    return n->toString();
}

void Push::execute(Machine& machine) const
{
}

Operation::Operation(const std::string& name)
    : name(name)
{
}

std::string Operation::toString() const
{
    return name;
}

void Operation::execute(Machine& machine) const
{
}

OperationAndAssign::OperationAndAssign(const std::string& name)
    : name(name)
{
}

std::string OperationAndAssign::toString() const
{
    return name;
}

void OperationAndAssign::execute(Machine& machine) const
{
}

std::string Assign::toString() const
{
    return "=";
}

void Assign::execute(Machine& machine) const
{
}

std::string Negative::toString() const
{
    return "neg";
}

void Negative::execute(Machine& machine) const
{
}

std::string Negation::toString() const
{
    return "not";
}

void Negation::execute(Machine& machine) const
{
}


ConstructArray::ConstructArray(int size)
    : size(size)
{
}

std::string ConstructArray::toString() const
{
    return "array : " + std::to_string(size);
}

void ConstructArray::execute(Machine& machine) const
{
}

std::string Begin::toString() const
{
    return "(";
}

void Begin::execute(Machine& machine) const
{
}

std::string End::toString() const
{
    return ")";
}

void End::execute(Machine& machine) const
{
}

ConstructFunction::ConstructFunction(std::shared_ptr<instruction::Procedure> procedure)
    : procedure(procedure)
{
}

std::string ConstructFunction::toString() const
{
    return "PROCEDURE\n" + procedure->toString() + "END\n";
}

void ConstructFunction::execute(Machine& machine) const
{
}

Location::Location(std::shared_ptr<Procedure>& procedure, size_t index)
    : procedure(procedure)
    , index(index)
{
}

Machine::Machine(const Location& startingLocation)
    : location(startingLocation)
{
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
