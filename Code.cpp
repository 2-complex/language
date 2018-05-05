#include "Code.h"

#include <stdlib.h>

namespace object
{
    Addable* Addable::operator + (const Addable* other) const
    {
        printf( "Oops, not supposed to get here" );
        return NULL;
    }

    Addable* Addable::operator - (const Addable* other) const
    {
        printf( "Oops, not supposed to get here" );
        return NULL;
    }

    std::string Number::toString() const
    {
        char buffer[1000];
        sprintf(buffer, "%f", value);
        return std::string(buffer);
    }

    Addable* Number::operator + (const Addable* other) const
    {
        if( other->isNumber() )
        {
            return new Number( value + other->asNumber()->value );
        }
        else
        {
            assert(false);
            return NULL;
        }

        assert(false);
        return NULL;
    }

    Addable* Number::operator - (const Addable* other) const
    {
        if( other->isNumber() )
        {
            return new Number( value - other->asNumber()->value );
        }
        else
        {
            assert(false);
            return NULL;
        }

        assert(false);
        return NULL;
    }
}

namespace code
{

std::string Code::toString() const
{
    return std::string("********");
}

Pair::Pair()
{
}

std::string Pair::toString() const
{
    return left->toString() + ":" + right->toString();
}

Assignment::Assignment()
{
}

std::string Assignment::toString() const
{
    return reference->toString() + operation + expression->toString();
}

std::string Program::toString() const
{
    std::string accum;
    for( std::vector<Line*>::const_iterator itr = lines.begin(); itr != lines.end(); itr++ )
    {
        accum += (*itr)->toString() + ",";
    }
    return accum;
}

std::string Call::toString() const
{
    std::string accum = evaluable->toString() + " ";
    for( std::vector<Expression*>::const_iterator itr = expressions.begin();
        itr != expressions.end(); itr++ )
    {
        accum += (*itr)->toString() + " ";
    }
    return accum;
}

AddedList::AddedList(Addable* first)
{
    operands.push_back(first);
}

object::Addable* AddedList::evaluate() const
{
    object::Addable* accum = operands[0]->evaluate();

    size_t n = ops.size();

    for( size_t i = 0; i < n; i++ )
    {
        if( ops[i] == "+" )
        {
            object::Addable* next = operands[i+1]->evaluate();
            object::Addable* newAddable = (*accum) + next;

            delete accum;
            delete next;

            accum = newAddable;
        }
        else if( ops[i] == "-" )
        {
            object::Addable* next = operands[i+1]->evaluate();
            object::Addable* newAddable = (*accum) - next;

            delete accum;
            delete next;

            accum = newAddable;
        }
    }

    return accum;
}

void AddedList::append(const std::string& op, Addable* operand)
{
    ops.push_back(op);
    operands.push_back(operand);
}

std::string AddedList::toString() const
{
    std::string accum;
    size_t n = operands.size();

    for( size_t i = 0; i < n-1; i++ )
        accum += (operands[i])->toString() + ops[i];

    accum += operands[n-1]->toString();

    return accum;
}

Negative::Negative()
{
}

std::string Negative::toString() const
{
    return std::string("-") + operand->toString();
}

Product::Product()
{
}

std::string Product::toString() const
{
    std::string accum;
    size_t n = operands.size();

    for( size_t i = 0; i < n-1; i++ )
        accum += (operands[i])->toString() + ops[i];

    accum += operands[n-1]->toString();

    return accum;
}

Comparison::Comparison(
        Comparable* left,
        std::string op,
        Comparable* right)
        : left(left)
        , op(op)
        , right(right)
{
}

std::string Comparison::toString() const
{
    return left->toString() + op + right->toString();
}

Function::Function(Program* program)
    : program(program)
{
}

std::string Function::toString() const
{
    return std::string("{") + program->toString() + std::string("}");
}

Group::Group(Program* program)
        : program(program)
{
}

std::string Group::toString() const
{
    return std::string("(") + program->toString() + std::string(")");
}

Array::Array()
{
}

std::string Array::toString() const
{
    std::string result = "[";
    for(std::vector<Expression*>::const_iterator itr = elements.begin();
        itr != elements.end();
        itr++)
    {
        result += (*itr)->toString() + ",";
    }
    result += "]";
    return result;
}

Number::Number()
    : value(0.0)
{
}

Number::Number(const std::string& text)
{
    value = atof(text.c_str());
}

std::string Number::toString() const
{
    char buffer[1000];
    sprintf(buffer, "%f", value);
    return std::string(buffer);
}

object::Addable* Number::evaluate() const
{
    return new object::Number(value);
}

Word::Word()
{
}

Word::Word(const std::string& text)
    : name(text)
{
}

std::string Word::toString() const
{
    return name;
}

Member::Member()
{
}

Member::Member(const std::string& text)
    : name(text.substr(1, text.size()-1))
{
}

std::string Member::toString() const
{
    return std::string(".") + name;
}

String::String()
{
}

String::String(const std::string& text)
{
    value = text.substr(1, text.size()-2);
}

std::string String::toString() const
{
    return std::string("\"") + value + std::string("\"");
}

}
