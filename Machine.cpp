
#include "Machine.h"

namespace instruction
{

Location::Location(std::shared_ptr<Procedure> procedure, size_t index)
    : procedure(procedure)
    , index(index)
{
}

std::string Location::toString() const
{
    return procedure->toString() + "(" + std::to_string(index) + ")";
}

Machine::Machine()
    : location(std::shared_ptr<Procedure>(new Procedure), -1)
    , temp(nullptr)
    , ret(nullptr)
    , mem(nullptr)
{
}

bool Machine::step()
{
    if( location.index < location.procedure->instructions.size() )
    {
        location.procedure->instructions[location.index]->execute(*this);
        ++location.index;
    }

    if( location.index < location.procedure->instructions.size() )
    {
        return true;
    }
    else
    {
        if( ret )
        {
            location = ret->location;
            ++location.index;
            ReturnFrame* b = ret;
            ret = ret->next;
            mem = mem->next;
            delete b;
            return true;
        }
    }

    return false;
}

void Machine::popTemp(size_t n)
{
    for (size_t i = 0; i < n; ++i)
    {
        TempFrame* b = temp;
        temp = temp->next;
        delete b;
    }
}

void Machine::pushTemp(std::shared_ptr<INode> node)
{
    temp = new TempFrame(node, temp);
}

std::vector<std::shared_ptr<INode>> Machine::topTemp(size_t n) const
{
    std::vector<std::shared_ptr<INode>> result;
    result.resize(n);

    TempFrame* t = temp;
    for (size_t i = 0; i < n; ++i)
    {
        result[n-1-i] = t->node;
        t = t->next;
    }
    return result;
}

void Machine::start(const Location& startingLocation)
{
    location = startingLocation;
}

void Machine::jump(std::shared_ptr<Procedure> procedure, std::shared_ptr<INode> node)
{
    ret = new ReturnFrame(location, ret);
    location = Location(procedure, -1);
    mem = std::shared_ptr<MemoryFrame>(new MemoryFrame(node, mem));
}

std::string Machine::toString() const
{
    std::string result = "";

    result += "temp:\n";

    for( TempFrame* f = temp; f; f=f->next )
    {
        result += std::string("    ") + f->toString() + "\n";
    }

    result += "memory:\n";

    for( std::shared_ptr<MemoryFrame> f = mem; f; f=f->next )
    {
        result += std::string("    ") + f->toString() + "\n";
    }

    result += "return:\n";

    for( ReturnFrame* f = ret; f; f=f->next )
    {
        result += std::string("    ") + f->toString() + "\n";
    }

    return result;
}

std::string Machine::toStringCompact() const
{
    std::string result = "";

    result += "t:";

    for( TempFrame* f = temp; f; f=f->next )
    {
        result += f->toString() + ",";
    }

    result += "m:";

    for( std::shared_ptr<MemoryFrame> f = mem; f; f=f->next )
    {
        result += f->toString() + ",";
    }

    result += "r:";

    for( ReturnFrame* f = ret; f; f=f->next )
    {
        result += f->toString() + ",";
    }

    return result;
}

MemoryFrame::MemoryFrame(
    std::shared_ptr<INode> node,
    std::shared_ptr<class MemoryFrame> next)
    : node(node)
    , next(next)
{
}

std::string MemoryFrame::toString() const
{
    return node->toString();
}

ReturnFrame::ReturnFrame(
    const Location& location,
    class ReturnFrame* next)
    : location(location)
    , next(next)
{
}

std::string ReturnFrame::toString() const
{
    return location.toString();
}

TempFrame::TempFrame(
    std::shared_ptr<INode> node,
    class TempFrame* next)
    : node(node)
    , next(next)
{
}

std::string TempFrame::toString() const
{
    return node->toString();
}

Instruction::Instruction()
{
}

Instruction::~Instruction()
{
}

Procedure::~Procedure()
{
    for( std::vector<instruction::Instruction*>::iterator itr = instructions.begin();
        itr != instructions.end();
        ++itr )
    {
        delete *itr;
    }
}

std::string Procedure::toString() const
{
    std::string result;

    for( std::vector<instruction::Instruction*>::const_iterator itr = instructions.begin();
        itr != instructions.end();
        ++itr )
    {
        result += (*itr)->toString();
    }

    return result;
}

void Procedure::add(Instruction* instruction)
{
    instructions.push_back(instruction);
}

}
