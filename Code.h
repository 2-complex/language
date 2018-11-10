#ifndef _Code_
#define _Code_

#include <string>
#include <vector>

#include <assert.h>

#include "objects.h"


namespace code
{

/*! When Calamity gets paresed into a tree of objects.
    Code is the base class of those objects.
*/
class Code
{
public:
    virtual std::string toString() const = 0;
    virtual object::Node* evaluate(Environment& env) const = 0;
};

class Line : public Code
{
};

/*! Expression represents any evaluable substring of code:
    x+7
    (z=2)

    Not an assignment:
    n = 3  <- not an Expression.
*/
class Expression : public Line
{
public:
    virtual object::Node* evaluateButLast(Environment& env) const;
    virtual object::Node* evaluateLast(Environment& env) const;
};

/*! A Pair is an element of a Group (object literal) i.e.
    (
        x = "ex",
        4: "four",
        *: "",
    )

    x = "ex", 4: "four" and *: "" are Pairs
*/
class Pair : public Line
{
public:
    Pair();

    Expression* left;
    Expression* right;

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const;
};

/*! Assignment is a piece of code that assigns a value to a variable
    such as:

    n = 3
    n += 1
*/
class Assignment : public Line
{
public:
    Expression* reference;
    std::string operation;
    Expression* expression;

    Assignment();
    Assignment(
        Expression* reference,
        const std::string& operation,
        Expression* expression);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

/*! A Program is a bunch of lines of code.  This can be the contents of a function,
    or it can be the contents of a group (object literal) or it can be the contents
    of a file.*/
class Program : public Code
{
public:
    std::vector<Line*> lines;

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Comparable : public Code
{
};

class Addable : public Expression
{
public:
    virtual object::Node* evaluate(Environment& env) const = 0;
};

class Logicable : public Expression
{
public:
    virtual object::Node* evaluate(Environment& env) const = 0;
};

class Call : public Expression
{
public:
    std::vector<Expression*> expressions;

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
    virtual object::Node* evaluateButLast(Environment& env) const override;
    virtual object::Node* evaluateLast(Environment& env) const override;
};

class AddedList : public Code
{
public:
    AddedList(Addable* first);

    std::vector<Addable*> operands;
    std::vector<std::string> ops;

    void append(const std::string& op, Addable* operand);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Negative : public Code
{
public:
    Negative();
    Negative(Addable* operand);

    Addable* operand;

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Product : public Code
{
public:
    Product(Expression* first);

    std::vector<Expression*> operands;
    std::vector<std::string> ops;

    void append(const std::string& op, Expression* operand);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Conjunction : public Code
{
public:
    Conjunction(Logicable* first);

    std::vector<Logicable*> operands;
    std::vector<std::string> ops;

    void append(const std::string& op, Logicable* operand);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Negation : public Code
{
public:
    Negation(Logicable* operand);

    Logicable* operand;

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Comparison : public Logicable
{
private:
    Comparable* left;
    std::string op;
    Comparable* right;

public:
    Comparison(
        Comparable* left,
        std::string op,
        Comparable* right);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Function : public Expression
{
private:
    Program* program;

public:
    Function(Program* program);
    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Group : public Expression
{
private:
    Program* program;

public:
    Group(Program* program);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Array : public Addable
{
public:
    Array();
    std::vector<Expression*> elements;
    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Number
    : public Addable
{
private:
    std::string text;
public:

    Number();
    Number(const std::string& text);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Boolean : public Logicable
{
private:
    bool value;
public:

    Boolean();
    Boolean(const std::string& text);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class Word
    : public Expression
{
private:
    std::string name;
public:

    Word();
    Word(const std::string& text);

    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
    virtual object::Node* evaluateLast(Environment& env) const;
};

class Member : public Expression
{
private:
    std::string name;
public:

    Member(const std::string& text);
    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

class String : public Addable
{
private:
    std::string value;
public:

    String();
    String(const std::string& text);
    virtual std::string toString() const override;
    virtual object::Node* evaluate(Environment& env) const override;
};

}

#endif
