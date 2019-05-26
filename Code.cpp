#include "Code.h"

#include "objects.h"
#include "Environment.h"

#include <stdlib.h>

namespace code
{

Pair::Pair()
{
}

std::string Pair::toString() const
{
    return left->toString() + ":" + right->toString();
}

void Pair::makeInstructions(instruction::Procedure& procedure) const
{
    procedure.instructions.push_back(new instruction::Underscore);
    left->makeInstructions(procedure);
    right->makeInstructions(procedure);
    procedure.instructions.push_back(new instruction::Assign);
}

Assignment::Assignment()
{
}

Assignment::Assignment(
    Expression* reference,
    const std::string& operation,
    Expression* expression)
    : reference(reference)
    , operation(operation)
    , expression(expression)
{
}

std::string Assignment::toString() const
{
    return reference->toString() + operation + expression->toString();
}

void Assignment::makeInstructions(instruction::Procedure& procedure) const
{
    if( operation == "=" )
    {
        reference->makeInstructionsButLast(procedure);
        expression->makeInstructions(procedure);
        procedure.instructions.push_back(new instruction::Assign);
    }
    else
    {
        reference->makeInstructionsButLast(procedure);
        expression->makeInstructions(procedure);
        procedure.instructions.push_back(new instruction::OperationAndAssign(operation));
    }
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

void Program::makeInstructions(instruction::Procedure& procedure) const
{
    for( std::vector<Line*>::const_iterator itr = lines.begin(); itr != lines.end(); ++itr )
    {
        (*itr)->makeInstructions(procedure);
    }
}

std::string Call::toString() const
{
    std::string accum;

    for( std::vector<Expression*>::const_iterator itr = expressions.begin(); itr != expressions.end(); itr++ )
    {
        accum += (*itr)->toString() + " ";
    }
    return accum;
}

void Call::makeInstructions(
    instruction::Procedure& procedure) const
{
    expressions[0]->makeInstructions(procedure);

    size_t n = expressions.size();
    for( size_t i = 1; i < n; i++ )
    {
        expressions[i]->makeInstructions(procedure);
        procedure.instructions.push_back(new instruction::Operation("call"));
    }
}

void Call::makeInstructionsButLast(
    instruction::Procedure& procedure) const
{
    expressions[0]->makeInstructions(procedure);

    size_t n = expressions.size()-1;
    for( size_t i = 1; i < n; i++ )
    {
        expressions[i]->makeInstructions(procedure);
        procedure.instructions.push_back(new instruction::Operation("call"));
    }
    expressions[n]->makeInstructions(procedure);
}

AddedList::AddedList(Addable* first)
{
    operands.push_back(first);
}

void AddedList::makeInstructions(
    instruction::Procedure& procedure) const
{
    operands[0]->makeInstructions(procedure);

    size_t n = ops.size();
    for( size_t i = 0; i < n; ++i )
    {
        operands[i+1]->makeInstructions(procedure);
        procedure.instructions.push_back(new instruction::Operation(ops[i]));
    }
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

Negative::Negative(Addable* operand)
    : operand(operand)
{
}

std::string Negative::toString() const
{
    return std::string("-") + operand->toString();
}

void Negative::makeInstructions(
    instruction::Procedure& procedure) const
{
    operand->makeInstructions(procedure);
    procedure.instructions.push_back(new instruction::Negative);
}

Product::Product(Expression* first)
{
    operands.push_back(first);
}

void Product::append(const std::string& op, Expression* operand)
{
    ops.push_back(op);
    operands.push_back(operand);
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

void Product::makeInstructions(
    instruction::Procedure& procedure) const
{
    operands[0]->makeInstructions(procedure);

    size_t n = ops.size();
    for( size_t i = 0; i < n; ++i )
    {
        operands[i+1]->makeInstructions(procedure);
        procedure.instructions.push_back(new instruction::Operation(ops[i]));
    }
}

Conjunction::Conjunction(Logicable* first)
{
    operands.push_back(first);
}

void Conjunction::append(const std::string& op, Logicable* operand)
{
    ops.push_back(op);
    operands.push_back(operand);
}

std::string Conjunction::toString() const
{
    std::string accum;
    size_t n = operands.size();

    for( size_t i = 0; i < n-1; i++ )
        accum += (operands[i])->toString() + " " + ops[i] + " ";

    accum += operands[n-1]->toString();

    return accum;
}

void Conjunction::makeInstructions(
    instruction::Procedure& procedure) const
{
    operands[0]->makeInstructions(procedure);

    size_t n = ops.size();
    for( size_t i = 0; i < n; ++i )
    {
        operands[i+1]->makeInstructions(procedure);
        procedure.instructions.push_back(new instruction::Operation(ops[i]));
    }
}

Negation::Negation(Logicable* operand)
    : operand(operand)
{
}

std::string Negation::toString() const
{
    return std::string("not ") + operand->toString();
}

void Negation::makeInstructions(
    instruction::Procedure& procedure) const
{
    operand->makeInstructions(procedure);
    procedure.instructions.push_back(new instruction::Negation);
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

void Comparison::makeInstructions(
    instruction::Procedure& procedure) const
{
    left->makeInstructions(procedure);
    right->makeInstructions(procedure);
    procedure.instructions.push_back(new instruction::Operation(op));
}

Function::Function(Program* program)
    : program(program)
{
}

std::string Function::toString() const
{
    return std::string("{") + program->toString() + std::string("}");
}

void Function::makeInstructions(
    instruction::Procedure& procedure) const
{
    instruction::Procedure* newProcedure =
        new instruction::Procedure;

    program->makeInstructions(*newProcedure);

    instruction::ConstructFunction* constructFunction =
        new instruction::ConstructFunction(std::shared_ptr<instruction::Procedure>(newProcedure));

    procedure.instructions.push_back(constructFunction);
}

Group::Group(Program* program)
    : program(program)
{
}

std::string Group::toString() const
{
    return std::string("(") + program->toString() + std::string(")");
}

void Group::makeInstructions(
    instruction::Procedure& procedure) const
{
    procedure.instructions.push_back(new instruction::Begin);
    program->makeInstructions(procedure);
    procedure.instructions.push_back(new instruction::End);
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

void Array::makeInstructions(
    instruction::Procedure& procedure) const
{
    for(std::vector<Expression*>::const_iterator itr = elements.begin();
        itr != elements.end();
        itr++)
    {
        (*itr)->makeInstructions(procedure);
    }

    procedure.instructions.push_back(new instruction::ConstructArray(elements.size()));
}

Boolean::Boolean()
    : value(false)
{
}

Boolean::Boolean(const std::string& text)
{
    value = (text == "true");
}

std::string Boolean::toString() const
{
    return std::string(value ? "true" : "false");
}

void Boolean::makeInstructions(
    instruction::Procedure& procedure) const
{
    procedure.instructions.push_back(new instruction::Push(new object::Boolean(value)));
}

Number::Number()
    : text("0")
{
}

Number::Number(const std::string& text)
    : text(text)
{
}

std::string Number::toString() const
{
    return text;
}

void Number::makeInstructions(
    instruction::Procedure& procedure) const
{
    bool isFloat = false;
    for( size_t i = 0; i < text.size(); ++i)
    {
        if( text[i] == '.' )
            isFloat = true;
    }

    if( isFloat )
    {
        procedure.instructions.push_back(new instruction::Push(new object::Double(text)));
    }
    else
    {
        procedure.instructions.push_back(new instruction::Push(new object::Integer(text)));
    }
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

void String::makeInstructions(
    instruction::Procedure& procedure) const
{
    procedure.instructions.push_back(new instruction::Push(new object::String(value)));
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

void Word::makeInstructions(
    instruction::Procedure& procedure) const
{
    procedure.instructions.push_back(new instruction::Underscore);
    procedure.instructions.push_back(new instruction::Push(new object::Member(name)));
    procedure.instructions.push_back(new instruction::Operation("call"));
}

void Word::makeInstructionsButLast(
    instruction::Procedure& procedure) const
{
    procedure.instructions.push_back(new instruction::Underscore);
    procedure.instructions.push_back(new instruction::Push(new object::Member(name)));
}

void Expression::makeInstructionsButLast(
    instruction::Procedure& procedure) const
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

void Member::makeInstructions(
    instruction::Procedure& procedure) const
{
    procedure.instructions.push_back(new instruction::Push(new object::Member(name)));
}

}
