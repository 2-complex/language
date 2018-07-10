
#include "Environment.h"
#include "objects.h"

#include <stdio.h>

Environment::Environment(object::Node* argument)
    : argument(argument)
{
    argument->retain();
}

Environment::~Environment()
{
    argument->release();
}

object::Node* Environment::setMapping(object::Node* index, object::Node* value)
{
    return argument->setMapping(index, value);
}

object::Node* Environment::getMapping(object::Node* index)
{
    return argument->getMapping(index);
}

object::Node* Environment::getArgument() const
{
    return argument;
}

std::string Environment::toString() const
{
    return argument->toString();
}

EnvironmentExtension::EnvironmentExtension(Environment& parent, object::Node* argument)
    : Environment(argument)
    , parent(parent)
{
}

EnvironmentExtension::~EnvironmentExtension()
{
}

std::string EnvironmentExtension::toString() const
{
    return getArgument()->toString() + "/" + parent.toString();
}

object::Node* EnvironmentExtension::getMapping(object::Node* index)
{
    object::Node* result = getArgument()->getMapping(index);

    if( ! result )
    {
        return parent.getMapping(index);
    }
    return result;
}
