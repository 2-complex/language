#ifndef _Instruction_
#define _Instruction_

#include "INode.h"
#include "Machine.h"

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

class Underscore : public Instruction
{
public:
    virtual std::string toString() const;
    virtual void execute(Machine& machine);
};

class Push : public Instruction
{
    std::shared_ptr<INode> node;

public:
    explicit Push(std::shared_ptr<INode> n);

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
    std::function<INode*(INode* a, INode* b)>
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

class StackFunction : public INode
{
public:
    StackFunction(
        Machine& machine,
        std::shared_ptr<Procedure> procedure,
        std::shared_ptr<MemoryFrame> memoryFrame);

    Machine& machine;
    std::shared_ptr<Procedure> procedure;
    std::shared_ptr<MemoryFrame> memoryFrame;

    virtual std::shared_ptr<INode> getMapping(std::shared_ptr<INode> key);
};

}

#endif
