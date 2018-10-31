
#ifndef _Environment_
#define _Environment_

#include <string>
#include <vector>

namespace object
{
    class Node;
    class Object;
}

class Environment
{
    std::vector<object::Object*> chain;

public:
    explicit Environment(object::Object* argument);
    Environment(Environment& parent, object::Object* argument);
    Environment(const Environment& environment);

    virtual ~Environment();

    object::Object* getArgument() const;

    object::Node* setMapping(object::Node* index, object::Node* value);
    object::Node* getMapping(object::Node* index);

    std::string toString() const;
};

#endif
