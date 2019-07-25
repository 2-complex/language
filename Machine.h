
#include "INode.h"

#include <memory>
#include <vector>
#include <string>

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

    void add(Instruction* instruction);
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
    MemoryFrame(std::shared_ptr<INode> node, std::shared_ptr<class MemoryFrame> next);

    std::shared_ptr<INode> node;
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
    TempFrame(std::shared_ptr<INode> node, class TempFrame* next);

    std::shared_ptr<INode> node;
    class TempFrame* next;

    std::string toString() const;
};

class Machine
{
public:
    Machine();

    void start(const Location& staringLocation);
    void jump(std::shared_ptr<Procedure> procedure, std::shared_ptr<INode> node);

    bool step();
    void popTemp(size_t n);
    std::vector<std::shared_ptr<INode>> topTemp(size_t n) const;
    void pushTemp(std::shared_ptr<INode> node);

    std::string toString() const;

private:
    Location location;

    TempFrame* temp;
    ReturnFrame* ret;
    std::shared_ptr<MemoryFrame> mem;


};

}
