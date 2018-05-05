#ifndef _Code_
#define _Code_

#include <string>
#include <vector>

#include <assert.h>


namespace object
{

class Object;
class Number;

class Object
{
public:
    virtual ~Object() {}

    virtual std::string toString() const = 0;
    virtual bool isNumber() const = 0;
    virtual const Number* asNumber() const = 0;
};

class Addable : public Object
{
public:
    virtual ~Addable() {}

    virtual object::Addable* operator + (const object::Addable* other) const;
    virtual object::Addable* operator - (const object::Addable* other) const;

    virtual bool isNumber() const {assert(false); return false;}
};

class Number : public Addable
{
    double value;

public:
    Number(double value) : value(value) {}
    virtual ~Number() {}

    virtual std::string toString() const;

    virtual const Number* asNumber() const override {return this;}
    virtual bool isNumber() const override {return true;}

    virtual object::Addable* operator + (const object::Addable* other) const override;
    virtual object::Addable* operator - (const object::Addable* other) const override;
};

}


namespace code
{

class Code
{
public:
    virtual std::string toString() const;
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
    virtual object::Addable* evaluate() const = 0;
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

    object::Addable* evaluate() const;
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
    Product();

    std::vector<Multiplyable*> operands;
    std::vector<std::string> ops;

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
    double value;
public:

    Number();
    Number(const std::string& text);

    virtual std::string toString() const override;
    virtual object::Addable* evaluate() const override;
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
