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

std::string Disregard::toString() const
{
    return "disregard";
}

Push::Push(object::Node* n)
    : n(n)
{
}

std::string Push::toString() const
{
    return n->toString();
}

Operation::Operation(const std::string& op)
    : op(op)
{
}

std::string Operation::toString() const
{
    return std::string(op);
}

std::string Negative::toString() const
{
    return "neg";
}

std::string Negation::toString() const
{
    return "not";
}

ConstructArray::ConstructArray(int size)
    : size(size)
{
}

std::string ConstructArray::toString() const
{
    return "array : " + std::to_string(size);
}

Begin::Begin(const std::string& op)
    : op(op)
{
}

std::string Begin::toString() const
{
    return op;
}

End::End(const std::string& op)
    : op(op)
{
}

std::string End::toString() const
{
    return op;
}

ConstructFunction::ConstructFunction(std::shared_ptr<instruction::Procedure> procedure)
    : procedure(procedure)
{
}

std::string ConstructFunction::toString() const
{
    return "PROCEDURE\n" + procedure->toString() + "END\n";
}

}
