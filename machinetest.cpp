
#include "Instruction.h"

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

int main(int argc, char** args)
{
    test1();

    return 0;
}
