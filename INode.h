#ifndef _INode_
#define _INode_

#include <string>

class INode
{
public:
    virtual std::string toString() const = 0;

/*
    virtual void setMapping(
        std::shared_ptr<INode> key,
        std::shared_ptr<INode> value) = 0;

    virtual std::shared_ptr<INode>
        getMapping(std::shared_ptr<INode> key) = 0;

    virtual bool isTrue() const = 0;
    virtual bool isError() const = 0;

    virtual INode* Negation() = 0;
    virtual INode* Negative() = 0;

    virtual INode* And(INode*) = 0;
    virtual INode* Or(INode*) = 0;
    virtual INode* Plus(INode*) = 0;
    virtual INode* Minus(INode*) = 0;
    virtual INode* Times(INode*) = 0;
    virtual INode* DividedBy(INode*) = 0;
    virtual INode* Mod(INode*) = 0;
    virtual INode* Equals(INode*) = 0;
    virtual INode* NotEquals(INode*) = 0;
    virtual INode* LessThan(INode*) = 0;
    virtual INode* GreaterThan(INode*) = 0;
    virtual INode* LessThanOrEqualTo(INode*) = 0;
    virtual INode* GreaterThanOrEqualTo(INode*) = 0;
*/
};

#endif
