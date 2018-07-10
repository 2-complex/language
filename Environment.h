
#ifndef _Environment_
#define _Environment_

#include <string>

namespace object
{
    class Node;
}

class Environment
{
    object::Node* argument;

public:
    explicit Environment(object::Node* argument);
    virtual ~Environment();

    object::Node* getArgument() const;
    object::Node* setMapping(object::Node* index, object::Node* value);
    virtual object::Node* getMapping(object::Node* index);
    virtual std::string toString() const;
};

class EnvironmentExtension : public Environment
{
    Environment& parent;

public:
    EnvironmentExtension(Environment& parent, object::Node* argument);
    virtual ~EnvironmentExtension();

    virtual object::Node* getMapping(object::Node* index) override;
    virtual std::string toString() const;
};

#endif
