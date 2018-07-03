#include "Code.h"
#include "objects.h"

#include <stdlib.h>

Environment::Environment(object::Object* argument)
    : context(NULL)
    , argument(argument)
{
}

Environment::Environment(Environment* context, object::Object* argument)
    : context(context)
    , argument(argument)
{
}

void Environment::setMember(const std::string& name, object::Node* value)
{
    return argument->setMember(name, value);
}

object::Node* Environment::getMember(const std::string& name)
{
    object::Node* node = argument->getMember(name);
    if( node )
    {
        return node;
    }

    if( context )
    {
        return context->getMember(name);
    }
    else
    {
        return new object::Error("Member not found: " + name);
    }
}

void Environment::setMapping(object::Node* key, object::Node* value)
{
    return argument->setMapping(key, value);
}

object::Node* Environment::getMapping(object::Node* key)
{
    return argument->getMapping(key);
}

object::Node* Environment::getArgument()
{
    return argument;
}

namespace code
{

std::string Code::toString() const
{
    return std::string("********");
}

object::Node* Code::evaluate(Environment& env) const
{
    return new object::Error;
}

Pair::Pair()
{
}

std::string Pair::toString() const
{
    return left->toString() + ":" + right->toString();
}

object::Node* Pair::evaluate(Environment& env) const
{
    env.setMapping(left->evaluate(env), right->evaluate(env));
    return NULL;
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

object::Node* Assignment::evaluate(Environment& env) const
{
    if( operation == "=" )
    {
        reference->setValue(env, expression->evaluate(env));
    }
    else if( operation == "+=" )
    {
        reference->setValue(env, reference->evaluate(env)->Plus(expression->evaluate(env)));
    }
    else if( operation == "-=" )
    {
        reference->setValue(env, reference->evaluate(env)->Minus(expression->evaluate(env)));
    }
    else if( operation == "*=" )
    {
        reference->setValue(env, reference->evaluate(env)->Times(expression->evaluate(env)));
    }
    else if( operation == "/=" )
    {
        reference->setValue(env, reference->evaluate(env)->DividedBy(expression->evaluate(env)));
    }

    object::Node* result = env.getArgument();
    return result;
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

object::Node* Program::evaluate(Environment& env) const
{
    object::Node* result = env.getArgument();
    for( std::vector<Line*>::const_iterator itr = lines.begin(); itr != lines.end(); itr++)
    {
        result = (*itr)->evaluate(env);
    }
    result->retain();
    return result;
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

object::Node* AddedList::evaluate(Environment& env) const
{
    object::Node* accum = operands[0]->evaluate(env);

    size_t n = ops.size();

    for( size_t i = 0; i < n; i++ )
    {
        if( ops[i] == "+" )
        {
            object::Node* next = operands[i+1]->evaluate(env);
            object::Node* newNode = accum->Plus(next);

            accum->release();
            next->release();

            accum = newNode;
        }
        else if( ops[i] == "-" )
        {
            object::Node* next = operands[i+1]->evaluate(env);
            object::Node* newNode = accum->Minus(next);

            accum->release();
            next->release();

            accum = newNode;
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

Negative::Negative(Addable* operand)
    : operand(operand)
{
}

std::string Negative::toString() const
{
    return std::string("-") + operand->toString();
}

object::Node* Negative::evaluate(Environment& env) const
{
    return operand->evaluate(env)->Negative();
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

object::Node* Product::evaluate(Environment& env) const
{
    object::Node* accum = operands[0]->evaluate(env);

    size_t n = ops.size();

    for( size_t i = 0; i < n; i++ )
    {
        if( ops[i] == "*" )
        {
            object::Node* next = operands[i+1]->evaluate(env);
            object::Node* newNode = accum->Times(next);

            accum->release();;
            next->release();;

            accum = newNode;
        }
        else if( ops[i] == "/" )
        {
            object::Node* next = operands[i+1]->evaluate(env);
            object::Node* newNode = accum->DividedBy(next);

            accum->release();;
            next->release();;

            accum = newNode;
        }
        else if( ops[i] == "%" )
        {
            object::Node* next = operands[i+1]->evaluate(env);
            object::Node* newNode = accum->Mod(next);

            accum->release();;
            next->release();;

            accum = newNode;
        }
    }

    return accum;
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

object::Node* Conjunction::evaluate(Environment& env) const
{
    object::Node* accum = operands[0]->evaluate(env);

    size_t n = ops.size();

    for( size_t i = 0; i < n; i++ )
    {
        if( ops[i] == "and" )
        {
            object::Node* next = operands[i+1]->evaluate(env);
            object::Node* newNode = accum->And(next);

            accum->release();;
            next->release();;

            accum = newNode;
        }
        else if( ops[i] == "or" )
        {
            object::Node* next = operands[i+1]->evaluate(env);
            object::Node* newNode = accum->Or(next);

            accum->release();;
            next->release();;

            accum = newNode;
        }
    }

    return accum;
}

Negation::Negation(Logicable* operand)
    : operand(operand)
{
}

std::string Negation::toString() const
{
    return std::string("not ") + operand->toString();
}

object::Node* Negation::evaluate(Environment& env) const
{
    return operand->evaluate(env)->Negation();
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

object::Node* Comparison::evaluate(Environment& env) const
{
    if( op == "==" )
    {
        return left->evaluate(env)->Equals( right->evaluate(env) );
    }
    else if( op == "!=" )
    {
        return left->evaluate(env)->NotEquals( right->evaluate(env) );
    }
    else if( op == "<=" )
    {
        return left->evaluate(env)->LessThanOrEqualTo( right->evaluate(env) );
    }
    else if( op == ">=" )
    {
        return left->evaluate(env)->GreaterThanOrEqualTo( right->evaluate(env) );
    }
    else if( op == "<" )
    {
        return left->evaluate(env)->LessThan( right->evaluate(env) );
    }
    else //( op == ">" )
    {
        return left->evaluate(env)->GreaterThan( right->evaluate(env) );
    }
}

Function::Function(Program* program)
    : program(program)
{
}

std::string Function::toString() const
{
    return std::string("{") + program->toString() + std::string("}");
}

object::Node* Function::evaluate(Environment& env) const
{
    return new object::Function(&env, program);
}

Group::Group(Program* program)
    : program(program)
{
}

std::string Group::toString() const
{
    return std::string("(") + program->toString() + std::string(")");
}

object::Node* Group::evaluate(Environment& env) const
{
    Environment ext(&env, new object::Object);
    return program->evaluate(ext);
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

object::Node* Array::evaluate(Environment& env) const
{
    object::Array* array = new object::Array;

    for(std::vector<Expression*>::const_iterator itr = elements.begin();
        itr != elements.end();
        itr++)
    {
        array->append((*itr)->evaluate(env));
    }

    printf( "returning array %s\n", array->toString().c_str() );
    return array;
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

object::Node* Boolean::evaluate(Environment& env) const
{
    return new object::Boolean(value);
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

object::Node* Number::evaluate(Environment& env) const
{
    bool isFloat = false;
    for( size_t i = 0; i < text.size(); ++i)
    {
        if( text[i] == '.' )
            isFloat = true;
    }

    if( isFloat )
    {
        return new object::Double(text);
    }
    else
    {
        return new object::Integer(text);
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

object::Node* String::evaluate(Environment& env) const
{
    return new object::String(value);
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

object::Node* Word::evaluate(Environment& env) const
{
    return env.getMember(name);
}

void Word::setValue(Environment& env, object::Node* value) const
{
    env.setMember(name, value);
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

}
