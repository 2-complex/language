
#include "Instruction.h"
#include "assert.h"

using namespace instruction;

class MyStringNode : public INode
{
public:
    MyStringNode(const std::string& s)
        : s(s)
    {
    }

    virtual std::string toString() const
    {
        return s;
    }

    std::string getS() const
    {
        return s;
    }

private:
    std::string s;
};

class MyAddInstruction : public Instruction
{
public:

    virtual std::string toString() const
    {
        return "add";
    }

    virtual void execute(Machine& machine)
    {
        std::vector<std::shared_ptr<INode>> v = machine.topTemp(2);
        MyStringNode* a = static_cast<MyStringNode*>(v[0].get());
        MyStringNode* b = static_cast<MyStringNode*>(v[1].get());

        MyStringNode* node = new MyStringNode(a->getS() + b->getS());

        machine.popTemp(2);
        machine.pushTemp(std::shared_ptr<INode>(node));
    }
};

class MyJumpInstruction : public Instruction
{
public:
    explicit MyJumpInstruction(std::shared_ptr<Procedure> procedure)
        : procedure(procedure)
    {
    }

    virtual std::string toString() const
    {
        return "Jump to: " + procedure->toString();
    }

    virtual void execute(Machine& machine)
    {
        machine.jump(procedure, std::shared_ptr<MyStringNode>(new MyStringNode("()")));
    }

private:
    std::shared_ptr<Procedure> procedure;
};

class MyPushInstruction : public Instruction
{
public:
    explicit MyPushInstruction(const std::string& s)
        : s(s)
    {
    }

    virtual std::string toString() const
    {
        return "MyAddInstruction";
    }

    virtual void execute(Machine& machine)
    {
        machine.pushTemp(std::shared_ptr<INode>(new MyStringNode(s)));
    }

private:
    std::string s;
};

void test1()
{
    Machine m;

    std::shared_ptr<Procedure> procedure(new Procedure);
    procedure->add(new MyPushInstruction("apple"));
    procedure->add(new MyPushInstruction("banana"));
    procedure->add(new MyAddInstruction);

    Location l(procedure, 0);
    m.start(l);

    m.step();
    printf("%s\n", m.toString().c_str());
    m.step();
    printf("%s\n", m.toString().c_str());
    m.step();
    printf("%s\n", m.toString().c_str());
}

void test2()
{
    Machine m;

    std::shared_ptr<Procedure> pushProcedure(new Procedure);
    pushProcedure->add(new MyPushInstruction("A"));
    pushProcedure->add(new MyPushInstruction("B"));

    std::shared_ptr<Procedure> addProcedure(new Procedure);
    addProcedure->add(new MyAddInstruction);

    pushProcedure->add(new MyJumpInstruction(addProcedure));
    pushProcedure->add(new MyPushInstruction("C"));

    Location l(pushProcedure, 0);
    m.start(l);

    while(m.step())
    {
        printf("%s\n", m.toString().c_str());
    }
    printf("%s\n", m.toString().c_str());
}

void test3()
{
    Machine m;

    std::shared_ptr<Procedure> emptyProcedure(new Procedure);

    std::shared_ptr<Procedure> pushProcedure(new Procedure);
    pushProcedure->add(new MyPushInstruction("A"));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyPushInstruction("B"));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));
    pushProcedure->add(new MyPushInstruction("C"));
    pushProcedure->add(new MyJumpInstruction(emptyProcedure));

    Location l(pushProcedure, 0);
    m.start(l);

    while(m.step())
    {
        printf("%s\n", m.toString().c_str());
    }
    printf("%s\n", m.toString().c_str());

    assert(m.toStringCompact() == "t:C,B,A,m:r:");
}


int main(int argc, char** args)
{
    test3();

    return 0;
}
