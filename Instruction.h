#ifndef _Instruction_
#define _Instruction_

#include "objects.h"

#include <memory>
#include <vector>
#include <string>
#include <stack>
#include <functional>

namespace code
{
    class Program;
};

namespace instruction
{

class Machine;

class Instruction
{
public:
    Instruction();
    virtual ~Instruction();

    virtual std::string toString() const = 0;
    virtual void execute(Machine& machine) const = 0;
};

class Procedure
{
public:
    std::vector<Instruction*> instructions;

    virtual std::string toString() const;
};

class Location
{
    Location(
        std::shared_ptr<Procedure>& procedure,
        size_t index);

public:
    std::shared_ptr<Procedure> procedure;
    size_t index;
};

class MemoryFrame
{
public:
    std::shared_ptr<object::Object> obj;
    std::shared_ptr<class MemoryFrame> next;
};

class Machine
{
public:
    explicit Machine(const Location& startingLocation);

    Location location;

    std::stack<std::shared_ptr<object::Node>> temp;
    std::stack<Location> call;
    std::shared_ptr<MemoryFrame> memory;

    bool step();
};

class Underscore : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class Push : public Instruction
{
    object::Node* n;

public:
    explicit Push(object::Node* n);

    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

typedef
    std::function<object::Node*(const object::Node* a, const object::Node* b)>
    OperationFunction;

class Operation : public Instruction
{
    OperationFunction op;
    std::string name;

public:
    explicit Operation(const std::string& opName);
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class OperationAndAssign : public Instruction
{
    OperationFunction op;
    std::string name;

public:
    explicit OperationAndAssign(const std::string& opName);
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class Assign : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class Negative : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class Negation : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class ConstructArray : public Instruction
{
    int size;

public:
    explicit ConstructArray(int size);
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class Begin : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class End : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class ConstructFunction : public Instruction
{
    std::shared_ptr<Procedure> procedure;

public:
    ConstructFunction(std::shared_ptr<Procedure> procedure);
    virtual std::string toString() const;
    virtual void execute(Machine& machine) const;
};

class Universe : public object::Object
{
    Machine& machine;

public:
    explicit Universe(Machine& machine);

    virtual object::Node* setMapping(object::Node* key, object::Node* value);
    virtual object::Node* getMapping(object::Node* key);

    virtual std::string toString() const override;
};

}

#endif
