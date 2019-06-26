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
    virtual void execute(Machine& machine) = 0;
};

class Procedure
{
public:
    virtual ~Procedure();
    std::vector<Instruction*> instructions;

    std::string toString() const;
};

class Location
{
public:
    Location(
        std::shared_ptr<Procedure> procedure,
        size_t index);

    std::shared_ptr<Procedure> procedure;
    size_t index;

    std::string toString() const;
};

class MemoryFrame
{
public:
    MemoryFrame(std::shared_ptr<object::Node> node, std::shared_ptr<class MemoryFrame> next);

    std::shared_ptr<object::Node> node;
    std::shared_ptr<class MemoryFrame> next;

    std::string toString() const;
};

class ReturnFrame
{
public:
    ReturnFrame(const Location& location, class ReturnFrame* next);

    Location location;
    class ReturnFrame* next;

    std::string toString() const;
};

class TempFrame
{
public:
    TempFrame(std::shared_ptr<object::Node> node, class TempFrame* next);

    std::shared_ptr<object::Node> node;
    class TempFrame* next;

    std::string toString() const;
};

class Machine
{
public:
    Machine();

    Location location;

    TempFrame* temp;
    ReturnFrame* ret;
    std::shared_ptr<MemoryFrame> mem;

    std::string toString() const;

    bool step();
    void popTemp();
    object::Node* top() const;
};

class Underscore : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class Push : public Instruction
{
    std::shared_ptr<object::Node> node;

public:
    explicit Push(std::shared_ptr<object::Node> n);

    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class Pop : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

typedef
    std::function<object::Node*(object::Node* a, object::Node* b)>
    OperationFunction;

class Operation : public Instruction
{
    OperationFunction op;
    std::string name;

public:
    explicit Operation(const std::string& opName);
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class OperationAndAssign : public Instruction
{
    OperationFunction op;
    std::string name;

public:
    explicit OperationAndAssign(const std::string& opName);
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class Assign : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class Call : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class Negative : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class Negation : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class ConstructArray : public Instruction
{
    int size;

public:
    explicit ConstructArray(int size);
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class Begin : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class End : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class ConstructFunction : public Instruction
{
    std::shared_ptr<Procedure> procedure;

public:
    ConstructFunction(std::shared_ptr<Procedure> procedure);
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class StackFunction : public object::Function
{
public:
    StackFunction(
        Machine& machine,
        std::shared_ptr<Procedure> procedure,
        std::shared_ptr<MemoryFrame> memoryFrame);

    Machine& machine;
    std::shared_ptr<Procedure> procedure;
    std::shared_ptr<MemoryFrame> memoryFrame;

    virtual std::shared_ptr<object::Node> getMapping(std::shared_ptr<object::Node> key);
};

}

#endif
