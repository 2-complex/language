#ifndef _Code_
#define _Code_

#include <string>
#include <vector>

#include <assert.h>

#include "objects.h"

namespace code
{

class Code
{
public:
    virtual std::string toString() const;
    virtual object::Node* evaluate() const;
};

class Line : public Code
{
};

class Expression : public Line
{
};

class Pair : public Line
{
public:
    Pair();

    Expression* left;
    Expression* right;

    virtual std::string toString() const override;
};

class Reference : public Code
{
};

class Assignment : public Line
{
public:
    Reference* reference;
    std::string operation;
    Expression* expression;

    Assignment();
    virtual std::string toString() const override;
};

class Program : public Code
{
public:
    std::vector<Line*> lines;

    virtual std::string toString() const override;
    virtual object::Node* evaluate() const override;
};

class Comparable : public Code
{
};

class Logicable : public Code
{
};

class Addable : public Expression
{
public:
    virtual object::Node* evaluate() const = 0;
};

class Multiplyable : public Code
{
};

class Evaluable : public Code
{
};

class Call : public Code
{
public:
    Evaluable* evaluable;
    std::vector<Expression*> expressions;

    virtual std::string toString() const override;
};

class AddedList : public Code
{
public:
    AddedList(Addable* first);

    std::vector<Addable*> operands;
    std::vector<std::string> ops;

    void append(const std::string& op, Addable* operand);

    virtual std::string toString() const override;

    object::Node* evaluate() const;
};

class Negative : public Code
{
public:
    Negative();

    Addable* operand;

    virtual std::string toString() const override;
};

class Product : public Code
{
public:
    Product(Multiplyable* first);

    std::vector<Multiplyable*> operands;
    std::vector<std::string> ops;

    void append(const std::string& op, Multiplyable* operand);

    virtual std::string toString() const override;
    virtual object::Node* evaluate() const override;
};

class Conjunction : public Code
{
public:
    Conjunction(Logicable* first);

    std::vector<Logicable*> operands;
    std::vector<std::string> ops;

    void append(const std::string& op, Logicable* operand);

    virtual std::string toString() const override;
};

class Negation : public Code
{
public:
    Negation();

    Logicable* operand;

    virtual std::string toString() const override;
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
};

class Function : public Expression
{
private:
    Program* program;

public:
    Function(Program* program);
    virtual std::string toString() const override;
};

class Group : public Expression
{
private:
    Program* program;

public:
    Group(Program* program);

    std::string toString() const override;
};

class Array : public Expression
{
public:
    Array();
    std::vector<Expression*> elements;
    virtual std::string toString() const override;
};

class Number : public Addable
{
private:
    std::string text;
public:

    Number();
    Number(const std::string& text);

    virtual std::string toString() const override;
    virtual object::Node* evaluate() const override;
};

class Boolean : public Expression
{
private:
    bool value;
public:

    Boolean();
    Boolean(const std::string& text);

    virtual std::string toString() const override;
};

class Word : public Expression
{
private:
    std::string name;
public:

    Word();
    Word(const std::string& text);

    virtual std::string toString() const;
};

class Member : public Expression
{
private:
    std::string name;
public:

    Member();
    Member(const std::string& text);
    virtual std::string toString() const override;
};

class String : public Expression
{
private:
    std::string value;
public:

    String();
    String(const std::string& text);
    virtual std::string toString() const override;
};

}

#endif
