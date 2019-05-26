
#include "Environment.h"
#include "objects.h"

#include <stdio.h>


Environment::Environment(object::Object* argument)
{
    chain.push_back(argument);
}

Environment::Environment(Environment& parent, object::Object* argument)
    : chain(parent.chain)
{
    chain.push_back(argument);
}

Environment::Environment(const Environment& env)
    : chain(env.chain)
{
}

Environment::~Environment()
{
}

std::string Environment::toString() const
{
    std::string result = "";

    for( object::Node* c : chain )
        result += c->toString() + "/";

    return result;
}

object::Node* Environment::setMapping(object::Node* index, object::Node* value)
{
    return getArgument()->setMapping(index, value);
}

object::Object* Environment::getArgument() const
{
    return *(chain.rbegin());
}

object::Node* Environment::getMapping(object::Node* index)
{
    for( std::vector<object::Object*>::reverse_iterator itr = chain.rbegin(); itr != chain.rend(); ++itr )
    {
        object::Node* result = (*itr)->getMapping(index);
        if( result )
            return result;
    }

    return NULL;
}
