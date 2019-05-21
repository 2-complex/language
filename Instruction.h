#ifndef _Instruction_
#define _Instruction_

#include <string>

namespace object
{
    class Node;
};

namespace code
{
    class Program;
};

namespace instruction
{

class Instruction
{
public:
    Instruction();
    virtual ~Instruction();

    virtual std::string toString() const = 0;
};

class Underscore : public Instruction
{
public:
    virtual std::string toString() const;
};

class Disregard : public Instruction
{
public:
    virtual std::string toString() const;
};

class Push : public Instruction
{
    object::Node* n;

public:
    explicit Push(object::Node* n);

    virtual std::string toString() const;
};

class Operation : public Instruction
{
    std::string op;

public:
    explicit Operation(const std::string& op);
    virtual std::string toString() const;
};

class Negative : public Instruction
{
public:
    virtual std::string toString() const;
};

class Negation : public Instruction
{
public:
    virtual std::string toString() const;
};

class ConstructArray : public Instruction
{
    int size;

public:
    explicit ConstructArray(int size);
    virtual std::string toString() const;
};

class Begin : public Instruction
{
    std::string op;

public:
    explicit Begin(const std::string& op);
    virtual std::string toString() const;
};

class End : public Instruction
{
    std::string op;

public:
    explicit End(const std::string& op);
    virtual std::string toString() const;
};

class Jump : public Instruction
{
    code::Program* program;

public:
    Jump(code::Program* program);
    virtual std::string toString() const;
};

}

#endif
