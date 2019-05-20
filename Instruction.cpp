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

Operation::Operation(std::string op)
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

Jump::Jump(code::Program* program)
    : program(program)
{
}

std::string Jump::toString() const
{
    return program->toString();
}

}
