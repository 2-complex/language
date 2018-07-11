
#ifndef _Environment_
#define _Environment_

#include <string>
#include <vector>

namespace object
{
    class Node;
}

class Environment
{
    std::vector<object::Node*> chain;

public:
    explicit Environment(object::Node* argument);
    Environment(Environment& parent, object::Node* argument);
    Environment(const Environment& environment);

    virtual ~Environment();

    object::Node* getArgument() const;
    object::Node* setMapping(object::Node* index, object::Node* value);

    object::Node* getMapping(object::Node* index);
    std::string toString() const;
};

#endif
