#include "objects.h"
#include "Code.h"

#include <math.h>

namespace object
{

Node::Node()
    : refCount(1)
{
}

Node::~Node()
{
}

void Node::retain()
{
    refCount++;
}

void Node::release()
{
    refCount--;

    if (refCount < 0)
    {
        printf( "something is wrong, there was a negative refcount\n" );
    }

    if (refCount == 0)
    {
        delete this;
    }
}

bool Node::isTrue()
{
    return false;
}

bool Node::isError() const
{
    return false;
}

std::string Node::mappingToString(Node* node) const
{
    return toString() + ":" + node->toString();
}

object::Node* Node::setMapping(object::Node* key, object::Node* value)
{
    return new Error("Attemt to set member "
        + key->toString()
        + " on non-object: "
        + toString());
}

object::Node* Node::getMapping(object::Node* key)
{
    return NULL;
}

std::string Error::toString() const
{
    return "ERROR: " + message;
}

Error::Error(const std::string& message)
    : message(message)
{
}

bool Error::isError() const
{
    return true;
}

Node* Error::Negation()
{
    retain();
    return this;
}

Node* Error::Negative()
{
    retain();
    return this;
}

Node* Error::And(Error* _)
{
    _->retain();
    return _;
}

Node* Error::And(Member* _)
{
    retain();
    return this;
}

Node* Error::And(Boolean* _)
{
    retain();
    return this;
}

Node* Error::And(Integer* _)
{
    retain();
    return this;
}

Node* Error::And(Double* _)
{
    retain();
    return this;
}

Node* Error::And(String* _)
{
    retain();
    return this;
}

Node* Error::And(Array* _)
{
    retain();
    return this;
}

Node* Error::And(Object* _)
{
    retain();
    return this;
}

Node* Error::And(Function* _)
{
    retain();
    return this;
}

std::string Member::getValue()
{
    return value;
}

Node* Member::And(Error* _)
{
    _->retain();
    return _;
}

Node* Member::And(Member* _)
{
    return new Error("Logical 'and' with member and member");
}

Node* Member::And(Boolean* _)
{
    return new Error("Logical 'and' with member and boolean");
}

Node* Member::And(Integer* _)
{
    return new Error("Logical 'and' with member and integer");
}

Node* Member::And(Double* _)
{
    return new Error("Logical 'and' with member and double");
}

Node* Member::And(String* _)
{
    return new Error("Logical 'and' with member and string");
}

Node* Member::And(Array* _)
{
    return new Error("Logical 'and' with member and array");
}

Node* Member::And(Object* _)
{
    return new Error("Logical 'and' with member and object");
}

Node* Member::And(Function* _)
{
    return new Error("Logical 'and' with member and function");
}

bool Boolean::getValue()
{
    return value;
}

std::string Boolean::toString() const
{
    return std::string(value ? "true" : "false");
}

Boolean::Boolean(bool value)
    : value(value)
{
}

Node* Boolean::Negation()
{
    return new Boolean(!value);
}

Node* Boolean::Negative()
{
    return new Error("Attempt to negate boolean with '-'");
}

Node* Boolean::And(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::And(Member* _)
{
    return new Error("Logical 'and' with boolean and member");
}

Node* Boolean::And(Boolean* _)
{
    return new Boolean(value && _->value);
}

Node* Boolean::And(Integer* _)
{
    return new Error("Logical 'and' with boolean and integer");
}

Node* Boolean::And(Double* _)
{
    return new Error("Logical 'and' with boolean and double");
}

Node* Boolean::And(String* _)
{
    return new Error("Logical 'and' with boolean and string");
}

Node* Boolean::And(Array* _)
{
    return new Error("Logical 'and' with boolean and array");
}

Node* Boolean::And(Object* _)
{
    return new Error("Logical 'and' with boolean and object");
}

Node* Boolean::And(Function* _)
{
    return new Error("Logical 'and' with boolean and function");
}

Integer::Integer(int value)
    : value(value)
{
}

Integer::Integer(const std::string& text)
{
    value = text;
}

BigInteger Integer::getValue()
{
    return value;
}

std::string Integer::toString() const
{
    return value.toString();
}

Node* Integer::Negation()
{
    return new Error("Attempt to negate integer with 'not'");
}

Node* Integer::Negative()
{
    return new Integer(-value);
}

Node* Integer::And(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::And(Member* _)
{
    return new Error("Logical 'and' with integer and member");
}

Node* Integer::And(Boolean* _)
{
    return new Error("Logical 'and' with integer and boolean");
}

Node* Integer::And(Integer* _)
{
    return new Error("Logical 'and' with integer and integer");
}

Node* Integer::And(Double* _)
{
    return new Error("Logical 'and' with integer and double");
}

Node* Integer::And(String* _)
{
    return new Error("Logical 'and' with integer and string");
}

Node* Integer::And(Array* _)
{
    return new Error("Logical 'and' with integer and array");
}

Node* Integer::And(Object* _)
{
    return new Error("Logical 'and' with integer and object");
}

Node* Integer::And(Function* _)
{
    return new Error("Logical 'and' with integer and function");
}

Double::Double(double value)
    : value(value)
{
}

Double::Double(const std::string& text)
{
    value = atof(text.c_str());
}

double Double::getValue() const
{
    return value;
}

std::string Double::toString() const
{
    return std::to_string(value);
}

Node* Double::Negation()
{
    return new Error("Attempt to negate double with 'not'");
}

Node* Double::Negative()
{
    return new Double(-value);
}

Node* Double::And(Error* _)
{
    _->retain();
    return _;
}

Node* Double::And(Member* _)
{
    return new Error("Logical 'and' with double and member");
}

Node* Double::And(Boolean* _)
{
    return new Error("Logical 'and' with double and boolean");
}

Node* Double::And(Integer* _)
{
    return new Error("Logical 'and' with double and integer");
}

Node* Double::And(Double* _)
{
    return new Error("Logical 'and' with double and double");
}

Node* Double::And(String* _)
{
    return new Error("Logical 'and' with double and string");
}

Node* Double::And(Array* _)
{
    return new Error("Logical 'and' with double and array");
}

Node* Double::And(Object* _)
{
    return new Error("Logical 'and' with double and object");
}

Node* Double::And(Function* _)
{
    return new Error("Logical 'and' with double and function");
}

String::String(const std::string& value)
    : value(value)
{
}

std::string String::toString() const
{
    return "\"" + value + "\"";
}

const std::string& String::getValue() const
{
    return value;
}

Node* String::Negation()
{
    return new Error("Attempt to negate string with 'not'");
}

Node* String::Negative()
{
    return new Error("Attempt to negate string with '-'");
}

Node* String::And(Error* _)
{
    _->retain();
    return _;
}

Node* String::And(Member* _)
{
    return new Error("Logical 'and' with string and member");
}

Node* String::And(Boolean* _)
{
    return new Error("Logical 'and' with string and boolean");
}

Node* String::And(Integer* _)
{
    return new Error("Logical 'and' with string and integer");
}

Node* String::And(Double* _)
{
    return new Error("Logical 'and' with string and double");
}

Node* String::And(String* _)
{
    return new Error("Logical 'and' with string and string");
}

Node* String::And(Array* _)
{
    return new Error("Logical 'and' with string and array");
}

Node* String::And(Object* _)
{
    return new Error("Logical 'and' with string and object");
}

Node* String::And(Function* _)
{
    return new Error("Logical 'and' with string and function");
}

const std::vector<Key>& Array::getValue()
{
    return value;
}

std::string Array::toString() const
{
    std::string result = "[";
    for( const Key& k : value )
    {
        result += k.node->toString() + ",";
    }
    result += "]";
    return result;
}

void Array::append(Node* node)
{
    value.push_back(node);
}

Node* Array::Negation()
{
    return new Error("Attempt to negate array with 'not'");
}

Node* Array::Negative()
{
    return new Error("Attempt to negate array with '-'");
}

Node* Array::And(Error* _)
{
    _->retain();
    return _;
}

Node* Array::And(Member* _)
{
    return new Error("Logical 'and' with array and member");
}

Node* Array::And(Boolean* _)
{
    return new Error("Logical 'and' with array and boolean");
}

Node* Array::And(Integer* _)
{
    return new Error("Logical 'and' with array and integer");
}

Node* Array::And(Double* _)
{
    return new Error("Logical 'and' with array and double");
}

Node* Array::And(String* _)
{
    return new Error("Logical 'and' with array and string");
}

Node* Array::And(Array* _)
{
    return new Error("Logical 'and' with array and array");
}

Node* Array::And(Object* _)
{
    return new Error("Logical 'and' with array and object");
}

Node* Array::And(Function* _)
{
    return new Error("Logical 'and' with array and function");
}

Key::Key()
    :node(NULL)
{
}

Key::Key(Node* node)
    : node(node)
{
}

bool Key::operator == (const class Key& other) const
{
    Node* temp = node->Equals(other.node);
    bool result = temp->isTrue();
    temp->release();
    return result;
}

bool Key::operator < (const class Key& other) const
{
    Node* temp = node->LessThan(other.node);
    bool result = temp->isTrue();
    temp->release();
    return result;
}

std::string Key::toString() const
{
    return node->toString();
}

Object::Object()
{
    underscore = this;
}

Object::Object(Node* underscore)
    : underscore(underscore)
{
    underscore->retain();
}

Object::~Object()
{
    if( underscore != this )
        underscore->release();

    for( auto itr = mappings.begin(); itr != mappings.end(); itr++ )
    {
        itr->second.node->release();
    }
}

std::map<Key, Key> Object::getValue()
{
    return mappings;
}

object::Node* Object::setMapping(Node* index, Node* value)
{
    Key key(index);

    if( index->isError() )
    {
        return index;
    }

    if( value->isError() )
    {
        return value;
    }

    auto itr = mappings.find(key);
    if (itr == mappings.end())
    {
        mappings[key] = value;
    }
    else
    {
        itr->second.node->release();
        itr->second = value;
    }

    return this;
}

Node* Object::getMapping(Node* index)
{
    Key key(index);
    auto itr = mappings.find(key);
    if( itr == mappings.end() )
    {
        return NULL;
    }

    itr->second.node->retain();
    return itr->second.node;
}

Node* Object::getUnderscore()
{
    return underscore;
}

std::string Object::toString() const
{
    std::string result = "(";

    for( auto itr = mappings.begin(); itr != mappings.end(); itr++ )
    {
        result += itr->first.node->mappingToString(itr->second.node);
        result += ",";
    }

    result += ")";

    return result;
}

Node* Object::Negation()
{
    return new Error("Attempt to negate object with 'not'");
}

Node* Object::Negative()
{
    return new Error("Attempt to negate object with '-'");
}

Node* Object::And(Error* _)
{
    _->retain();
    return _;
}

Node* Object::And(Member* _)
{
    return new Error("Logical 'and' with object and member");
}

Node* Object::And(Boolean* _)
{
    return new Error("Logical 'and' with object and boolean");
}

Node* Object::And(Integer* _)
{
    return new Error("Logical 'and' with object and integer");
}

Node* Object::And(Double* _)
{
    return new Error("Logical 'and' with object and double");
}

Node* Object::And(String* _)
{
    return new Error("Logical 'and' with object and string");
}

Node* Object::And(Array* _)
{
    return new Error("Logical 'and' with object and array");
}

Node* Object::And(Object* _)
{
    return new Error("Logical 'and' with object and object");
}

Node* Object::And(Function* _)
{
    return new Error("Logical 'and' with object and function");
}

Function::Function(
    Environment& environment,
    code::Program* program)
    : environment(environment)
    , program(program)
{
}

std::string Function::getValue()
{
    return toString();
}

code::Program* Function::getProgram() const
{
    return program;
}

std::string Function::toString() const
{
    return std::string("{") + program->toString() + std::string("}");
}

Node* Function::Negation()
{
    return new Error("Attempt to negate function with 'not'");
}

Node* Function::Negative()
{
    return new Error("Attempt to negate function with '-'");
}

Node* Function::And(Error* _)
{
    _->retain();
    return _;
}

Node* Function::And(Member* _)
{
    return new Error("Logical 'and' with function and member");
}

Node* Function::And(Boolean* _)
{
    return new Error("Logical 'and' with function and boolean");
}

Node* Function::And(Integer* _)
{
    return new Error("Logical 'and' with function and integer");
}

Node* Function::And(Double* _)
{
    return new Error("Logical 'and' with function and double");
}

Node* Function::And(String* _)
{
    return new Error("Logical 'and' with function and string");
}

Node* Function::And(Array* _)
{
    return new Error("Logical 'and' with function and array");
}

Node* Function::And(Object* _)
{
    return new Error("Logical 'and' with function and object");
}

Node* Function::And(Function* _)
{
    return new Error("Logical 'and' with function and function");
}

Node* Error::Or(Error* _)
{
    _->retain();
    return _;
}

Node* Error::Or(Member* _)
{
    retain();
    return this;
}

Node* Error::Or(Boolean* _)
{
    retain();
    return this;
}

Node* Error::Or(Integer* _)
{
    retain();
    return this;
}

Node* Error::Or(Double* _)
{
    retain();
    return this;
}

Node* Error::Or(String* _)
{
    retain();
    return this;
}

Node* Error::Or(Array* _)
{
    retain();
    return this;
}

Node* Error::Or(Object* _)
{
    retain();
    return this;
}

Node* Error::Or(Function* _)
{
    retain();
    return this;
}

Member::Member(const std::string& value)
    : value(value)
{
}

std::string Member::toString() const
{
    return "." + value;
}

std::string Member::mappingToString(Node* node) const
{
    return value + "=" + node->toString();
}

Node* Member::Negation()
{
    return new Error("Attempt to negate member with 'not'");
}

Node* Member::Negative()
{
    return new Error("Attempt to negate member with '-'");
}

Node* Member::Or(Error* _)
{
    _->retain();
    return _;
}

Node* Member::Or(Member* _)
{
    return new Error("Logical 'or' with member and member");
}

Node* Member::Or(Boolean* _)
{
    return new Error("Logical 'or' with member and boolean");
}

Node* Member::Or(Integer* _)
{
    return new Error("Logical 'or' with member and integer");
}

Node* Member::Or(Double* _)
{
    return new Error("Logical 'or' with member and double");
}

Node* Member::Or(String* _)
{
    return new Error("Logical 'or' with member and string");
}

Node* Member::Or(Array* _)
{
    return new Error("Logical 'or' with member and array");
}

Node* Member::Or(Object* _)
{
    return new Error("Logical 'or' with member and object");
}

Node* Member::Or(Function* _)
{
    return new Error("Logical 'or' with member and function");
}

bool Boolean::isTrue()
{
    return getValue();
}

Node* Boolean::Or(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::Or(Member* _)
{
    return new Error("Logical 'or' with boolean and member");
}

Node* Boolean::Or(Boolean* _)
{
    return new Boolean(value || _->value);
}

Node* Boolean::Or(Integer* _)
{
    return new Error("Logical 'or' with boolean and integer");
}

Node* Boolean::Or(Double* _)
{
    return new Error("Logical 'or' with boolean and double");
}

Node* Boolean::Or(String* _)
{
    return new Error("Logical 'or' with boolean and string");
}

Node* Boolean::Or(Array* _)
{
    return new Error("Logical 'or' with boolean and array");
}

Node* Boolean::Or(Object* _)
{
    return new Error("Logical 'or' with boolean and object");
}

Node* Boolean::Or(Function* _)
{
    return new Error("Logical 'or' with boolean and function");
}

Node* Integer::Or(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::Or(Member* _)
{
    return new Error("Logical 'or' with integer and member");
}

Node* Integer::Or(Boolean* _)
{
    return new Error("Logical 'or' with integer and boolean");
}

Node* Integer::Or(Integer* _)
{
    return new Error("Logical 'or' with integer and integer");
}

Node* Integer::Or(Double* _)
{
    return new Error("Logical 'or' with integer and double");
}

Node* Integer::Or(String* _)
{
    return new Error("Logical 'or' with integer and string");
}

Node* Integer::Or(Array* _)
{
    return new Error("Logical 'or' with integer and array");
}

Node* Integer::Or(Object* _)
{
    return new Error("Logical 'or' with integer and object");
}

Node* Integer::Or(Function* _)
{
    return new Error("Logical 'or' with integer and function");
}

Node* Double::Or(Error* _)
{
    _->retain();
    return _;
}

Node* Double::Or(Member* _)
{
    return new Error("Logical 'or' with double and member");
}

Node* Double::Or(Boolean* _)
{
    return new Error("Logical 'or' with double and boolean");
}

Node* Double::Or(Integer* _)
{
    return new Error("Logical 'or' with double and integer");
}

Node* Double::Or(Double* _)
{
    return new Error("Logical 'or' with double and double");
}

Node* Double::Or(String* _)
{
    return new Error("Logical 'or' with double and string");
}

Node* Double::Or(Array* _)
{
    return new Error("Logical 'or' with double and array");
}

Node* Double::Or(Object* _)
{
    return new Error("Logical 'or' with double and object");
}

Node* Double::Or(Function* _)
{
    return new Error("Logical 'or' with double and function");
}

Node* String::Or(Error* _)
{
    _->retain();
    return _;
}

Node* String::Or(Member* _)
{
    return new Error("Logical 'or' with string and member");
}

Node* String::Or(Boolean* _)
{
    return new Error("Logical 'or' with string and boolean");
}

Node* String::Or(Integer* _)
{
    return new Error("Logical 'or' with string and integer");
}

Node* String::Or(Double* _)
{
    return new Error("Logical 'or' with string and double");
}

Node* String::Or(String* _)
{
    return new Error("Logical 'or' with string and string");
}

Node* String::Or(Array* _)
{
    return new Error("Logical 'or' with string and array");
}

Node* String::Or(Object* _)
{
    return new Error("Logical 'or' with string and object");
}

Node* String::Or(Function* _)
{
    return new Error("Logical 'or' with string and function");
}

Node* Array::Or(Error* _)
{
    _->retain();
    return _;
}

Node* Array::Or(Member* _)
{
    return new Error("Logical 'or' with array and member");
}

Node* Array::Or(Boolean* _)
{
    return new Error("Logical 'or' with array and boolean");
}

Node* Array::Or(Integer* _)
{
    return new Error("Logical 'or' with array and integer");
}

Node* Array::Or(Double* _)
{
    return new Error("Logical 'or' with array and double");
}

Node* Array::Or(String* _)
{
    return new Error("Logical 'or' with array and string");
}

Node* Array::Or(Array* _)
{
    return new Error("Logical 'or' with array and array");
}

Node* Array::Or(Object* _)
{
    return new Error("Logical 'or' with array and object");
}

Node* Array::Or(Function* _)
{
    return new Error("Logical 'or' with array and function");
}

Node* Object::Or(Error* _)
{
    _->retain();
    return _;
}

Node* Object::Or(Member* _)
{
    return new Error("Logical 'or' with object and member");
}

Node* Object::Or(Boolean* _)
{
    return new Error("Logical 'or' with object and boolean");
}

Node* Object::Or(Integer* _)
{
    return new Error("Logical 'or' with object and integer");
}

Node* Object::Or(Double* _)
{
    return new Error("Logical 'or' with object and double");
}

Node* Object::Or(String* _)
{
    return new Error("Logical 'or' with object and string");
}

Node* Object::Or(Array* _)
{
    return new Error("Logical 'or' with object and array");
}

Node* Object::Or(Object* _)
{
    return new Error("Logical 'or' with object and object");
}

Node* Object::Or(Function* _)
{
    return new Error("Logical 'or' with object and function");
}

Node* Function::Or(Error* _)
{
    _->retain();
    return _;
}

Node* Function::Or(Member* _)
{
    return new Error("Logical 'or' with function and member");
}

Node* Function::Or(Boolean* _)
{
    return new Error("Logical 'or' with function and boolean");
}

Node* Function::Or(Integer* _)
{
    return new Error("Logical 'or' with function and integer");
}

Node* Function::Or(Double* _)
{
    return new Error("Logical 'or' with function and double");
}

Node* Function::Or(String* _)
{
    return new Error("Logical 'or' with function and string");
}

Node* Function::Or(Array* _)
{
    return new Error("Logical 'or' with function and array");
}

Node* Function::Or(Object* _)
{
    return new Error("Logical 'or' with function and object");
}

Node* Function::Or(Function* _)
{
    return new Error("Logical 'or' with function and function");
}

Node* Error::Impart(Error* _)
{
    retain();
    return this;
}

Node* Error::Impart(Member* _)
{
    retain();
    return this;
}

Node* Error::Impart(Boolean* _)
{
    retain();
    return this;
}

Node* Error::Impart(Integer* _)
{
    retain();
    return this;
}

Node* Error::Impart(Double* _)
{
    retain();
    return this;
}

Node* Error::Impart(String* _)
{
    retain();
    return this;
}

Node* Error::Impart(Array* _)
{
    retain();
    return this;
}

Node* Error::Impart(Object* _)
{
    retain();
    return this;
}

Node* Error::Impart(Function* _)
{
    retain();
    return this;
}

Node* Member::Impart(Error* _)
{
    _->retain();
    return _;
}

Node* Member::Impart(Member* _)
{
    return new Error("Attempt to impart member and member");
}

Node* Member::Impart(Boolean* _)
{
    return new Error("Attempt to impart member and boolean");
}

Node* Member::Impart(Integer* _)
{
    return new Error("Attempt to impart member and integer");
}

Node* Member::Impart(Double* _)
{
    return new Error("Attempt to impart member and double");
}

Node* Member::Impart(String* _)
{
    return new Error("Attempt to impart member and string");
}

Node* Member::Impart(Array* _)
{
    return new Error("Attempt to impart member and array");
}

Node* Member::Impart(Object* _)
{
    return new Error("Attempt to impart member and object");
}

Node* Member::Impart(Function* _)
{
    return new Error("Attempt to impart member and function");
}

Node* Boolean::Impart(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::Impart(Member* _)
{
    return new Error("Attempt to impart boolean and member");
}

Node* Boolean::Impart(Boolean* _)
{
    return new Error("Attempt to impart boolean and boolean");
}

Node* Boolean::Impart(Integer* _)
{
    return new Error("Attempt to impart boolean and integer");
}

Node* Boolean::Impart(Double* _)
{
    return new Error("Attempt to impart boolean and double");
}

Node* Boolean::Impart(String* _)
{
    return new Error("Attempt to impart boolean and string");
}

Node* Boolean::Impart(Array* _)
{
    return new Error("Attempt to impart boolean and array");
}

Node* Boolean::Impart(Object* _)
{
    return new Error("Attempt to impart boolean and object");
}

Node* Boolean::Impart(Function* _)
{
    return new Error("Attempt to impart boolean and function");
}

Node* Integer::Impart(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::Impart(Member* _)
{
    return new Error("Attempt to impart integer and member");
}

Node* Integer::Impart(Boolean* _)
{
    return new Error("Attempt to impart integer and boolean");
}

Node* Integer::Impart(Integer* _)
{
    return new Error("Attempt to impart integer and integer");
}

Node* Integer::Impart(Double* _)
{
    return new Error("Attempt to impart integer and double");
}

Node* Integer::Impart(String* _)
{
    return new Error("Attempt to impart integer and string");
}

Node* Integer::Impart(Array* _)
{
    return new Error("Attempt to impart integer and array");
}

Node* Integer::Impart(Object* _)
{
    return new Error("Attempt to impart integer and object");
}

Node* Integer::Impart(Function* _)
{
    return new Error("Attempt to impart integer and function");
}

Node* Double::Impart(Error* _)
{
    _->retain();
    return _;
}

Node* Double::Impart(Member* _)
{
    return new Error("Attempt to impart double and member");
}

Node* Double::Impart(Boolean* _)
{
    return new Error("Attempt to impart double and boolean");
}

Node* Double::Impart(Integer* _)
{
    return new Error("Attempt to impart double and integer");
}

Node* Double::Impart(Double* _)
{
    return new Error("Attempt to impart double and double");
}

Node* Double::Impart(String* _)
{
    return new Error("Attempt to impart double and string");
}

Node* Double::Impart(Array* _)
{
    return new Error("Attempt to impart double and array");
}

Node* Double::Impart(Object* _)
{
    return new Error("Attempt to impart double and object");
}

Node* Double::Impart(Function* _)
{
    return new Error("Attempt to impart double and function");
}

Node* String::Impart(Error* _)
{
    _->retain();
    return _;
}

Node* String::Impart(Member* _)
{
    return new Error("Attempt to impart string and member");
}

Node* String::Impart(Boolean* _)
{
    return new Error("Attempt to impart string and boolean");
}

Node* String::Impart(Integer* _)
{
    return new Error("Attempt to impart string and integer");
}

Node* String::Impart(Double* _)
{
    return new Error("Attempt to impart string and double");
}

Node* String::Impart(String* _)
{
    return new Error("Attempt to impart string and string");
}

Node* String::Impart(Array* _)
{
    return new Error("Attempt to impart string and array");
}

Node* String::Impart(Object* _)
{
    return new Error("Attempt to impart string and object");
}

Node* String::Impart(Function* _)
{
    return new Error("Attempt to impart string and function");
}

Node* Array::Impart(Error* _)
{
    _->retain();
    return _;
}

Node* Array::Impart(Member* _)
{
    return new Error("Attempt to impart array and member");
}

Node* Array::Impart(Boolean* _)
{
    return new Error("Attempt to impart array and boolean");
}

Node* Array::Impart(Integer* _)
{
    return new Error("Attempt to impart array and integer");
}

Node* Array::Impart(Double* _)
{
    return new Error("Attempt to impart array and double");
}

Node* Array::Impart(String* _)
{
    return new Error("Attempt to impart string and string");
}

Node* Array::Impart(Array* _)
{
    return new Error("Attempt to impart string and array");
}

Node* Array::Impart(Object* _)
{
    return new Error("Attempt to impart array and object");
}

Node* Array::Impart(Function* _)
{
    return new Error("Attempt to impart array and function");
}

Node* Object::Impart(Error* _)
{
    _->retain();
    return _;
}

Node* Object::Impart(Member* _)
{
    return new Error("Attempt to impart object and member");
}

Node* Object::Impart(Boolean* _)
{
    return new Error("Attempt to impart object and boolean");
}

Node* Object::Impart(Integer* _)
{
    return new Error("Attempt to impart object and integer");
}

Node* Object::Impart(Double* _)
{
    return new Error("Attempt to impart object and double");
}

Node* Object::Impart(String* _)
{
    return new Error("Attempt to impart object and string");
}

Node* Object::Impart(Array* _)
{
    return new Error("Attempt to impart object and array");
}

Node* Object::Impart(Object* _)
{
    return new Error("Attempt to impart object and object");
}

Node* Object::Impart(Function* function)
{
    Environment env(this);
    return new Function(env, function->getProgram());
}

Node* Function::Impart(Error* _)
{
    _->retain();
    return _;
}

Node* Function::Impart(Member* _)
{
    return new Error("Attempt to impart function and member");
}

Node* Function::Impart(Boolean* _)
{
    return new Error("Attempt to impart function and boolean");
}

Node* Function::Impart(Integer* _)
{
    return new Error("Attempt to impart function and integer");
}

Node* Function::Impart(Double* _)
{
    return new Error("Attempt to impart function and double");
}

Node* Function::Impart(String* _)
{
    return new Error("Attempt to impart string and string");
}

Node* Function::Impart(Array* _)
{
    return new Error("Attempt to impart function and array");
}

Node* Function::Impart(Object* _)
{
    return new Error("Attempt to impart function and object");
}

Node* Function::Impart(Function* _)
{
    return new Error("Attempt to impart function and function");
}

Node* Error::Plus(Error* _)
{
    retain();
    return this;
}

Node* Error::Plus(Member* _)
{
    retain();
    return this;
}

Node* Error::Plus(Boolean* _)
{
    retain();
    return this;
}

Node* Error::Plus(Integer* _)
{
    retain();
    return this;
}

Node* Error::Plus(Double* _)
{
    retain();
    return this;
}

Node* Error::Plus(String* _)
{
    retain();
    return this;
}

Node* Error::Plus(Array* _)
{
    retain();
    return this;
}

Node* Error::Plus(Object* _)
{
    retain();
    return this;
}

Node* Error::Plus(Function* _)
{
    retain();
    return this;
}

Node* Member::Plus(Error* _)
{
    _->retain();
    return _;
}

Node* Member::Plus(Member* _)
{
    return new Error("Attempt to add member and member with '+'");
}

Node* Member::Plus(Boolean* _)
{
    return new Error("Attempt to add member and boolean with '+'");
}

Node* Member::Plus(Integer* _)
{
    return new Error("Attempt to add member and integer with '+'");
}

Node* Member::Plus(Double* _)
{
    return new Error("Attempt to add member and double with '+'");
}

Node* Member::Plus(String* _)
{
    return new Error("Attempt to add member and string with '+'");
}

Node* Member::Plus(Array* _)
{
    return new Error("Attempt to add member and array with '+'");
}

Node* Member::Plus(Object* _)
{
    return new Error("Attempt to add member and object with '+'");
}

Node* Member::Plus(Function* _)
{
    return new Error("Attempt to add member and function with '+'");
}

Node* Boolean::Plus(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::Plus(Member* _)
{
    return new Error("Attempt to add boolean and member with '+'");
}

Node* Boolean::Plus(Boolean* _)
{
    return new Error("Attempt to add boolean and boolean with '+'");
}

Node* Boolean::Plus(Integer* _)
{
    return new Error("Attempt to add boolean and integer with '+'");
}

Node* Boolean::Plus(Double* _)
{
    return new Error("Attempt to add boolean and double with '+'");
}

Node* Boolean::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Boolean::Plus(Array* _)
{
    return new Error("Attempt to add boolean and array with '+'");
}

Node* Boolean::Plus(Object* _)
{
    return new Error("Attempt to add boolean and object with '+'");
}

Node* Boolean::Plus(Function* _)
{
    return new Error("Attempt to add boolean and function with '+'");
}

Node* Integer::Plus(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::Plus(Member* _)
{
    return new Error("Attempt to add integer and member with '+'");
}

Node* Integer::Plus(Boolean* _)
{
    return new Error("Attempt to add integer and boolean with '+'");
}

Node* Integer::Plus(Integer* _)
{
    return new Integer(value + _->value);
}

Node* Integer::Plus(Double* _)
{
    return new Double(value + _->getValue());
}

Node* Integer::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Integer::Plus(Array* _)
{
    return new Error("Attempt to add integer and array with '+'");
}

Node* Integer::Plus(Object* _)
{
    return new Error("Attempt to add integer and object with '+'");
}

Node* Integer::Plus(Function* _)
{
    return new Error("Attempt to add integer and function with '+'");
}

Node* Double::Plus(Error* _)
{
    _->retain();
    return _;
}

Node* Double::Plus(Member* _)
{
    return new Error("Attempt to add double and member with '+'");
}

Node* Double::Plus(Boolean* _)
{
    return new Error("Attempt to add double and boolean with '+'");
}

Node* Double::Plus(Integer* _)
{
    return new Double(value + _->getValue().toDouble());
}

Node* Double::Plus(Double* _)
{
    return new Double(value + _->value);
}

Node* Double::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Double::Plus(Array* _)
{
    return new Error("Attempt to add double and array with '+'");
}

Node* Double::Plus(Object* _)
{
    return new Error("Attempt to add double and object with '+'");
}

Node* Double::Plus(Function* _)
{
    return new Error("Attempt to add double and function with '+'");
}

Node* String::Plus(Error* _)
{
    _->retain();
    return _;
}

Node* String::Plus(Member* _)
{
    return new Error("Attempt to add string and member with '+'");
}

Node* String::Plus(Boolean* _)
{
    return new String(value + _->toString());
}

Node* String::Plus(Integer* _)
{
    return new String(value + _->toString());
}

Node* String::Plus(Double* _)
{
    return new String(value + _->toString());
}

Node* String::Plus(String* _)
{
    return new String(value + _->value);
}

Node* String::Plus(Array* _)
{
    return new String(value + _->toString());
}

Node* String::Plus(Object* _)
{
    return new String(value + _->toString());
}

Node* String::Plus(Function* _)
{
    return new String(value + _->toString());
}

Node* Array::Plus(Error* _)
{
    _->retain();
    return _;
}

Node* Array::Plus(Member* _)
{
    return new Error("Attempt to add array and member with '+'");
}

Node* Array::Plus(Boolean* _)
{
    return new Error("Attempt to add array and boolean with '+'");
}

Node* Array::Plus(Integer* _)
{
    return new Error("Attempt to add array and integer with '+'");
}

Node* Array::Plus(Double* _)
{
    return new Error("Attempt to add array and double with '+'");
}

Node* Array::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Array::Plus(Array* _)
{
    Array* array = new Array;

    for( Key& k : value )
        array->append(k.node);

    for( Key& k : _->value )
        array->append(k.node);

    return array;
}

Node* Array::Plus(Object* _)
{
    return new Error("Attempt to add array and object with '+'");
}

Node* Array::Plus(Function* _)
{
    return new Error("Attempt to add array and function with '+'");
}

Node* Object::Plus(Error* _)
{
    _->retain();
    return _;
}

Node* Object::Plus(Member* _)
{
    return new Error("Attempt to add object and member with '+'");
}

Node* Object::Plus(Boolean* _)
{
    return new Error("Attempt to add object and boolean with '+'");
}

Node* Object::Plus(Integer* _)
{
    return new Error("Attempt to add object and integer with '+'");
}

Node* Object::Plus(Double* _)
{
    return new Error("Attempt to add object and double with '+'");
}

Node* Object::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Object::Plus(Array* _)
{
    return new Error("Attempt to add object and array with '+'");
}

Node* Object::Plus(Object* _)
{
    return new Error("Attempt to add object and object with '+'");
}

Node* Object::Plus(Function* _)
{
    return new Error("Attempt to add object and function with '+'");
}

Node* Function::Plus(Error* _)
{
    _->retain();
    return _;
}

Node* Function::Plus(Member* _)
{
    return new Error("Attempt to add function and member with '+'");
}

Node* Function::Plus(Boolean* _)
{
    return new Error("Attempt to add function and boolean with '+'");
}

Node* Function::Plus(Integer* _)
{
    return new Error("Attempt to add function and integer with '+'");
}

Node* Function::Plus(Double* _)
{
    return new Error("Attempt to add function and double with '+'");
}

Node* Function::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Function::Plus(Array* _)
{
    return new Error("Attempt to add function and array with '+'");
}

Node* Function::Plus(Object* _)
{
    return new Error("Attempt to add function and object with '+'");
}

Node* Function::Plus(Function* _)
{
    return new Error("Attempt to add function and function with '+'");
}

Node* Error::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* Error::Minus(Member* _)
{
    retain();
    return this;
}

Node* Error::Minus(Boolean* _)
{
    retain();
    return this;
}

Node* Error::Minus(Integer* _)
{
    retain();
    return this;
}

Node* Error::Minus(Double* _)
{
    retain();
    return this;
}

Node* Error::Minus(String* _)
{
    retain();
    return this;
}

Node* Error::Minus(Array* _)
{
    retain();
    return this;
}

Node* Error::Minus(Object* _)
{
    retain();
    return this;
}

Node* Error::Minus(Function* _)
{
    retain();
    return this;
}

Node* Member::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* Member::Minus(Member* _)
{
    return new Error("Attempt to subtract member and member with '-'");
}

Node* Member::Minus(Boolean* _)
{
    return new Error("Attempt to subtract member and boolean with '-'");
}

Node* Member::Minus(Integer* _)
{
    return new Error("Attempt to subtract member and integer with '-'");
}

Node* Member::Minus(Double* _)
{
    return new Error("Attempt to subtract member and double with '-'");
}

Node* Member::Minus(String* _)
{
    return new Error("Attempt to subtract member and string with '-'");
}

Node* Member::Minus(Array* _)
{
    return new Error("Attempt to subtract member and array with '-'");
}

Node* Member::Minus(Object* _)
{
    return new Error("Attempt to subtract member and object with '-'");
}

Node* Member::Minus(Function* _)
{
    return new Error("Attempt to subtract member and function with '-'");
}

Node* Boolean::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::Minus(Member* _)
{
    return new Error("Attempt to subtract boolean and member with '-'");
}

Node* Boolean::Minus(Boolean* _)
{
    return new Error("Attempt to subtract boolean and boolean with '-'");
}

Node* Boolean::Minus(Integer* _)
{
    return new Error("Attempt to subtract boolean and integer with '-'");
}

Node* Boolean::Minus(Double* _)
{
    return new Error("Attempt to subtract boolean and double with '-'");
}

Node* Boolean::Minus(String* _)
{
    return new Error("Attempt to subtract boolean and string with '-'");
}

Node* Boolean::Minus(Array* _)
{
    return new Error("Attempt to subtract boolean and array with '-'");
}

Node* Boolean::Minus(Object* _)
{
    return new Error("Attempt to subtract boolean and object with '-'");
}

Node* Boolean::Minus(Function* _)
{
    return new Error("Attempt to subtract boolean and function with '-'");
}

Node* Integer::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::Minus(Member* _)
{
    return new Error("Attempt to subtract integer and member with '-'");
}

Node* Integer::Minus(Boolean* _)
{
    return new Error("Attempt to subtract integer and boolean with '-'");
}

Node* Integer::Minus(Integer* _)
{
    return new Integer(value - _->value);
}

Node* Integer::Minus(Double* _)
{
    return new Double(value - _->getValue());
}

Node* Integer::Minus(String* _)
{
    return new Error("Attempt to subtract integer and string with '-'");
}

Node* Integer::Minus(Array* _)
{
    return new Error("Attempt to subtract integer and array with '-'");
}

Node* Integer::Minus(Object* _)
{
    return new Error("Attempt to subtract integer and object with '-'");
}

Node* Integer::Minus(Function* _)
{
    return new Error("Attempt to subtract integer and function with '-'");
}

Node* Double::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* Double::Minus(Member* _)
{
    return new Error("Attempt to subtract double and member with '-'");
}

Node* Double::Minus(Boolean* _)
{
    return new Error("Attempt to subtract double and boolean with '-'");
}

Node* Double::Minus(Integer* _)
{
    return new Double(value - _->getValue().toDouble());
}

Node* Double::Minus(Double* _)
{
    return new Double(value - _->value);
}

Node* Double::Minus(String* _)
{
    return new Error("Attempt to subtract double and string with '-'");
}

Node* Double::Minus(Array* _)
{
    return new Error("Attempt to subtract double and array with '-'");
}

Node* Double::Minus(Object* _)
{
    return new Error("Attempt to subtract double and object with '-'");
}

Node* Double::Minus(Function* _)
{
    return new Error("Attempt to subtract double and function with '-'");
}

Node* String::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* String::Minus(Member* _)
{
    return new Error("Attempt to subtract string and member with '-'");
}

Node* String::Minus(Boolean* _)
{
    return new Error("Attempt to subtract string and boolean with '-'");
}

Node* String::Minus(Integer* _)
{
    return new Error("Attempt to subtract string and integer with '-'");
}

Node* String::Minus(Double* _)
{
    return new Error("Attempt to subtract string and double with '-'");
}

Node* String::Minus(String* _)
{
    return new Error("Attempt to subtract string and string with '-'");
}

Node* String::Minus(Array* _)
{
    return new Error("Attempt to subtract string and array with '-'");
}

Node* String::Minus(Object* _)
{
    return new Error("Attempt to subtract string and object with '-'");
}

Node* String::Minus(Function* _)
{
    return new Error("Attempt to subtract string and function with '-'");
}

Node* Array::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* Array::Minus(Member* _)
{
    return new Error("Attempt to subtract array and member with '-'");
}

Node* Array::Minus(Boolean* _)
{
    return new Error("Attempt to subtract array and boolean with '-'");
}

Node* Array::Minus(Integer* _)
{
    return new Error("Attempt to subtract array and integer with '-'");
}

Node* Array::Minus(Double* _)
{
    return new Error("Attempt to subtract array and double with '-'");
}

Node* Array::Minus(String* _)
{
    return new Error("Attempt to subtract array and string with '-'");
}

Node* Array::Minus(Array* _)
{
    return new Error("Attempt to subtract array and array with '-'");
}

Node* Array::Minus(Object* _)
{
    return new Error("Attempt to subtract array and object with '-'");
}

Node* Array::Minus(Function* _)
{
    return new Error("Attempt to subtract array and function with '-'");
}

Node* Object::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* Object::Minus(Member* _)
{
    return new Error("Attempt to subtract object and member with '-'");
}

Node* Object::Minus(Boolean* _)
{
    return new Error("Attempt to subtract object and boolean with '-'");
}

Node* Object::Minus(Integer* _)
{
    return new Error("Attempt to subtract object and integer with '-'");
}

Node* Object::Minus(Double* _)
{
    return new Error("Attempt to subtract object and double with '-'");
}

Node* Object::Minus(String* _)
{
    return new Error("Attempt to subtract object and string with '-'");
}

Node* Object::Minus(Array* _)
{
    return new Error("Attempt to subtract object and array with '-'");
}

Node* Object::Minus(Object* _)
{
    return new Error("Attempt to subtract object and object with '-'");
}

Node* Object::Minus(Function* _)
{
    return new Error("Attempt to subtract object and function with '-'");
}

Node* Function::Minus(Error* _)
{
    _->retain();
    return _;
}

Node* Function::Minus(Member* _)
{
    return new Error("Attempt to subtract function and member with '-'");
}

Node* Function::Minus(Boolean* _)
{
    return new Error("Attempt to subtract function and boolean with '-'");
}

Node* Function::Minus(Integer* _)
{
    return new Error("Attempt to subtract function and integer with '-'");
}

Node* Function::Minus(Double* _)
{
    return new Error("Attempt to subtract function and double with '-'");
}

Node* Function::Minus(String* _)
{
    return new Error("Attempt to subtract function and string with '-'");
}

Node* Function::Minus(Array* _)
{
    return new Error("Attempt to subtract function and array with '-'");
}

Node* Function::Minus(Object* _)
{
    return new Error("Attempt to subtract function and object with '-'");
}

Node* Function::Minus(Function* _)
{
    return new Error("Attempt to subtract function and function with '-'");
}

Node* Error::Times(Error* _)
{
    retain();
    return this;
}

Node* Error::Times(Member* _)
{
    retain();
    return this;
}

Node* Error::Times(Boolean* _)
{
    retain();
    return this;
}

Node* Error::Times(Integer* _)
{
    retain();
    return this;
}

Node* Error::Times(Double* _)
{
    retain();
    return this;
}

Node* Error::Times(String* _)
{
    retain();
    return this;
}

Node* Error::Times(Array* _)
{
    retain();
    return this;
}

Node* Error::Times(Object* _)
{
    retain();
    return this;
}

Node* Error::Times(Function* _)
{
    retain();
    return this;
}

Node* Member::Times(Error* _)
{
    _->retain();
    return _;
}

Node* Member::Times(Member* _)
{
    return new Error("Attempt to multiply member by member with '*'");
}

Node* Member::Times(Boolean* _)
{
    return new Error("Attempt to multiply member by boolean with '*'");
}

Node* Member::Times(Integer* _)
{
    return new Error("Attempt to multiply member by integer with '*'");
}

Node* Member::Times(Double* _)
{
    return new Error("Attempt to multiply member by double with '*'");
}

Node* Member::Times(String* _)
{
    return new Error("Attempt to multiply member by string with '*'");
}

Node* Member::Times(Array* _)
{
    return new Error("Attempt to multiply member by array with '*'");
}

Node* Member::Times(Object* _)
{
    return new Error("Attempt to multiply member by object with '*'");
}

Node* Member::Times(Function* _)
{
    return new Error("Attempt to multiply member by function with '*'");
}

Node* Boolean::Times(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::Times(Member* _)
{
    return new Error("Attempt to multiply boolean by member with '*'");
}

Node* Boolean::Times(Boolean* _)
{
    return new Error("Attempt to multiply boolean by boolean with '*'");
}

Node* Boolean::Times(Integer* _)
{
    return new Error("Attempt to multiply boolean by integer with '*'");
}

Node* Boolean::Times(Double* _)
{
    return new Error("Attempt to multiply boolean by double with '*'");
}

Node* Boolean::Times(String* _)
{
    return new Error("Attempt to multiply boolean by string with '*'");
}

Node* Boolean::Times(Array* _)
{
    return new Error("Attempt to multiply boolean by array with '*'");
}

Node* Boolean::Times(Object* _)
{
    return new Error("Attempt to multiply boolean by object with '*'");
}

Node* Boolean::Times(Function* _)
{
    return new Error("Attempt to multiply boolean by function with '*'");
}

Node* Integer::Times(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::Times(Member* _)
{
    return new Error("Attempt to multiply integer by member with '*'");
}

Node* Integer::Times(Boolean* _)
{
    return new Error("Attempt to multiply integer by boolean with '*'");
}

Node* Integer::Times(Integer* _)
{
    return new Integer(value * _->value);
}

Node* Integer::Times(Double* _)
{
    return new Error("Attempt to multiply integer by double with '*'");
}

Node* Integer::Times(String* _)
{
    return new Error("Attempt to multiply integer by string with '*'");
}

Node* Integer::Times(Array* _)
{
    return new Error("Attempt to multiply integer by array with '*'");
}

Node* Integer::Times(Object* _)
{
    return new Error("Attempt to multiply integer by object with '*'");
}

Node* Integer::Times(Function* _)
{
    return new Error("Attempt to multiply integer by function with '*'");
}

Node* Double::Times(Error* _)
{
    _->retain();
    return _;
}

Node* Double::Times(Member* _)
{
    return new Error("Attempt to multiply double by member with '*'");
}

Node* Double::Times(Boolean* _)
{
    return new Error("Attempt to multiply double by boolean with '*'");
}

Node* Double::Times(Integer* _)
{
    return new Double(getValue() * _->getValue().toDouble());
}

Node* Double::Times(Double* _)
{
    return new Double(getValue() * _->getValue());
}

Node* Double::Times(String* _)
{
    return new Error("Attempt to multiply double by string with '*'");
}

Node* Double::Times(Array* _)
{
    return new Error("Attempt to multiply double by array with '*'");
}

Node* Double::Times(Object* _)
{
    return new Error("Attempt to multiply double by object with '*'");
}

Node* Double::Times(Function* _)
{
    return new Error("Attempt to multiply double by function with '*'");
}

Node* String::Times(Error* _)
{
    _->retain();
    return _;
}

Node* String::Times(Member* _)
{
    return new Error("Attempt to multiply string by member with '*'");
}

Node* String::Times(Boolean* _)
{
    return new Error("Attempt to multiply string by boolean with '*'");
}

Node* String::Times(Integer* _)
{
    return new Error("Attempt to multiply string by integer with '*'");
}

Node* String::Times(Double* _)
{
    return new Error("Attempt to multiply string by double with '*'");
}

Node* String::Times(String* _)
{
    return new Error("Attempt to multiply string by string with '*'");
}

Node* String::Times(Array* _)
{
    return new Error("Attempt to multiply string by array with '*'");
}

Node* String::Times(Object* _)
{
    return new Error("Attempt to multiply string by object with '*'");
}

Node* String::Times(Function* _)
{
    return new Error("Attempt to multiply string by function with '*'");
}

Node* Array::Times(Error* _)
{
    _->retain();
    return _;
}

Node* Array::Times(Member* _)
{
    return new Error("Attempt to multiply array by member with '*'");
}

Node* Array::Times(Boolean* _)
{
    return new Error("Attempt to multiply array by boolean with '*'");
}

Node* Array::Times(Integer* _)
{
    return new Error("Attempt to multiply array by integer with '*'");
}

Node* Array::Times(Double* _)
{
    return new Error("Attempt to multiply array by double with '*'");
}

Node* Array::Times(String* _)
{
    return new Error("Attempt to multiply array by string with '*'");
}

Node* Array::Times(Array* _)
{
    return new Error("Attempt to multiply array by array with '*'");
}

Node* Array::Times(Object* _)
{
    return new Error("Attempt to multiply array by object with '*'");
}

Node* Array::Times(Function* _)
{
    return new Error("Attempt to multiply array by function with '*'");
}

Node* Object::Times(Error* _)
{
    _->retain();
    return _;
}

Node* Object::Times(Member* _)
{
    return new Error("Attempt to multiply object by member with '*'");
}

Node* Object::Times(Boolean* _)
{
    return new Error("Attempt to multiply object by boolean with '*'");
}

Node* Object::Times(Integer* _)
{
    return new Error("Attempt to multiply object by integer with '*'");
}

Node* Object::Times(Double* _)
{
    return new Error("Attempt to multiply object by double with '*'");
}

Node* Object::Times(String* _)
{
    return new Error("Attempt to multiply object by string with '*'");
}

Node* Object::Times(Array* _)
{
    return new Error("Attempt to multiply object by array with '*'");
}

Node* Object::Times(Object* _)
{
    return new Error("Attempt to multiply object by object with '*'");
}

Node* Object::Times(Function* _)
{
    return new Error("Attempt to multiply object by function with '*'");
}

Node* Function::Times(Error* _)
{
    _->retain();
    return _;
}

Node* Function::Times(Member* _)
{
    return new Error("Attempt to multiply function by member with '*'");
}

Node* Function::Times(Boolean* _)
{
    return new Error("Attempt to multiply function by boolean with '*'");
}

Node* Function::Times(Integer* _)
{
    return new Error("Attempt to multiply function by integer with '*'");
}

Node* Function::Times(Double* _)
{
    return new Error("Attempt to multiply function by double with '*'");
}

Node* Function::Times(String* _)
{
    return new Error("Attempt to multiply function by string with '*'");
}

Node* Function::Times(Array* _)
{
    return new Error("Attempt to multiply function by array with '*'");
}

Node* Function::Times(Object* _)
{
    return new Error("Attempt to multiply function by object with '*'");
}

Node* Function::Times(Function* _)
{
    return new Error("Attempt to multiply function by function with '*'");
}

Node* Error::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* Error::DividedBy(Member* _)
{
    retain();
    return this;
}

Node* Error::DividedBy(Boolean* _)
{
    retain();
    return this;
}

Node* Error::DividedBy(Integer* _)
{
    retain();
    return this;
}

Node* Error::DividedBy(Double* _)
{
    retain();
    return this;
}

Node* Error::DividedBy(String* _)
{
    retain();
    return this;
}

Node* Error::DividedBy(Array* _)
{
    retain();
    return this;
}

Node* Error::DividedBy(Object* _)
{
    retain();
    return this;
}

Node* Error::DividedBy(Function* _)
{
    retain();
    return this;
}

Node* Member::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* Member::DividedBy(Member* _)
{
    return new Error("Attempt to divide member by member with '/'");
}

Node* Member::DividedBy(Boolean* _)
{
    return new Error("Attempt to divide member by boolean with '/'");
}

Node* Member::DividedBy(Integer* _)
{
    return new Error("Attempt to divide member by integer with '/'");
}

Node* Member::DividedBy(Double* _)
{
    return new Error("Attempt to divide member by double with '/'");
}

Node* Member::DividedBy(String* _)
{
    return new Error("Attempt to divide member by string with '/'");
}

Node* Member::DividedBy(Array* _)
{
    return new Error("Attempt to divide member by array with '/'");
}

Node* Member::DividedBy(Object* _)
{
    return new Error("Attempt to divide member by object with '/'");
}

Node* Member::DividedBy(Function* _)
{
    return new Error("Attempt to divide member by function with '/'");
}

Node* Boolean::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::DividedBy(Member* _)
{
    return new Error("Attempt to divide boolean by member with '/'");
}

Node* Boolean::DividedBy(Boolean* _)
{
    return new Error("Attempt to divide boolean by boolean with '/'");
}

Node* Boolean::DividedBy(Integer* _)
{
    return new Error("Attempt to divide boolean by integer with '/'");
}

Node* Boolean::DividedBy(Double* _)
{
    return new Error("Attempt to divide boolean by double with '/'");
}

Node* Boolean::DividedBy(String* _)
{
    return new Error("Attempt to divide boolean by string with '/'");
}

Node* Boolean::DividedBy(Array* _)
{
    return new Error("Attempt to divide boolean by array with '/'");
}

Node* Boolean::DividedBy(Object* _)
{
    return new Error("Attempt to divide boolean by object with '/'");
}

Node* Boolean::DividedBy(Function* _)
{
    return new Error("Attempt to divide boolean by function with '/'");
}

Node* Integer::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::DividedBy(Member* _)
{
    return new Error("Attempt to divide integer by member with '/'");
}

Node* Integer::DividedBy(Boolean* _)
{
    return new Error("Attempt to divide integer by boolean with '/'");
}

Node* Integer::DividedBy(Integer* _)
{
    return new Integer(value / _->value);
}

Node* Integer::DividedBy(Double* _)
{
    return new Error("Attempt to divide integer by double with '/'");
}

Node* Integer::DividedBy(String* _)
{
    return new Error("Attempt to divide integer by string with '/'");
}

Node* Integer::DividedBy(Array* _)
{
    return new Error("Attempt to divide integer by array with '/'");
}

Node* Integer::DividedBy(Object* _)
{
    return new Error("Attempt to divide integer by object with '/'");
}

Node* Integer::DividedBy(Function* _)
{
    return new Error("Attempt to divide integer by function with '/'");
}

Node* Double::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* Double::DividedBy(Member* _)
{
    return new Error("Attempt to divide double by member with '/'");
}

Node* Double::DividedBy(Boolean* _)
{
    return new Error("Attempt to divide double by boolean with '/'");
}

Node* Double::DividedBy(Integer* _)
{
    return new Double(getValue() / _->getValue().toDouble());
}

Node* Double::DividedBy(Double* _)
{
    return new Double(getValue() / _->getValue());
}

Node* Double::DividedBy(String* _)
{
    return new Error("Attempt to divide double by string with '/'");
}

Node* Double::DividedBy(Array* _)
{
    return new Error("Attempt to divide double by array with '/'");
}

Node* Double::DividedBy(Object* _)
{
    return new Error("Attempt to divide double by object with '/'");
}

Node* Double::DividedBy(Function* _)
{
    return new Error("Attempt to divide double by function with '/'");
}

Node* String::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* String::DividedBy(Member* _)
{
    return new Error("Attempt to divide string by member with '/'");
}

Node* String::DividedBy(Boolean* _)
{
    return new Error("Attempt to divide string by boolean with '/'");
}

Node* String::DividedBy(Integer* _)
{
    return new Error("Attempt to divide string by integer with '/'");
}

Node* String::DividedBy(Double* _)
{
    return new Error("Attempt to divide string by double with '/'");
}

Node* String::DividedBy(String* _)
{
    return new Error("Attempt to divide string by string with '/'");
}

Node* String::DividedBy(Array* _)
{
    return new Error("Attempt to divide string by array with '/'");
}

Node* String::DividedBy(Object* _)
{
    return new Error("Attempt to divide string by object with '/'");
}

Node* String::DividedBy(Function* _)
{
    return new Error("Attempt to divide string by function with '/'");
}

Node* Array::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* Array::DividedBy(Member* _)
{
    return new Error("Attempt to divide array by member with '/'");
}

Node* Array::DividedBy(Boolean* _)
{
    return new Error("Attempt to divide array by boolean with '/'");
}

Node* Array::DividedBy(Integer* _)
{
    return new Error("Attempt to divide array by integer with '/'");
}

Node* Array::DividedBy(Double* _)
{
    return new Error("Attempt to divide array by double with '/'");
}

Node* Array::DividedBy(String* _)
{
    return new Error("Attempt to divide array by string with '/'");
}

Node* Array::DividedBy(Array* _)
{
    return new Error("Attempt to divide array by array with '/'");
}

Node* Array::DividedBy(Object* _)
{
    return new Error("Attempt to divide array by object with '/'");
}

Node* Array::DividedBy(Function* _)
{
    return new Error("Attempt to divide array by function with '/'");
}

Node* Object::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* Object::DividedBy(Member* _)
{
    return new Error("Attempt to divide object by member with '/'");
}

Node* Object::DividedBy(Boolean* _)
{
    return new Error("Attempt to divide object by boolean with '/'");
}

Node* Object::DividedBy(Integer* _)
{
    return new Error("Attempt to divide object by integer with '/'");
}

Node* Object::DividedBy(Double* _)
{
    return new Error("Attempt to divide object by double with '/'");
}

Node* Object::DividedBy(String* _)
{
    return new Error("Attempt to divide object by string with '/'");
}

Node* Object::DividedBy(Array* _)
{
    return new Error("Attempt to divide object by array with '/'");
}

Node* Object::DividedBy(Object* _)
{
    return new Error("Attempt to divide object by object with '/'");
}

Node* Object::DividedBy(Function* _)
{
    return new Error("Attempt to divide object by function with '/'");
}

Node* Function::DividedBy(Error* _)
{
    _->retain();
    return _;
}

Node* Function::DividedBy(Member* _)
{
    return new Error("Attempt to divide function by member with '/'");
}

Node* Function::DividedBy(Boolean* _)
{
    return new Error("Attempt to divide function by boolean with '/'");
}

Node* Function::DividedBy(Integer* _)
{
    return new Error("Attempt to divide function by integer with '/'");
}

Node* Function::DividedBy(Double* _)
{
    return new Error("Attempt to divide function by double with '/'");
}

Node* Function::DividedBy(String* _)
{
    return new Error("Attempt to divide function by string with '/'");
}

Node* Function::DividedBy(Array* _)
{
    return new Error("Attempt to divide function by array with '/'");
}

Node* Function::DividedBy(Object* _)
{
    return new Error("Attempt to divide function by object with '/'");
}

Node* Function::DividedBy(Function* _)
{
    return new Error("Attempt to divide function by function with '/'");
}

Node* Error::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* Error::Mod(Member* _)
{
    retain();
    return this;
}

Node* Error::Mod(Boolean* _)
{
    retain();
    return this;
}

Node* Error::Mod(Integer* _)
{
    retain();
    return this;
}

Node* Error::Mod(Double* _)
{
    retain();
    return this;
}

Node* Error::Mod(String* _)
{
    retain();
    return this;
}

Node* Error::Mod(Array* _)
{
    retain();
    return this;
}

Node* Error::Mod(Object* _)
{
    retain();
    return this;
}

Node* Error::Mod(Function* _)
{
    retain();
    return this;
}

Node* Member::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* Member::Mod(Member* _)
{
    return new Error("Attempt to mod member and member with '%'");
}

Node* Member::Mod(Boolean* _)
{
    return new Error("Attempt to mod member and boolean with '%'");
}

Node* Member::Mod(Integer* _)
{
    return new Error("Attempt to mod member and integer with '%'");
}

Node* Member::Mod(Double* _)
{
    return new Error("Attempt to mod member and double with '%'");
}

Node* Member::Mod(String* _)
{
    return new Error("Attempt to mod member and string with '%'");
}

Node* Member::Mod(Array* _)
{
    return new Error("Attempt to mod member and array with '%'");
}

Node* Member::Mod(Object* _)
{
    return new Error("Attempt to mod member and object with '%'");
}

Node* Member::Mod(Function* _)
{
    return new Error("Attempt to mod member and function with '%'");
}

Node* Boolean::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::Mod(Member* _)
{
    return new Error("Attempt to mod boolean and member with '%'");
}

Node* Boolean::Mod(Boolean* _)
{
    return new Error("Attempt to mod boolean and boolean with '%'");
}

Node* Boolean::Mod(Integer* _)
{
    return new Error("Attempt to mod boolean and integer with '%'");
}

Node* Boolean::Mod(Double* _)
{
    return new Error("Attempt to mod boolean and double with '%'");
}

Node* Boolean::Mod(String* _)
{
    return new Error("Attempt to mod boolean and string with '%'");
}

Node* Boolean::Mod(Array* _)
{
    return new Error("Attempt to mod boolean and array with '%'");
}

Node* Boolean::Mod(Object* _)
{
    return new Error("Attempt to mod boolean and object with '%'");
}

Node* Boolean::Mod(Function* _)
{
    return new Error("Attempt to mod boolean and function with '%'");
}

Node* Integer::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::Mod(Member* _)
{
    return new Error("Attempt to mod integer and member with '%'");
}

Node* Integer::Mod(Boolean* _)
{
    return new Error("Attempt to mod integer and boolean with '%'");
}

Node* Integer::Mod(Integer* _)
{
    return new Integer(value % _->value);
}

Node* Integer::Mod(Double* _)
{
    return new Double(fmod(value.toDouble(), _->getValue()));
}

Node* Integer::Mod(String* _)
{
    return new Error("Attempt to mod integer and string with '%'");
}

Node* Integer::Mod(Array* _)
{
    return new Error("Attempt to mod integer and array with '%'");
}

Node* Integer::Mod(Object* _)
{
    return new Error("Attempt to mod integer and object with '%'");
}

Node* Integer::Mod(Function* _)
{
    return new Error("Attempt to mod integer and function with '%'");
}

Node* Double::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* Double::Mod(Member* _)
{
    return new Error("Attempt to mod double and member with '%'");
}

Node* Double::Mod(Boolean* _)
{
    return new Error("Attempt to mod double and boolean with '%'");
}

Node* Double::Mod(Integer* _)
{
    return new Double(fmod(value, _->getValue().toDouble()));
}

Node* Double::Mod(Double* _)
{
    return new Double(fmod(value, _->value));
}

Node* Double::Mod(String* _)
{
    return new Error("Attempt to mod double and string with '%'");
}

Node* Double::Mod(Array* _)
{
    return new Error("Attempt to mod double and array with '%'");
}

Node* Double::Mod(Object* _)
{
    return new Error("Attempt to mod double and object with '%'");
}

Node* Double::Mod(Function* _)
{
    return new Error("Attempt to mod double and function with '%'");
}

Node* String::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* String::Mod(Member* _)
{
    return new Error("Attempt to mod string and member with '%'");
}

Node* String::Mod(Boolean* _)
{
    return new Error("Attempt to mod string and boolean with '%'");
}

Node* String::Mod(Integer* _)
{
    return new Error("Attempt to mod string and integer with '%'");
}

Node* String::Mod(Double* _)
{
    return new Error("Attempt to mod string and double with '%'");
}

Node* String::Mod(String* _)
{
    return new Error("Attempt to mod string and string with '%'");
}

Node* String::Mod(Array* _)
{
    return new Error("Attempt to mod string and array with '%'");
}

Node* String::Mod(Object* _)
{
    return new Error("Attempt to mod string and object with '%'");
}

Node* String::Mod(Function* _)
{
    return new Error("Attempt to mod string and function with '%'");
}

Node* Array::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* Array::Mod(Member* _)
{
    return new Error("Attempt to mod array and member with '%'");
}

Node* Array::Mod(Boolean* _)
{
    return new Error("Attempt to mod array and boolean with '%'");
}

Node* Array::Mod(Integer* _)
{
    return new Error("Attempt to mod array and integer with '%'");
}

Node* Array::Mod(Double* _)
{
    return new Error("Attempt to mod array and double with '%'");
}

Node* Array::Mod(String* _)
{
    return new Error("Attempt to mod array and string with '%'");
}

Node* Array::Mod(Array* _)
{
    return new Error("Attempt to mod array and array with '%'");
}

Node* Array::Mod(Object* _)
{
    return new Error("Attempt to mod array and object with '%'");
}

Node* Array::Mod(Function* _)
{
    return new Error("Attempt to mod array and function with '%'");
}

Node* Object::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* Object::Mod(Member* _)
{
    return new Error("Attempt to mod object and member with '%'");
}

Node* Object::Mod(Boolean* _)
{
    return new Error("Attempt to mod object and boolean with '%'");
}

Node* Object::Mod(Integer* _)
{
    return new Error("Attempt to mod object and integer with '%'");
}

Node* Object::Mod(Double* _)
{
    return new Error("Attempt to mod object and double with '%'");
}

Node* Object::Mod(String* _)
{
    return new Error("Attempt to mod object and string with '%'");
}

Node* Object::Mod(Array* _)
{
    return new Error("Attempt to mod object and array with '%'");
}

Node* Object::Mod(Object* _)
{
    return new Error("Attempt to mod object and object with '%'");
}

Node* Object::Mod(Function* _)
{
    return new Error("Attempt to mod object and function with '%'");
}

Node* Function::Mod(Error* _)
{
    _->retain();
    return _;
}

Node* Function::Mod(Member* _)
{
    return new Error("Attempt to mod function and member with '%'");
}

Node* Function::Mod(Boolean* _)
{
    return new Error("Attempt to mod function and boolean with '%'");
}

Node* Function::Mod(Integer* _)
{
    return new Error("Attempt to mod function and integer with '%'");
}

Node* Function::Mod(Double* _)
{
    return new Error("Attempt to mod function and double with '%'");
}

Node* Function::Mod(String* _)
{
    return new Error("Attempt to mod function and string with '%'");
}

Node* Function::Mod(Array* _)
{
    return new Error("Attempt to mod function and array with '%'");
}

Node* Function::Mod(Object* _)
{
    return new Error("Attempt to mod function and object with '%'");
}

Node* Function::Mod(Function* _)
{
    return new Error("Attempt to mod function and function with '%'");
}

Node* Error::Call(Error* _)
{
    _->retain();
    return _;
}

Node* Error::Call(Member* _)
{
    retain();
    return this;
}

Node* Error::Call(Boolean* _)
{
    retain();
    return this;
}

Node* Error::Call(Integer* _)
{
    retain();
    return this;
}

Node* Error::Call(Double* _)
{
    retain();
    return this;
}

Node* Error::Call(String* _)
{
    retain();
    return this;
}

Node* Error::Call(Array* _)
{
    retain();
    return this;
}

Node* Error::Call(Object* _)
{
    retain();
    return this;
}

Node* Error::Call(Function* _)
{
    retain();
    return this;
}

Node* Member::Call(Error* _)
{
    _->retain();
    return _;
}

Node* Member::Call(Member* _)
{
    return new Error("Attempt to call member with member as argument");
}

Node* Member::Call(Boolean* _)
{
    return new Error("Attempt to call member with boolean as argument");
}

Node* Member::Call(Integer* _)
{
    return new Error("Attempt to call member with integer as argument");
}

Node* Member::Call(Double* _)
{
    return new Error("Attempt to call member with double as argument");
}

Node* Member::Call(String* _)
{
    return new Error("Attempt to call member with string as argument");
}

Node* Member::Call(Array* _)
{
    return new Error("Attempt to call member with array as argument");
}

Node* Member::Call(Object* _)
{
    return new Error("Attempt to call member with object as argument");
}

Node* Member::Call(Function* _)
{
    return new Error("Attempt to call member with function as argument");
}

Node* Boolean::Call(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::Call(Member* _)
{
    return new Error("Attempt to call boolean with member as argument");
}

Node* Boolean::Call(Boolean* _)
{
    return new Error("Attempt to call boolean with boolean as argument");
}

Node* Boolean::Call(Integer* _)
{
    return new Error("Attempt to call boolean with integer as argument");
}

Node* Boolean::Call(Double* _)
{
    return new Error("Attempt to call boolean with double as argument");
}

Node* Boolean::Call(String* _)
{
    return new Error("Attempt to call boolean with string as argument");
}

Node* Boolean::Call(Array* _)
{
    return new Error("Attempt to call boolean with array as argument");
}

Node* Boolean::Call(Object* _)
{
    return new Error("Attempt to call boolean with object as argument");
}

Node* Boolean::Call(Function* _)
{
    return new Error("Attempt to call boolean with function as argument");
}

Node* Integer::Call(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::Call(Member* _)
{
    return new Error("Attempt to call integer with member as argument");
}

Node* Integer::Call(Boolean* _)
{
    return new Error("Attempt to call integer with boolean as argument");
}

Node* Integer::Call(Integer* _)
{
    return new Error("Attempt to call integer with integer as argument");
}

Node* Integer::Call(Double* _)
{
    return new Error("Attempt to call integer with double as argument");
}

Node* Integer::Call(String* _)
{
    return new Error("Attempt to call integer with string as argument");
}

Node* Integer::Call(Array* _)
{
    return new Error("Attempt to call integer with array as argument");
}

Node* Integer::Call(Object* _)
{
    return new Error("Attempt to call integer with object as argument");
}

Node* Integer::Call(Function* _)
{
    return new Error("Attempt to call integer with function as argument");
}

Node* Double::Call(Error* _)
{
    _->retain();
    return _;
}

Node* Double::Call(Member* _)
{
    return new Error("Attempt to call double with member as argument");
}

Node* Double::Call(Boolean* _)
{
    return new Error("Attempt to call double with boolean as argument");
}

Node* Double::Call(Integer* _)
{
    return new Error("Attempt to call double with integer as argument");
}

Node* Double::Call(Double* _)
{
    return new Error("Attempt to call double with double as argument");
}

Node* Double::Call(String* _)
{
    return new Error("Attempt to call double with string as argument");
}

Node* Double::Call(Array* _)
{
    return new Error("Attempt to call double with array as argument");
}

Node* Double::Call(Object* _)
{
    return new Error("Attempt to call double with object as argument");
}

Node* Double::Call(Function* _)
{
    return new Error("Attempt to call double with function as argument");
}

Node* String::Call(Error* _)
{
    _->retain();
    return _;
}

Node* String::Call(Member* _)
{
    return new Error("Attempt to call string with member as argument");
}

Node* String::Call(Boolean* _)
{
    return new Error("Attempt to call string with boolean as argument");
}

Node* String::Call(Integer* _)
{
    if( _->getValue() < 0 || _->getValue() >= getValue().size() )
        return new Error("String index out of range");

    return new String(getValue().substr(_->getValue().toSizeT(),1));
}

Node* String::Call(Double* _)
{
    return new Error("Attempt to call string with double as argument");
}

Node* String::Call(String* _)
{
    return new Error("Attempt to call string with string as argument");
}

Node* String::Call(Array* _)
{
    return new Error("Attempt to call string with array as argument");
}

Node* String::Call(Object* _)
{
    return new Error("Attempt to call string with object as argument");
}

Node* String::Call(Function* _)
{
    return new Error("Attempt to call string with function as argument");
}

Node* Array::Call(Error* _)
{
    _->retain();
    return _;
}

Node* Array::Call(Member* _)
{
    return new Error("Attempt to call array with member as argument");
}

Node* Array::Call(Boolean* _)
{
    return new Error("Attempt to call array with boolean as argument");
}

Node* Array::Call(Integer* _)
{
    if( _->getValue() < 0 || _->getValue() >= value.size() )
        return new Error("Array index out of bounds");

    return value[_->getValue().toSizeT()].node;
}

Node* Array::Call(Double* _)
{
    return new Error("Attempt to call array with double as argument");
}

Node* Array::Call(String* _)
{
    return new Error("Attempt to call array with string as argument");
}

Node* Array::Call(Array* _)
{
    return new Error("Attempt to call array with array as argument");
}

Node* Array::Call(Object* _)
{
    return new Error("Attempt to call array with object as argument");
}

Node* Array::Call(Function* _)
{
    Array* array = new Array;

    for( Key& k : value )
        array->append(_->Call(k.node));

    return array;
}

Node* Object::Call(Error* _)
{
    _->retain();
    return _;
}

Node* Object::Call(Member* _)
{
    Node* result = getMapping(_);
    if( ! result )
    {
        return new Error("Attempt to access non-existant member " + _->getValue());
    }
    return result;
}

Node* Object::Call(Boolean* _)
{
    Node* result = getMapping(_);
    if( ! result )
    {
        return new Object;
    }
    return result;
}

Node* Object::Call(Integer* _)
{
    Node* result = getMapping(_);
    if( ! result )
    {
        return new Object;
    }
    return result;
}

Node* Object::Call(Double* _)
{
    Node* result = getMapping(_);
    if( ! result )
    {
        return new Object;
    }
    return result;
}

Node* Object::Call(String* _)
{
    Node* result = getMapping(_);
    if( ! result )
    {
        return new Object;
    }
    return result;
}

Node* Object::Call(Array* _)
{
    Node* result = getMapping(_);
    if( ! result )
    {
        return new Object;
    }
    return result;
}

Node* Object::Call(Object* _)
{
    Node* result = getMapping(_);
    if( ! result )
    {
        return new Object;
    }
    return result;
}

Node* Object::Call(Function* _)
{
    Node* result = getMapping(_);
    if( ! result )
    {
        return new Object;
    }
    return result;
}

Node* Function::Call(Error* _)
{
    _->retain();
    return _;
}

Node* Function::Call(Member* _)
{
    Environment extension(environment, new Object(_));
    return program->evaluate(extension);
}

Node* Function::Call(Boolean* _)
{
    Environment extension(environment, new Object(_));
    return program->evaluate(extension);
}

Node* Function::Call(Integer* _)
{
    Environment extension(environment, new Object(_));
    return program->evaluate(extension);
}

Node* Function::Call(Double* _)
{
    Environment extension(environment, new Object(_));
    return program->evaluate(extension);
}

Node* Function::Call(String* _)
{
    Environment extension(environment, new Object(_));
    return program->evaluate(extension);
}

Node* Function::Call(Array* _)
{
    Environment extension(environment, new Object(_));
    return program->evaluate(extension);
}

Node* Function::Call(Object* _)
{
    Environment extension(environment, _);
    return program->evaluate(extension);
}

Node* Function::Call(Function* _)
{
    Environment extension(environment, new Object(_));
    return program->evaluate(extension);
}

Node* Error::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* Error::Equals(Member* _)
{
    retain();
    return this;
}

Node* Error::Equals(Boolean* _)
{
    retain();
    return this;
}

Node* Error::Equals(Integer* _)
{
    retain();
    return this;
}

Node* Error::Equals(Double* _)
{
    retain();
    return this;
}

Node* Error::Equals(String* _)
{
    retain();
    return this;
}

Node* Error::Equals(Array* _)
{
    retain();
    return this;
}

Node* Error::Equals(Object* _)
{
    retain();
    return this;
}

Node* Error::Equals(Function* _)
{
    retain();
    return this;
}

Node* Member::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* Member::Equals(Member* _)
{
    return new Boolean( getValue() == _->getValue() );
}

Node* Member::Equals(Boolean* _)
{
    return new Boolean(true);
}

Node* Member::Equals(Integer* _)
{
    return new Boolean(true);
}

Node* Member::Equals(Double* _)
{
    return new Boolean(true);
}

Node* Member::Equals(String* _)
{
    return new Boolean(true);
}

Node* Member::Equals(Array* _)
{
    return new Boolean(true);
}

Node* Member::Equals(Object* _)
{
    return new Boolean(true);
}

Node* Member::Equals(Function* _)
{
    return new Boolean(true);
}

Node* Boolean::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::Equals(Member* _)
{
    return new Boolean(false);
}

Node* Boolean::Equals(Boolean* _)
{
    return new Boolean(getValue() == _->getValue());
}

Node* Boolean::Equals(Integer* _)
{
    return new Boolean(false);
}

Node* Boolean::Equals(Double* _)
{
    return new Boolean(false);
}

Node* Boolean::Equals(String* _)
{
    return new Boolean(false);
}

Node* Boolean::Equals(Array* _)
{
    return new Boolean(false);
}

Node* Boolean::Equals(Object* _)
{
    return new Boolean(false);
}

Node* Boolean::Equals(Function* _)
{
    return new Boolean(false);
}

Node* Integer::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::Equals(Member* _)
{
    return new Boolean(false);
}

Node* Integer::Equals(Boolean* _)
{
    return new Boolean(false);
}

Node* Integer::Equals(Integer* _)
{
    return new Boolean(getValue() == _->getValue());
}

Node* Integer::Equals(Double* _)
{
    return new Boolean(getValue() == _->getValue());
}

Node* Integer::Equals(String* _)
{
    return new Boolean(false);
}

Node* Integer::Equals(Array* _)
{
    return new Boolean(false);
}

Node* Integer::Equals(Object* _)
{
    return new Boolean(false);
}

Node* Integer::Equals(Function* _)
{
    return new Boolean(false);
}

Node* Double::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* Double::Equals(Member* _)
{
    return new Boolean(false);
}

Node* Double::Equals(Boolean* _)
{
    return new Boolean(false);
}

Node* Double::Equals(Integer* _)
{
    return new Boolean(getValue() == _->getValue().toDouble());
}

Node* Double::Equals(Double* _)
{
    return new Boolean(getValue() == _->getValue());
}

Node* Double::Equals(String* _)
{
    return new Boolean(false);
}

Node* Double::Equals(Array* _)
{
    return new Boolean(false);
}

Node* Double::Equals(Object* _)
{
    return new Boolean(false);
}

Node* Double::Equals(Function* _)
{
    return new Boolean(false);
}

Node* String::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* String::Equals(Member* _)
{
    return new Boolean(false);
}

Node* String::Equals(Boolean* _)
{
    return new Boolean(false);
}

Node* String::Equals(Integer* _)
{
    return new Boolean(false);
}

Node* String::Equals(Double* _)
{
    return new Boolean(false);
}

Node* String::Equals(String* _)
{
    return new Boolean(getValue() == _->getValue());
}

Node* String::Equals(Array* _)
{
    return new Boolean(false);
}

Node* String::Equals(Object* _)
{
    return new Boolean(false);
}

Node* String::Equals(Function* _)
{
    return new Boolean(false);
}

Node* Array::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* Array::Equals(Member* _)
{
    return new Boolean(false);
}

Node* Array::Equals(Boolean* _)
{
    return new Boolean(false);
}

Node* Array::Equals(Integer* _)
{
    return new Boolean(false);
}

Node* Array::Equals(Double* _)
{
    return new Boolean(false);
}

Node* Array::Equals(String* _)
{
    return new Boolean(false);
}

Node* Array::Equals(Array* _)
{
    return new Boolean(getValue() == _->getValue());
}

Node* Array::Equals(Object* _)
{
    return new Boolean(false);
}

Node* Array::Equals(Function* _)
{
    return new Boolean(false);
}

Node* Object::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* Object::Equals(Member* _)
{
    return new Boolean(false);
}

Node* Object::Equals(Boolean* _)
{
    return new Boolean(false);
}

Node* Object::Equals(Integer* _)
{
    return new Boolean(false);
}

Node* Object::Equals(Double* _)
{
    return new Boolean(false);
}

Node* Object::Equals(String* _)
{
    return new Boolean(false);
}

Node* Object::Equals(Array* _)
{
    return new Boolean(false);
}

Node* Object::Equals(Object* _)
{
    return new Boolean(getValue() == _->getValue());
}

Node* Object::Equals(Function* _)
{
    return new Boolean(false);
}

Node* Function::Equals(Error* _)
{
    _->retain();
    return _;
}

Node* Function::Equals(Member* _)
{
    return new Boolean(false);
}

Node* Function::Equals(Boolean* _)
{
    return new Boolean(false);
}

Node* Function::Equals(Integer* _)
{
    return new Boolean(false);
}

Node* Function::Equals(Double* _)
{
    return new Boolean(false);
}

Node* Function::Equals(String* _)
{
    return new Boolean(false);
}

Node* Function::Equals(Array* _)
{
    return new Boolean(false);
}

Node* Function::Equals(Object* _)
{
    return new Boolean(false);
}

Node* Function::Equals(Function* _)
{
    return new Boolean(getValue() == _->getValue());
}

Node* Error::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* Error::NotEquals(Member* _)
{
    retain();
    return this;
}

Node* Error::NotEquals(Boolean* _)
{
    retain();
    return this;
}

Node* Error::NotEquals(Integer* _)
{
    retain();
    return this;
}

Node* Error::NotEquals(Double* _)
{
    retain();
    return this;
}

Node* Error::NotEquals(String* _)
{
    retain();
    return this;
}

Node* Error::NotEquals(Array* _)
{
    retain();
    return this;
}

Node* Error::NotEquals(Object* _)
{
    retain();
    return this;
}

Node* Error::NotEquals(Function* _)
{
    retain();
    return this;
}

Node* Member::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* Member::NotEquals(Member* _)
{
    return new Boolean( getValue() != _->getValue() );
}

Node* Member::NotEquals(Boolean* _)
{
    return new Boolean(true);
}

Node* Member::NotEquals(Integer* _)
{
    return new Boolean(true);
}

Node* Member::NotEquals(Double* _)
{
    return new Boolean(true);
}

Node* Member::NotEquals(String* _)
{
    return new Boolean(true);
}

Node* Member::NotEquals(Array* _)
{
    return new Boolean(true);
}

Node* Member::NotEquals(Object* _)
{
    return new Boolean(true);
}

Node* Member::NotEquals(Function* _)
{
    return new Boolean(true);
}

Node* Boolean::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::NotEquals(Member* _)
{
    return new Boolean(false);
}

Node* Boolean::NotEquals(Boolean* _)
{
    return new Boolean(getValue() != _->getValue());
}

Node* Boolean::NotEquals(Integer* _)
{
    return new Boolean(true);
}

Node* Boolean::NotEquals(Double* _)
{
    return new Boolean(true);
}

Node* Boolean::NotEquals(String* _)
{
    return new Boolean(true);
}

Node* Boolean::NotEquals(Array* _)
{
    return new Boolean(true);
}

Node* Boolean::NotEquals(Object* _)
{
    return new Boolean(true);
}

Node* Boolean::NotEquals(Function* _)
{
    return new Boolean(true);
}

Node* Integer::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::NotEquals(Member* _)
{
    return new Boolean(false);
}

Node* Integer::NotEquals(Boolean* _)
{
    return new Boolean(true);
}

Node* Integer::NotEquals(Integer* _)
{
    return new Boolean(getValue() != _->getValue());
}

Node* Integer::NotEquals(Double* _)
{
    return new Boolean(getValue() != _->getValue());
}

Node* Integer::NotEquals(String* _)
{
    return new Boolean(true);
}

Node* Integer::NotEquals(Array* _)
{
    return new Boolean(true);
}

Node* Integer::NotEquals(Object* _)
{
    return new Boolean(true);
}

Node* Integer::NotEquals(Function* _)
{
    return new Boolean(true);
}

Node* Double::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* Double::NotEquals(Member* _)
{
    return new Boolean(false);
}

Node* Double::NotEquals(Boolean* _)
{
    return new Boolean(true);
}

Node* Double::NotEquals(Integer* _)
{
    return new Boolean(getValue() != _->getValue().toDouble());
}

Node* Double::NotEquals(Double* _)
{
    return new Boolean(getValue() != _->getValue());
}

Node* Double::NotEquals(String* _)
{
    return new Boolean(true);
}

Node* Double::NotEquals(Array* _)
{
    return new Boolean(true);
}

Node* Double::NotEquals(Object* _)
{
    return new Boolean(true);
}

Node* Double::NotEquals(Function* _)
{
    return new Boolean(true);
}

Node* String::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* String::NotEquals(Member* _)
{
    return new Boolean(false);
}

Node* String::NotEquals(Boolean* _)
{
    return new Boolean(true);
}

Node* String::NotEquals(Integer* _)
{
    return new Boolean(true);
}

Node* String::NotEquals(Double* _)
{
    return new Boolean(true);
}

Node* String::NotEquals(String* _)
{
    return new Boolean(getValue() != _->getValue());
}

Node* String::NotEquals(Array* _)
{
    return new Boolean(true);
}

Node* String::NotEquals(Object* _)
{
    return new Boolean(true);
}

Node* String::NotEquals(Function* _)
{
    return new Boolean(true);
}

Node* Array::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* Array::NotEquals(Member* _)
{
    return new Boolean(false);
}

Node* Array::NotEquals(Boolean* _)
{
    return new Boolean(true);
}

Node* Array::NotEquals(Integer* _)
{
    return new Boolean(true);
}

Node* Array::NotEquals(Double* _)
{
    return new Boolean(true);
}

Node* Array::NotEquals(String* _)
{
    return new Boolean(true);
}

Node* Array::NotEquals(Array* _)
{
    return new Boolean(getValue() != _->getValue());
}

Node* Array::NotEquals(Object* _)
{
    return new Boolean(true);
}

Node* Array::NotEquals(Function* _)
{
    return new Boolean(true);
}

Node* Object::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* Object::NotEquals(Member* _)
{
    return new Boolean(false);
}

Node* Object::NotEquals(Boolean* _)
{
    return new Boolean(true);
}

Node* Object::NotEquals(Integer* _)
{
    return new Boolean(true);
}

Node* Object::NotEquals(Double* _)
{
    return new Boolean(true);
}

Node* Object::NotEquals(String* _)
{
    return new Boolean(true);
}

Node* Object::NotEquals(Array* _)
{
    return new Boolean(true);
}

Node* Object::NotEquals(Object* _)
{
    return new Boolean(getValue() != _->getValue());
}

Node* Object::NotEquals(Function* _)
{
    return new Boolean(true);
}

Node* Function::NotEquals(Error* _)
{
    _->retain();
    return _;
}

Node* Function::NotEquals(Member* _)
{
    return new Boolean(false);
}

Node* Function::NotEquals(Boolean* _)
{
    return new Boolean(true);
}

Node* Function::NotEquals(Integer* _)
{
    return new Boolean(true);
}

Node* Function::NotEquals(Double* _)
{
    return new Boolean(true);
}

Node* Function::NotEquals(String* _)
{
    return new Boolean(true);
}

Node* Function::NotEquals(Array* _)
{
    return new Boolean(true);
}

Node* Function::NotEquals(Object* _)
{
    return new Boolean(true);
}

Node* Function::NotEquals(Function* _)
{
    return new Boolean(getValue() != _->getValue());
}

Node* Error::LessThan(Error* _)
{
    retain();
    return this;
}

Node* Error::LessThan(Member* _)
{
    retain();
    return this;
}

Node* Error::LessThan(Boolean* _)
{
    retain();
    return this;
}

Node* Error::LessThan(Integer* _)
{
    retain();
    return this;
}

Node* Error::LessThan(Double* _)
{
    retain();
    return this;
}

Node* Error::LessThan(String* _)
{
    retain();
    return this;
}

Node* Error::LessThan(Array* _)
{
    retain();
    return this;
}

Node* Error::LessThan(Object* _)
{
    retain();
    return this;
}

Node* Error::LessThan(Function* _)
{
    retain();
    return this;
}

Node* Member::LessThan(Error* _)
{
    _->retain();
    return _;
}

Node* Member::LessThan(Member* _)
{
    return new Boolean( getValue() < _->getValue() );
}

Node* Member::LessThan(Boolean* _)
{
    return new Boolean(true);
}

Node* Member::LessThan(Integer* _)
{
    return new Boolean(true);
}

Node* Member::LessThan(Double* _)
{
    return new Boolean(true);
}

Node* Member::LessThan(String* _)
{
    return new Boolean(true);
}

Node* Member::LessThan(Array* _)
{
    return new Boolean(true);
}

Node* Member::LessThan(Object* _)
{
    return new Boolean(true);
}

Node* Member::LessThan(Function* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThan(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::LessThan(Member* _)
{
    return new Boolean(false);
}

Node* Boolean::LessThan(Boolean* _)
{
    return new Boolean(getValue() < _->getValue());
}

Node* Boolean::LessThan(Integer* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThan(Double* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThan(String* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThan(Array* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThan(Object* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThan(Function* _)
{
    return new Boolean(true);
}

Node* Integer::LessThan(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::LessThan(Member* _)
{
    return new Boolean(false);
}

Node* Integer::LessThan(Boolean* _)
{
    return new Boolean(false);
}

Node* Integer::LessThan(Integer* _)
{
    return new Boolean(getValue() < _->getValue());
}

Node* Integer::LessThan(Double* _)
{
    return new Boolean(getValue() < _->getValue());
}

Node* Integer::LessThan(String* _)
{
    return new Boolean(true);
}

Node* Integer::LessThan(Array* _)
{
    return new Boolean(true);
}

Node* Integer::LessThan(Object* _)
{
    return new Boolean(true);
}

Node* Integer::LessThan(Function* _)
{
    return new Boolean(true);
}

Node* Double::LessThan(Error* _)
{
    _->retain();
    return _;
}

Node* Double::LessThan(Member* _)
{
    return new Boolean(false);
}

Node* Double::LessThan(Boolean* _)
{
    return new Boolean(false);
}

Node* Double::LessThan(Integer* _)
{
    return new Boolean(false);
}

Node* Double::LessThan(Double* _)
{
    _->retain();
    return _;
}

Node* Double::LessThan(String* _)
{
    return new Boolean(true);
}

Node* Double::LessThan(Array* _)
{
    return new Boolean(true);
}

Node* Double::LessThan(Object* _)
{
    return new Boolean(true);
}

Node* Double::LessThan(Function* _)
{
    return new Boolean(true);
}

Node* String::LessThan(Error* _)
{
    _->retain();
    return _;
}

Node* String::LessThan(Member* _)
{
    return new Boolean(false);
}

Node* String::LessThan(Boolean* _)
{
    return new Boolean(false);
}

Node* String::LessThan(Integer* _)
{
    return new Boolean(false);
}

Node* String::LessThan(Double* _)
{
    return new Boolean(false);
}

Node* String::LessThan(String* _)
{
    return new Boolean(getValue() < _->getValue());
}

Node* String::LessThan(Array* _)
{
    return new Boolean(true);
}

Node* String::LessThan(Object* _)
{
    return new Boolean(true);
}

Node* String::LessThan(Function* _)
{
    return new Boolean(true);
}

Node* Array::LessThan(Error* _)
{
    _->retain();
    return _;
}

Node* Array::LessThan(Member* _)
{
    return new Boolean(false);
}

Node* Array::LessThan(Boolean* _)
{
    return new Boolean(false);
}

Node* Array::LessThan(Integer* _)
{
    return new Boolean(false);
}

Node* Array::LessThan(Double* _)
{
    return new Boolean(false);
}

Node* Array::LessThan(String* _)
{
    return new Boolean(false);
}

Node* Array::LessThan(Array* _)
{
    return new Boolean(getValue() < _->getValue());
}

Node* Array::LessThan(Object* _)
{
    return new Boolean(true);
}

Node* Array::LessThan(Function* _)
{
    return new Boolean(true);
}

Node* Object::LessThan(Error* _)
{
    _->retain();
    return _;
}

Node* Object::LessThan(Member* _)
{
    return new Boolean(false);
}

Node* Object::LessThan(Boolean* _)
{
    return new Boolean(false);
}

Node* Object::LessThan(Integer* _)
{
    return new Boolean(false);
}

Node* Object::LessThan(Double* _)
{
    return new Boolean(false);
}

Node* Object::LessThan(String* _)
{
    return new Boolean(false);
}

Node* Object::LessThan(Array* _)
{
    return new Boolean(false);
}

Node* Object::LessThan(Object* _)
{
    return new Boolean(getValue() < _->getValue());
}

Node* Object::LessThan(Function* _)
{
    return new Boolean(true);
}

Node* Function::LessThan(Error* _)
{
    _->retain();
    return _;
}

Node* Function::LessThan(Member* _)
{
    return new Boolean(false);
}

Node* Function::LessThan(Boolean* _)
{
    return new Boolean(false);
}

Node* Function::LessThan(Integer* _)
{
    return new Boolean(false);
}

Node* Function::LessThan(Double* _)
{
    return new Boolean(false);
}

Node* Function::LessThan(String* _)
{
    return new Boolean(false);
}

Node* Function::LessThan(Array* _)
{
    return new Boolean(false);
}

Node* Function::LessThan(Object* _)
{
    return new Boolean(false);
}

Node* Function::LessThan(Function* _)
{
    return new Boolean(getValue() < _->getValue());
}

Node* Error::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* Error::GreaterThan(Member* _)
{
    retain();
    return this;
}

Node* Error::GreaterThan(Boolean* _)
{
    retain();
    return this;
}

Node* Error::GreaterThan(Integer* _)
{
    retain();
    return this;
}

Node* Error::GreaterThan(Double* _)
{
    retain();
    return this;
}

Node* Error::GreaterThan(String* _)
{
    retain();
    return this;
}

Node* Error::GreaterThan(Array* _)
{
    retain();
    return this;
}

Node* Error::GreaterThan(Object* _)
{
    retain();
    return this;
}

Node* Error::GreaterThan(Function* _)
{
    retain();
    return this;
}

Node* Member::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* Member::GreaterThan(Member* _)
{
    return new Boolean( getValue() > _->getValue() );
}

Node* Member::GreaterThan(Boolean* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThan(Integer* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThan(Double* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThan(String* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThan(Array* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThan(Object* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThan(Function* _)
{
    return new Boolean(true);
}

Node* Boolean::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::GreaterThan(Member* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThan(Boolean* _)
{
    return new Boolean(getValue() > _->getValue());
}

Node* Boolean::GreaterThan(Integer* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThan(Double* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThan(String* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThan(Array* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThan(Object* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThan(Function* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::GreaterThan(Member* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThan(Boolean* _)
{
    return new Boolean(true);
}

Node* Integer::GreaterThan(Integer* _)
{
    return new Boolean(getValue() > _->getValue());
}

Node* Integer::GreaterThan(Double* _)
{
    return new Boolean(getValue() > _->getValue());
}

Node* Integer::GreaterThan(String* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThan(Array* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThan(Object* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThan(Function* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* Double::GreaterThan(Member* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThan(Boolean* _)
{
    return new Boolean(true);
}

Node* Double::GreaterThan(Integer* _)
{
    return new Boolean(true);
}

Node* Double::GreaterThan(Double* _)
{
    return new Boolean(getValue() > _->getValue());
}

Node* Double::GreaterThan(String* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThan(Array* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThan(Object* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThan(Function* _)
{
    return new Boolean(false);
}

Node* String::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* String::GreaterThan(Member* _)
{
    return new Boolean(false);
}

Node* String::GreaterThan(Boolean* _)
{
    return new Boolean(true);
}

Node* String::GreaterThan(Integer* _)
{
    return new Boolean(true);
}

Node* String::GreaterThan(Double* _)
{
    return new Boolean(true);
}

Node* String::GreaterThan(String* _)
{
    return new Boolean(getValue() > _->getValue());
}

Node* String::GreaterThan(Array* _)
{
    return new Boolean(false);
}

Node* String::GreaterThan(Object* _)
{
    return new Boolean(false);
}

Node* String::GreaterThan(Function* _)
{
    return new Boolean(false);
}

Node* Array::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* Array::GreaterThan(Member* _)
{
    return new Boolean(false);
}

Node* Array::GreaterThan(Boolean* _)
{
    return new Boolean(true);
}

Node* Array::GreaterThan(Integer* _)
{
    return new Boolean(true);
}

Node* Array::GreaterThan(Double* _)
{
    return new Boolean(true);
}

Node* Array::GreaterThan(String* _)
{
    return new Boolean(true);
}

Node* Array::GreaterThan(Array* _)
{
    return new Boolean(getValue() > _->getValue());
}

Node* Array::GreaterThan(Object* _)
{
    return new Boolean(false);
}

Node* Array::GreaterThan(Function* _)
{
    return new Boolean(false);
}

Node* Object::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* Object::GreaterThan(Member* _)
{
    return new Boolean(false);
}

Node* Object::GreaterThan(Boolean* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThan(Integer* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThan(Double* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThan(String* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThan(Array* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThan(Object* _)
{
    return new Boolean(getValue() > _->getValue());
}

Node* Object::GreaterThan(Function* _)
{
    return new Boolean(false);
}

Node* Function::GreaterThan(Error* _)
{
    _->retain();
    return _;
}

Node* Function::GreaterThan(Member* _)
{
    return new Boolean(false);
}

Node* Function::GreaterThan(Boolean* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThan(Integer* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThan(Double* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThan(String* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThan(Array* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThan(Object* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThan(Function* _)
{
    return new Boolean(getValue() > _->getValue());
}

Node* Error::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Error::LessThanOrEqualTo(Member* _)
{
    retain();
    return this;
}

Node* Error::LessThanOrEqualTo(Boolean* _)
{
    retain();
    return this;
}

Node* Error::LessThanOrEqualTo(Integer* _)
{
    retain();
    return this;
}

Node* Error::LessThanOrEqualTo(Double* _)
{
    retain();
    return this;
}

Node* Error::LessThanOrEqualTo(String* _)
{
    retain();
    return this;
}

Node* Error::LessThanOrEqualTo(Array* _)
{
    retain();
    return this;
}

Node* Error::LessThanOrEqualTo(Object* _)
{
    retain();
    return this;
}

Node* Error::LessThanOrEqualTo(Function* _)
{
    retain();
    return this;
}

Node* Member::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Member::LessThanOrEqualTo(Member* _)
{
    return new Boolean( getValue() <= _->getValue() );
}

Node* Member::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* Member::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(true);
}

Node* Member::LessThanOrEqualTo(Double* _)
{
    return new Boolean(true);
}

Node* Member::LessThanOrEqualTo(String* _)
{
    return new Boolean(true);
}

Node* Member::LessThanOrEqualTo(Array* _)
{
    return new Boolean(true);
}

Node* Member::LessThanOrEqualTo(Object* _)
{
    return new Boolean(true);
}

Node* Member::LessThanOrEqualTo(Function* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::LessThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Boolean::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(getValue() <= _->getValue());
}

Node* Boolean::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThanOrEqualTo(Double* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThanOrEqualTo(String* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThanOrEqualTo(Array* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThanOrEqualTo(Object* _)
{
    return new Boolean(true);
}

Node* Boolean::LessThanOrEqualTo(Function* _)
{
    return new Boolean(true);
}

Node* Integer::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::LessThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Integer::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(false);
}

Node* Integer::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(getValue() <= _->getValue());
}

Node* Integer::LessThanOrEqualTo(Double* _)
{
    return new Boolean(getValue() <= _->getValue());
}

Node* Integer::LessThanOrEqualTo(String* _)
{
    return new Boolean(true);
}

Node* Integer::LessThanOrEqualTo(Array* _)
{
    return new Boolean(true);
}

Node* Integer::LessThanOrEqualTo(Object* _)
{
    return new Boolean(true);
}

Node* Integer::LessThanOrEqualTo(Function* _)
{
    return new Boolean(true);
}

Node* Double::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Double::LessThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Double::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(false);
}

Node* Double::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(getValue() <= _->getValue().toDouble());
}

Node* Double::LessThanOrEqualTo(Double* _)
{
    return new Boolean(getValue() <= _->getValue());
}

Node* Double::LessThanOrEqualTo(String* _)
{
    return new Boolean(true);
}

Node* Double::LessThanOrEqualTo(Array* _)
{
    return new Boolean(true);
}

Node* Double::LessThanOrEqualTo(Object* _)
{
    return new Boolean(true);
}

Node* Double::LessThanOrEqualTo(Function* _)
{
    return new Boolean(true);
}

Node* String::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* String::LessThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* String::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(false);
}

Node* String::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(false);
}

Node* String::LessThanOrEqualTo(Double* _)
{
    return new Boolean(false);
}

Node* String::LessThanOrEqualTo(String* _)
{
    return new Boolean(getValue() <= _->getValue());
}

Node* String::LessThanOrEqualTo(Array* _)
{
    return new Boolean(true);
}

Node* String::LessThanOrEqualTo(Object* _)
{
    return new Boolean(true);
}

Node* String::LessThanOrEqualTo(Function* _)
{
    return new Boolean(true);
}

Node* Array::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Array::LessThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Array::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(false);
}

Node* Array::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(false);
}

Node* Array::LessThanOrEqualTo(Double* _)
{
    return new Boolean(false);
}

Node* Array::LessThanOrEqualTo(String* _)
{
    return new Boolean(false);
}

Node* Array::LessThanOrEqualTo(Array* _)
{
    return new Boolean(getValue() <= _->getValue());
}

Node* Array::LessThanOrEqualTo(Object* _)
{
    return new Boolean(true);
}

Node* Array::LessThanOrEqualTo(Function* _)
{
    return new Boolean(true);
}

Node* Object::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Object::LessThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Object::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(false);
}

Node* Object::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(false);
}

Node* Object::LessThanOrEqualTo(Double* _)
{
    return new Boolean(false);
}

Node* Object::LessThanOrEqualTo(String* _)
{
    return new Boolean(false);
}

Node* Object::LessThanOrEqualTo(Array* _)
{
    return new Boolean(false);
}

Node* Object::LessThanOrEqualTo(Object* _)
{
    return new Boolean(getValue() <= _->getValue());
}

Node* Object::LessThanOrEqualTo(Function* _)
{
    return new Boolean(true);
}

Node* Function::LessThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Function::LessThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Function::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(false);
}

Node* Function::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(false);
}

Node* Function::LessThanOrEqualTo(Double* _)
{
    return new Boolean(false);
}

Node* Function::LessThanOrEqualTo(String* _)
{
    return new Boolean(false);
}

Node* Function::LessThanOrEqualTo(Array* _)
{
    return new Boolean(false);
}

Node* Function::LessThanOrEqualTo(Object* _)
{
    return new Boolean(false);
}

Node* Function::LessThanOrEqualTo(Function* _)
{
    return new Boolean(getValue() <= _->getValue());
}

Node* Error::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Error::GreaterThanOrEqualTo(Member* _)
{
    retain();
    return this;
}

Node* Error::GreaterThanOrEqualTo(Boolean* _)
{
    retain();
    return this;
}

Node* Error::GreaterThanOrEqualTo(Integer* _)
{
    retain();
    return this;
}

Node* Error::GreaterThanOrEqualTo(Double* _)
{
    retain();
    return this;
}

Node* Error::GreaterThanOrEqualTo(String* _)
{
    retain();
    return this;
}

Node* Error::GreaterThanOrEqualTo(Array* _)
{
    retain();
    return this;
}

Node* Error::GreaterThanOrEqualTo(Object* _)
{
    retain();
    return this;
}

Node* Error::GreaterThanOrEqualTo(Function* _)
{
    retain();
    return this;
}

Node* Member::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Member::GreaterThanOrEqualTo(Member* _)
{
    return new Boolean( getValue() >= _->getValue() );
}

Node* Member::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThanOrEqualTo(Double* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThanOrEqualTo(String* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThanOrEqualTo(Array* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThanOrEqualTo(Object* _)
{
    return new Boolean(true);
}

Node* Member::GreaterThanOrEqualTo(Function* _)
{
    return new Boolean(true);
}

Node* Boolean::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Boolean::GreaterThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(getValue() >= _->getValue());
}

Node* Boolean::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThanOrEqualTo(Double* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThanOrEqualTo(String* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThanOrEqualTo(Array* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThanOrEqualTo(Object* _)
{
    return new Boolean(false);
}

Node* Boolean::GreaterThanOrEqualTo(Function* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Integer::GreaterThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* Integer::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(getValue() >= _->getValue());
}

Node* Integer::GreaterThanOrEqualTo(Double* _)
{
    return new Boolean(getValue() >= _->getValue());
}

Node* Integer::GreaterThanOrEqualTo(String* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThanOrEqualTo(Array* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThanOrEqualTo(Object* _)
{
    return new Boolean(false);
}

Node* Integer::GreaterThanOrEqualTo(Function* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Double::GreaterThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* Double::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(getValue() >= _->getValue().toDouble());
}

Node* Double::GreaterThanOrEqualTo(Double* _)
{
    return new Boolean(getValue() >= _->getValue());
}

Node* Double::GreaterThanOrEqualTo(String* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThanOrEqualTo(Array* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThanOrEqualTo(Object* _)
{
    return new Boolean(false);
}

Node* Double::GreaterThanOrEqualTo(Function* _)
{
    return new Boolean(false);
}

Node* String::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* String::GreaterThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* String::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* String::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(true);
}

Node* String::GreaterThanOrEqualTo(Double* _)
{
    return new Boolean(true);
}

Node* String::GreaterThanOrEqualTo(String* _)
{
    return new Boolean(getValue() >= _->getValue());
}

Node* String::GreaterThanOrEqualTo(Array* _)
{
    return new Boolean(false);
}

Node* String::GreaterThanOrEqualTo(Object* _)
{
    return new Boolean(false);
}

Node* String::GreaterThanOrEqualTo(Function* _)
{
    return new Boolean(false);
}

Node* Array::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Array::GreaterThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Array::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* Array::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(true);
}

Node* Array::GreaterThanOrEqualTo(Double* _)
{
    return new Boolean(true);
}

Node* Array::GreaterThanOrEqualTo(String* _)
{
    return new Boolean(true);
}

Node* Array::GreaterThanOrEqualTo(Array* _)
{
    return new Boolean(getValue() >= _->getValue());
}

Node* Array::GreaterThanOrEqualTo(Object* _)
{
    return new Boolean(false);
}

Node* Array::GreaterThanOrEqualTo(Function* _)
{
    return new Boolean(false);
}

Node* Object::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Object::GreaterThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Object::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThanOrEqualTo(Double* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThanOrEqualTo(String* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThanOrEqualTo(Array* _)
{
    return new Boolean(true);
}

Node* Object::GreaterThanOrEqualTo(Object* _)
{
    return new Boolean(getValue() >= _->getValue());
}

Node* Object::GreaterThanOrEqualTo(Function* _)
{
    return new Boolean(false);
}

Node* Function::GreaterThanOrEqualTo(Error* _)
{
    _->retain();
    return _;
}

Node* Function::GreaterThanOrEqualTo(Member* _)
{
    return new Boolean(false);
}

Node* Function::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThanOrEqualTo(Double* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThanOrEqualTo(String* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThanOrEqualTo(Array* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThanOrEqualTo(Object* _)
{
    return new Boolean(true);
}

Node* Function::GreaterThanOrEqualTo(Function* _)
{
    return new Boolean(getValue() >= _->getValue());
}

Node* Error::And(Node* _) { return _->back_And(this); }
Node* Error::back_And(Error* _) { return _->And(this); }
Node* Error::back_And(Member* _) { return _->And(this); }
Node* Error::back_And(Boolean* _) { return _->And(this); }
Node* Error::back_And(Integer* _) { return _->And(this); }
Node* Error::back_And(Double* _) { return _->And(this); }
Node* Error::back_And(String* _) { return _->And(this); }
Node* Error::back_And(Array* _) { return _->And(this); }
Node* Error::back_And(Object* _) { return _->And(this); }
Node* Error::back_And(Function* _) { return _->And(this); }
Node* Member::And(Node* _) { return _->back_And(this); }
Node* Member::back_And(Error* _) { return _->And(this); }
Node* Member::back_And(Member* _) { return _->And(this); }
Node* Member::back_And(Boolean* _) { return _->And(this); }
Node* Member::back_And(Integer* _) { return _->And(this); }
Node* Member::back_And(Double* _) { return _->And(this); }
Node* Member::back_And(String* _) { return _->And(this); }
Node* Member::back_And(Array* _) { return _->And(this); }
Node* Member::back_And(Object* _) { return _->And(this); }
Node* Member::back_And(Function* _) { return _->And(this); }
Node* Boolean::And(Node* _) { return _->back_And(this); }
Node* Boolean::back_And(Error* _) { return _->And(this); }
Node* Boolean::back_And(Member* _) { return _->And(this); }
Node* Boolean::back_And(Boolean* _) { return _->And(this); }
Node* Boolean::back_And(Integer* _) { return _->And(this); }
Node* Boolean::back_And(Double* _) { return _->And(this); }
Node* Boolean::back_And(String* _) { return _->And(this); }
Node* Boolean::back_And(Array* _) { return _->And(this); }
Node* Boolean::back_And(Object* _) { return _->And(this); }
Node* Boolean::back_And(Function* _) { return _->And(this); }
Node* Integer::And(Node* _) { return _->back_And(this); }
Node* Integer::back_And(Error* _) { return _->And(this); }
Node* Integer::back_And(Member* _) { return _->And(this); }
Node* Integer::back_And(Boolean* _) { return _->And(this); }
Node* Integer::back_And(Integer* _) { return _->And(this); }
Node* Integer::back_And(Double* _) { return _->And(this); }
Node* Integer::back_And(String* _) { return _->And(this); }
Node* Integer::back_And(Array* _) { return _->And(this); }
Node* Integer::back_And(Object* _) { return _->And(this); }
Node* Integer::back_And(Function* _) { return _->And(this); }
Node* Double::And(Node* _) { return _->back_And(this); }
Node* Double::back_And(Error* _) { return _->And(this); }
Node* Double::back_And(Member* _) { return _->And(this); }
Node* Double::back_And(Boolean* _) { return _->And(this); }
Node* Double::back_And(Integer* _) { return _->And(this); }
Node* Double::back_And(Double* _) { return _->And(this); }
Node* Double::back_And(String* _) { return _->And(this); }
Node* Double::back_And(Array* _) { return _->And(this); }
Node* Double::back_And(Object* _) { return _->And(this); }
Node* Double::back_And(Function* _) { return _->And(this); }
Node* String::And(Node* _) { return _->back_And(this); }
Node* String::back_And(Error* _) { return _->And(this); }
Node* String::back_And(Member* _) { return _->And(this); }
Node* String::back_And(Boolean* _) { return _->And(this); }
Node* String::back_And(Integer* _) { return _->And(this); }
Node* String::back_And(Double* _) { return _->And(this); }
Node* String::back_And(String* _) { return _->And(this); }
Node* String::back_And(Array* _) { return _->And(this); }
Node* String::back_And(Object* _) { return _->And(this); }
Node* String::back_And(Function* _) { return _->And(this); }
Node* Array::And(Node* _) { return _->back_And(this); }
Node* Array::back_And(Error* _) { return _->And(this); }
Node* Array::back_And(Member* _) { return _->And(this); }
Node* Array::back_And(Boolean* _) { return _->And(this); }
Node* Array::back_And(Integer* _) { return _->And(this); }
Node* Array::back_And(Double* _) { return _->And(this); }
Node* Array::back_And(String* _) { return _->And(this); }
Node* Array::back_And(Array* _) { return _->And(this); }
Node* Array::back_And(Object* _) { return _->And(this); }
Node* Array::back_And(Function* _) { return _->And(this); }
Node* Object::And(Node* _) { return _->back_And(this); }
Node* Object::back_And(Error* _) { return _->And(this); }
Node* Object::back_And(Member* _) { return _->And(this); }
Node* Object::back_And(Boolean* _) { return _->And(this); }
Node* Object::back_And(Integer* _) { return _->And(this); }
Node* Object::back_And(Double* _) { return _->And(this); }
Node* Object::back_And(String* _) { return _->And(this); }
Node* Object::back_And(Array* _) { return _->And(this); }
Node* Object::back_And(Object* _) { return _->And(this); }
Node* Object::back_And(Function* _) { return _->And(this); }
Node* Function::And(Node* _) { return _->back_And(this); }
Node* Function::back_And(Error* _) { return _->And(this); }
Node* Function::back_And(Member* _) { return _->And(this); }
Node* Function::back_And(Boolean* _) { return _->And(this); }
Node* Function::back_And(Integer* _) { return _->And(this); }
Node* Function::back_And(Double* _) { return _->And(this); }
Node* Function::back_And(String* _) { return _->And(this); }
Node* Function::back_And(Array* _) { return _->And(this); }
Node* Function::back_And(Object* _) { return _->And(this); }
Node* Function::back_And(Function* _) { return _->And(this); }
Node* Error::Or(Node* _) { return _->back_Or(this); }
Node* Error::back_Or(Error* _) { return _->Or(this); }
Node* Error::back_Or(Member* _) { return _->Or(this); }
Node* Error::back_Or(Boolean* _) { return _->Or(this); }
Node* Error::back_Or(Integer* _) { return _->Or(this); }
Node* Error::back_Or(Double* _) { return _->Or(this); }
Node* Error::back_Or(String* _) { return _->Or(this); }
Node* Error::back_Or(Array* _) { return _->Or(this); }
Node* Error::back_Or(Object* _) { return _->Or(this); }
Node* Error::back_Or(Function* _) { return _->Or(this); }
Node* Member::Or(Node* _) { return _->back_Or(this); }
Node* Member::back_Or(Error* _) { return _->Or(this); }
Node* Member::back_Or(Member* _) { return _->Or(this); }
Node* Member::back_Or(Boolean* _) { return _->Or(this); }
Node* Member::back_Or(Integer* _) { return _->Or(this); }
Node* Member::back_Or(Double* _) { return _->Or(this); }
Node* Member::back_Or(String* _) { return _->Or(this); }
Node* Member::back_Or(Array* _) { return _->Or(this); }
Node* Member::back_Or(Object* _) { return _->Or(this); }
Node* Member::back_Or(Function* _) { return _->Or(this); }
Node* Boolean::Or(Node* _) { return _->back_Or(this); }
Node* Boolean::back_Or(Error* _) { return _->Or(this); }
Node* Boolean::back_Or(Member* _) { return _->Or(this); }
Node* Boolean::back_Or(Boolean* _) { return _->Or(this); }
Node* Boolean::back_Or(Integer* _) { return _->Or(this); }
Node* Boolean::back_Or(Double* _) { return _->Or(this); }
Node* Boolean::back_Or(String* _) { return _->Or(this); }
Node* Boolean::back_Or(Array* _) { return _->Or(this); }
Node* Boolean::back_Or(Object* _) { return _->Or(this); }
Node* Boolean::back_Or(Function* _) { return _->Or(this); }
Node* Integer::Or(Node* _) { return _->back_Or(this); }
Node* Integer::back_Or(Error* _) { return _->Or(this); }
Node* Integer::back_Or(Member* _) { return _->Or(this); }
Node* Integer::back_Or(Boolean* _) { return _->Or(this); }
Node* Integer::back_Or(Integer* _) { return _->Or(this); }
Node* Integer::back_Or(Double* _) { return _->Or(this); }
Node* Integer::back_Or(String* _) { return _->Or(this); }
Node* Integer::back_Or(Array* _) { return _->Or(this); }
Node* Integer::back_Or(Object* _) { return _->Or(this); }
Node* Integer::back_Or(Function* _) { return _->Or(this); }
Node* Double::Or(Node* _) { return _->back_Or(this); }
Node* Double::back_Or(Error* _) { return _->Or(this); }
Node* Double::back_Or(Member* _) { return _->Or(this); }
Node* Double::back_Or(Boolean* _) { return _->Or(this); }
Node* Double::back_Or(Integer* _) { return _->Or(this); }
Node* Double::back_Or(Double* _) { return _->Or(this); }
Node* Double::back_Or(String* _) { return _->Or(this); }
Node* Double::back_Or(Array* _) { return _->Or(this); }
Node* Double::back_Or(Object* _) { return _->Or(this); }
Node* Double::back_Or(Function* _) { return _->Or(this); }
Node* String::Or(Node* _) { return _->back_Or(this); }
Node* String::back_Or(Error* _) { return _->Or(this); }
Node* String::back_Or(Member* _) { return _->Or(this); }
Node* String::back_Or(Boolean* _) { return _->Or(this); }
Node* String::back_Or(Integer* _) { return _->Or(this); }
Node* String::back_Or(Double* _) { return _->Or(this); }
Node* String::back_Or(String* _) { return _->Or(this); }
Node* String::back_Or(Array* _) { return _->Or(this); }
Node* String::back_Or(Object* _) { return _->Or(this); }
Node* String::back_Or(Function* _) { return _->Or(this); }
Node* Array::Or(Node* _) { return _->back_Or(this); }
Node* Array::back_Or(Error* _) { return _->Or(this); }
Node* Array::back_Or(Member* _) { return _->Or(this); }
Node* Array::back_Or(Boolean* _) { return _->Or(this); }
Node* Array::back_Or(Integer* _) { return _->Or(this); }
Node* Array::back_Or(Double* _) { return _->Or(this); }
Node* Array::back_Or(String* _) { return _->Or(this); }
Node* Array::back_Or(Array* _) { return _->Or(this); }
Node* Array::back_Or(Object* _) { return _->Or(this); }
Node* Array::back_Or(Function* _) { return _->Or(this); }
Node* Object::Or(Node* _) { return _->back_Or(this); }
Node* Object::back_Or(Error* _) { return _->Or(this); }
Node* Object::back_Or(Member* _) { return _->Or(this); }
Node* Object::back_Or(Boolean* _) { return _->Or(this); }
Node* Object::back_Or(Integer* _) { return _->Or(this); }
Node* Object::back_Or(Double* _) { return _->Or(this); }
Node* Object::back_Or(String* _) { return _->Or(this); }
Node* Object::back_Or(Array* _) { return _->Or(this); }
Node* Object::back_Or(Object* _) { return _->Or(this); }
Node* Object::back_Or(Function* _) { return _->Or(this); }
Node* Function::Or(Node* _) { return _->back_Or(this); }
Node* Function::back_Or(Error* _) { return _->Or(this); }
Node* Function::back_Or(Member* _) { return _->Or(this); }
Node* Function::back_Or(Boolean* _) { return _->Or(this); }
Node* Function::back_Or(Integer* _) { return _->Or(this); }
Node* Function::back_Or(Double* _) { return _->Or(this); }
Node* Function::back_Or(String* _) { return _->Or(this); }
Node* Function::back_Or(Array* _) { return _->Or(this); }
Node* Function::back_Or(Object* _) { return _->Or(this); }
Node* Function::back_Or(Function* _) { return _->Or(this); }
Node* Error::Impart(Node* _) { return _->back_Impart(this); }
Node* Error::back_Impart(Error* _) { return _->Impart(this); }
Node* Error::back_Impart(Member* _) { return _->Impart(this); }
Node* Error::back_Impart(Boolean* _) { return _->Impart(this); }
Node* Error::back_Impart(Integer* _) { return _->Impart(this); }
Node* Error::back_Impart(Double* _) { return _->Impart(this); }
Node* Error::back_Impart(String* _) { return _->Impart(this); }
Node* Error::back_Impart(Array* _) { return _->Impart(this); }
Node* Error::back_Impart(Object* _) { return _->Impart(this); }
Node* Error::back_Impart(Function* _) { return _->Impart(this); }
Node* Member::Impart(Node* _) { return _->back_Impart(this); }
Node* Member::back_Impart(Error* _) { return _->Impart(this); }
Node* Member::back_Impart(Member* _) { return _->Impart(this); }
Node* Member::back_Impart(Boolean* _) { return _->Impart(this); }
Node* Member::back_Impart(Integer* _) { return _->Impart(this); }
Node* Member::back_Impart(Double* _) { return _->Impart(this); }
Node* Member::back_Impart(String* _) { return _->Impart(this); }
Node* Member::back_Impart(Array* _) { return _->Impart(this); }
Node* Member::back_Impart(Object* _) { return _->Impart(this); }
Node* Member::back_Impart(Function* _) { return _->Impart(this); }
Node* Boolean::Impart(Node* _) { return _->back_Impart(this); }
Node* Boolean::back_Impart(Error* _) { return _->Impart(this); }
Node* Boolean::back_Impart(Member* _) { return _->Impart(this); }
Node* Boolean::back_Impart(Boolean* _) { return _->Impart(this); }
Node* Boolean::back_Impart(Integer* _) { return _->Impart(this); }
Node* Boolean::back_Impart(Double* _) { return _->Impart(this); }
Node* Boolean::back_Impart(String* _) { return _->Impart(this); }
Node* Boolean::back_Impart(Array* _) { return _->Impart(this); }
Node* Boolean::back_Impart(Object* _) { return _->Impart(this); }
Node* Boolean::back_Impart(Function* _) { return _->Impart(this); }
Node* Integer::Impart(Node* _) { return _->back_Impart(this); }
Node* Integer::back_Impart(Error* _) { return _->Impart(this); }
Node* Integer::back_Impart(Member* _) { return _->Impart(this); }
Node* Integer::back_Impart(Boolean* _) { return _->Impart(this); }
Node* Integer::back_Impart(Integer* _) { return _->Impart(this); }
Node* Integer::back_Impart(Double* _) { return _->Impart(this); }
Node* Integer::back_Impart(String* _) { return _->Impart(this); }
Node* Integer::back_Impart(Array* _) { return _->Impart(this); }
Node* Integer::back_Impart(Object* _) { return _->Impart(this); }
Node* Integer::back_Impart(Function* _) { return _->Impart(this); }
Node* Double::Impart(Node* _) { return _->back_Impart(this); }
Node* Double::back_Impart(Error* _) { return _->Impart(this); }
Node* Double::back_Impart(Member* _) { return _->Impart(this); }
Node* Double::back_Impart(Boolean* _) { return _->Impart(this); }
Node* Double::back_Impart(Integer* _) { return _->Impart(this); }
Node* Double::back_Impart(Double* _) { return _->Impart(this); }
Node* Double::back_Impart(String* _) { return _->Impart(this); }
Node* Double::back_Impart(Array* _) { return _->Impart(this); }
Node* Double::back_Impart(Object* _) { return _->Impart(this); }
Node* Double::back_Impart(Function* _) { return _->Impart(this); }
Node* String::Impart(Node* _) { return _->back_Impart(this); }
Node* String::back_Impart(Error* _) { return _->Impart(this); }
Node* String::back_Impart(Member* _) { return _->Impart(this); }
Node* String::back_Impart(Boolean* _) { return _->Impart(this); }
Node* String::back_Impart(Integer* _) { return _->Impart(this); }
Node* String::back_Impart(Double* _) { return _->Impart(this); }
Node* String::back_Impart(String* _) { return _->Impart(this); }
Node* String::back_Impart(Array* _) { return _->Impart(this); }
Node* String::back_Impart(Object* _) { return _->Impart(this); }
Node* String::back_Impart(Function* _) { return _->Impart(this); }
Node* Array::Impart(Node* _) { return _->back_Impart(this); }
Node* Array::back_Impart(Error* _) { return _->Impart(this); }
Node* Array::back_Impart(Member* _) { return _->Impart(this); }
Node* Array::back_Impart(Boolean* _) { return _->Impart(this); }
Node* Array::back_Impart(Integer* _) { return _->Impart(this); }
Node* Array::back_Impart(Double* _) { return _->Impart(this); }
Node* Array::back_Impart(String* _) { return _->Impart(this); }
Node* Array::back_Impart(Array* _) { return _->Impart(this); }
Node* Array::back_Impart(Object* _) { return _->Impart(this); }
Node* Array::back_Impart(Function* _) { return _->Impart(this); }
Node* Object::Impart(Node* _) { return _->back_Impart(this); }
Node* Object::back_Impart(Error* _) { return _->Impart(this); }
Node* Object::back_Impart(Member* _) { return _->Impart(this); }
Node* Object::back_Impart(Boolean* _) { return _->Impart(this); }
Node* Object::back_Impart(Integer* _) { return _->Impart(this); }
Node* Object::back_Impart(Double* _) { return _->Impart(this); }
Node* Object::back_Impart(String* _) { return _->Impart(this); }
Node* Object::back_Impart(Array* _) { return _->Impart(this); }
Node* Object::back_Impart(Object* _) { return _->Impart(this); }
Node* Object::back_Impart(Function* _) { return _->Impart(this); }
Node* Function::Impart(Node* _) { return _->back_Impart(this); }
Node* Function::back_Impart(Error* _) { return _->Impart(this); }
Node* Function::back_Impart(Member* _) { return _->Impart(this); }
Node* Function::back_Impart(Boolean* _) { return _->Impart(this); }
Node* Function::back_Impart(Integer* _) { return _->Impart(this); }
Node* Function::back_Impart(Double* _) { return _->Impart(this); }
Node* Function::back_Impart(String* _) { return _->Impart(this); }
Node* Function::back_Impart(Array* _) { return _->Impart(this); }
Node* Function::back_Impart(Object* _) { return _->Impart(this); }
Node* Function::back_Impart(Function* _) { return _->Impart(this); }
Node* Error::Plus(Node* _) { return _->back_Plus(this); }
Node* Error::back_Plus(Error* _) { return _->Plus(this); }
Node* Error::back_Plus(Member* _) { return _->Plus(this); }
Node* Error::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Error::back_Plus(Integer* _) { return _->Plus(this); }
Node* Error::back_Plus(Double* _) { return _->Plus(this); }
Node* Error::back_Plus(String* _) { return _->Plus(this); }
Node* Error::back_Plus(Array* _) { return _->Plus(this); }
Node* Error::back_Plus(Object* _) { return _->Plus(this); }
Node* Error::back_Plus(Function* _) { return _->Plus(this); }
Node* Member::Plus(Node* _) { return _->back_Plus(this); }
Node* Member::back_Plus(Error* _) { return _->Plus(this); }
Node* Member::back_Plus(Member* _) { return _->Plus(this); }
Node* Member::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Member::back_Plus(Integer* _) { return _->Plus(this); }
Node* Member::back_Plus(Double* _) { return _->Plus(this); }
Node* Member::back_Plus(String* _) { return _->Plus(this); }
Node* Member::back_Plus(Array* _) { return _->Plus(this); }
Node* Member::back_Plus(Object* _) { return _->Plus(this); }
Node* Member::back_Plus(Function* _) { return _->Plus(this); }
Node* Boolean::Plus(Node* _) { return _->back_Plus(this); }
Node* Boolean::back_Plus(Error* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Member* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Integer* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Double* _) { return _->Plus(this); }
Node* Boolean::back_Plus(String* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Array* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Object* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Function* _) { return _->Plus(this); }
Node* Integer::Plus(Node* _) { return _->back_Plus(this); }
Node* Integer::back_Plus(Error* _) { return _->Plus(this); }
Node* Integer::back_Plus(Member* _) { return _->Plus(this); }
Node* Integer::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Integer::back_Plus(Integer* _) { return _->Plus(this); }
Node* Integer::back_Plus(Double* _) { return _->Plus(this); }
Node* Integer::back_Plus(String* _) { return _->Plus(this); }
Node* Integer::back_Plus(Array* _) { return _->Plus(this); }
Node* Integer::back_Plus(Object* _) { return _->Plus(this); }
Node* Integer::back_Plus(Function* _) { return _->Plus(this); }
Node* Double::Plus(Node* _) { return _->back_Plus(this); }
Node* Double::back_Plus(Error* _) { return _->Plus(this); }
Node* Double::back_Plus(Member* _) { return _->Plus(this); }
Node* Double::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Double::back_Plus(Integer* _) { return _->Plus(this); }
Node* Double::back_Plus(Double* _) { return _->Plus(this); }
Node* Double::back_Plus(String* _) { return _->Plus(this); }
Node* Double::back_Plus(Array* _) { return _->Plus(this); }
Node* Double::back_Plus(Object* _) { return _->Plus(this); }
Node* Double::back_Plus(Function* _) { return _->Plus(this); }
Node* String::Plus(Node* _) { return _->back_Plus(this); }
Node* String::back_Plus(Error* _) { return _->Plus(this); }
Node* String::back_Plus(Member* _) { return _->Plus(this); }
Node* String::back_Plus(Boolean* _) { return _->Plus(this); }
Node* String::back_Plus(Integer* _) { return _->Plus(this); }
Node* String::back_Plus(Double* _) { return _->Plus(this); }
Node* String::back_Plus(String* _) { return _->Plus(this); }
Node* String::back_Plus(Array* _) { return _->Plus(this); }
Node* String::back_Plus(Object* _) { return _->Plus(this); }
Node* String::back_Plus(Function* _) { return _->Plus(this); }
Node* Array::Plus(Node* _) { return _->back_Plus(this); }
Node* Array::back_Plus(Error* _) { return _->Plus(this); }
Node* Array::back_Plus(Member* _) { return _->Plus(this); }
Node* Array::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Array::back_Plus(Integer* _) { return _->Plus(this); }
Node* Array::back_Plus(Double* _) { return _->Plus(this); }
Node* Array::back_Plus(String* _) { return _->Plus(this); }
Node* Array::back_Plus(Array* _) { return _->Plus(this); }
Node* Array::back_Plus(Object* _) { return _->Plus(this); }
Node* Array::back_Plus(Function* _) { return _->Plus(this); }
Node* Object::Plus(Node* _) { return _->back_Plus(this); }
Node* Object::back_Plus(Error* _) { return _->Plus(this); }
Node* Object::back_Plus(Member* _) { return _->Plus(this); }
Node* Object::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Object::back_Plus(Integer* _) { return _->Plus(this); }
Node* Object::back_Plus(Double* _) { return _->Plus(this); }
Node* Object::back_Plus(String* _) { return _->Plus(this); }
Node* Object::back_Plus(Array* _) { return _->Plus(this); }
Node* Object::back_Plus(Object* _) { return _->Plus(this); }
Node* Object::back_Plus(Function* _) { return _->Plus(this); }
Node* Function::Plus(Node* _) { return _->back_Plus(this); }
Node* Function::back_Plus(Error* _) { return _->Plus(this); }
Node* Function::back_Plus(Member* _) { return _->Plus(this); }
Node* Function::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Function::back_Plus(Integer* _) { return _->Plus(this); }
Node* Function::back_Plus(Double* _) { return _->Plus(this); }
Node* Function::back_Plus(String* _) { return _->Plus(this); }
Node* Function::back_Plus(Array* _) { return _->Plus(this); }
Node* Function::back_Plus(Object* _) { return _->Plus(this); }
Node* Function::back_Plus(Function* _) { return _->Plus(this); }
Node* Error::Minus(Node* _) { return _->back_Minus(this); }
Node* Error::back_Minus(Error* _) { return _->Minus(this); }
Node* Error::back_Minus(Member* _) { return _->Minus(this); }
Node* Error::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Error::back_Minus(Integer* _) { return _->Minus(this); }
Node* Error::back_Minus(Double* _) { return _->Minus(this); }
Node* Error::back_Minus(String* _) { return _->Minus(this); }
Node* Error::back_Minus(Array* _) { return _->Minus(this); }
Node* Error::back_Minus(Object* _) { return _->Minus(this); }
Node* Error::back_Minus(Function* _) { return _->Minus(this); }
Node* Member::Minus(Node* _) { return _->back_Minus(this); }
Node* Member::back_Minus(Error* _) { return _->Minus(this); }
Node* Member::back_Minus(Member* _) { return _->Minus(this); }
Node* Member::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Member::back_Minus(Integer* _) { return _->Minus(this); }
Node* Member::back_Minus(Double* _) { return _->Minus(this); }
Node* Member::back_Minus(String* _) { return _->Minus(this); }
Node* Member::back_Minus(Array* _) { return _->Minus(this); }
Node* Member::back_Minus(Object* _) { return _->Minus(this); }
Node* Member::back_Minus(Function* _) { return _->Minus(this); }
Node* Boolean::Minus(Node* _) { return _->back_Minus(this); }
Node* Boolean::back_Minus(Error* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Member* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Integer* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Double* _) { return _->Minus(this); }
Node* Boolean::back_Minus(String* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Array* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Object* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Function* _) { return _->Minus(this); }
Node* Integer::Minus(Node* _) { return _->back_Minus(this); }
Node* Integer::back_Minus(Error* _) { return _->Minus(this); }
Node* Integer::back_Minus(Member* _) { return _->Minus(this); }
Node* Integer::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Integer::back_Minus(Integer* _) { return _->Minus(this); }
Node* Integer::back_Minus(Double* _) { return _->Minus(this); }
Node* Integer::back_Minus(String* _) { return _->Minus(this); }
Node* Integer::back_Minus(Array* _) { return _->Minus(this); }
Node* Integer::back_Minus(Object* _) { return _->Minus(this); }
Node* Integer::back_Minus(Function* _) { return _->Minus(this); }
Node* Double::Minus(Node* _) { return _->back_Minus(this); }
Node* Double::back_Minus(Error* _) { return _->Minus(this); }
Node* Double::back_Minus(Member* _) { return _->Minus(this); }
Node* Double::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Double::back_Minus(Integer* _) { return _->Minus(this); }
Node* Double::back_Minus(Double* _) { return _->Minus(this); }
Node* Double::back_Minus(String* _) { return _->Minus(this); }
Node* Double::back_Minus(Array* _) { return _->Minus(this); }
Node* Double::back_Minus(Object* _) { return _->Minus(this); }
Node* Double::back_Minus(Function* _) { return _->Minus(this); }
Node* String::Minus(Node* _) { return _->back_Minus(this); }
Node* String::back_Minus(Error* _) { return _->Minus(this); }
Node* String::back_Minus(Member* _) { return _->Minus(this); }
Node* String::back_Minus(Boolean* _) { return _->Minus(this); }
Node* String::back_Minus(Integer* _) { return _->Minus(this); }
Node* String::back_Minus(Double* _) { return _->Minus(this); }
Node* String::back_Minus(String* _) { return _->Minus(this); }
Node* String::back_Minus(Array* _) { return _->Minus(this); }
Node* String::back_Minus(Object* _) { return _->Minus(this); }
Node* String::back_Minus(Function* _) { return _->Minus(this); }
Node* Array::Minus(Node* _) { return _->back_Minus(this); }
Node* Array::back_Minus(Error* _) { return _->Minus(this); }
Node* Array::back_Minus(Member* _) { return _->Minus(this); }
Node* Array::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Array::back_Minus(Integer* _) { return _->Minus(this); }
Node* Array::back_Minus(Double* _) { return _->Minus(this); }
Node* Array::back_Minus(String* _) { return _->Minus(this); }
Node* Array::back_Minus(Array* _) { return _->Minus(this); }
Node* Array::back_Minus(Object* _) { return _->Minus(this); }
Node* Array::back_Minus(Function* _) { return _->Minus(this); }
Node* Object::Minus(Node* _) { return _->back_Minus(this); }
Node* Object::back_Minus(Error* _) { return _->Minus(this); }
Node* Object::back_Minus(Member* _) { return _->Minus(this); }
Node* Object::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Object::back_Minus(Integer* _) { return _->Minus(this); }
Node* Object::back_Minus(Double* _) { return _->Minus(this); }
Node* Object::back_Minus(String* _) { return _->Minus(this); }
Node* Object::back_Minus(Array* _) { return _->Minus(this); }
Node* Object::back_Minus(Object* _) { return _->Minus(this); }
Node* Object::back_Minus(Function* _) { return _->Minus(this); }
Node* Function::Minus(Node* _) { return _->back_Minus(this); }
Node* Function::back_Minus(Error* _) { return _->Minus(this); }
Node* Function::back_Minus(Member* _) { return _->Minus(this); }
Node* Function::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Function::back_Minus(Integer* _) { return _->Minus(this); }
Node* Function::back_Minus(Double* _) { return _->Minus(this); }
Node* Function::back_Minus(String* _) { return _->Minus(this); }
Node* Function::back_Minus(Array* _) { return _->Minus(this); }
Node* Function::back_Minus(Object* _) { return _->Minus(this); }
Node* Function::back_Minus(Function* _) { return _->Minus(this); }
Node* Error::Times(Node* _) { return _->back_Times(this); }
Node* Error::back_Times(Error* _) { return _->Times(this); }
Node* Error::back_Times(Member* _) { return _->Times(this); }
Node* Error::back_Times(Boolean* _) { return _->Times(this); }
Node* Error::back_Times(Integer* _) { return _->Times(this); }
Node* Error::back_Times(Double* _) { return _->Times(this); }
Node* Error::back_Times(String* _) { return _->Times(this); }
Node* Error::back_Times(Array* _) { return _->Times(this); }
Node* Error::back_Times(Object* _) { return _->Times(this); }
Node* Error::back_Times(Function* _) { return _->Times(this); }
Node* Member::Times(Node* _) { return _->back_Times(this); }
Node* Member::back_Times(Error* _) { return _->Times(this); }
Node* Member::back_Times(Member* _) { return _->Times(this); }
Node* Member::back_Times(Boolean* _) { return _->Times(this); }
Node* Member::back_Times(Integer* _) { return _->Times(this); }
Node* Member::back_Times(Double* _) { return _->Times(this); }
Node* Member::back_Times(String* _) { return _->Times(this); }
Node* Member::back_Times(Array* _) { return _->Times(this); }
Node* Member::back_Times(Object* _) { return _->Times(this); }
Node* Member::back_Times(Function* _) { return _->Times(this); }
Node* Boolean::Times(Node* _) { return _->back_Times(this); }
Node* Boolean::back_Times(Error* _) { return _->Times(this); }
Node* Boolean::back_Times(Member* _) { return _->Times(this); }
Node* Boolean::back_Times(Boolean* _) { return _->Times(this); }
Node* Boolean::back_Times(Integer* _) { return _->Times(this); }
Node* Boolean::back_Times(Double* _) { return _->Times(this); }
Node* Boolean::back_Times(String* _) { return _->Times(this); }
Node* Boolean::back_Times(Array* _) { return _->Times(this); }
Node* Boolean::back_Times(Object* _) { return _->Times(this); }
Node* Boolean::back_Times(Function* _) { return _->Times(this); }
Node* Integer::Times(Node* _) { return _->back_Times(this); }
Node* Integer::back_Times(Error* _) { return _->Times(this); }
Node* Integer::back_Times(Member* _) { return _->Times(this); }
Node* Integer::back_Times(Boolean* _) { return _->Times(this); }
Node* Integer::back_Times(Integer* _) { return _->Times(this); }
Node* Integer::back_Times(Double* _) { return _->Times(this); }
Node* Integer::back_Times(String* _) { return _->Times(this); }
Node* Integer::back_Times(Array* _) { return _->Times(this); }
Node* Integer::back_Times(Object* _) { return _->Times(this); }
Node* Integer::back_Times(Function* _) { return _->Times(this); }
Node* Double::Times(Node* _) { return _->back_Times(this); }
Node* Double::back_Times(Error* _) { return _->Times(this); }
Node* Double::back_Times(Member* _) { return _->Times(this); }
Node* Double::back_Times(Boolean* _) { return _->Times(this); }
Node* Double::back_Times(Integer* _) { return _->Times(this); }
Node* Double::back_Times(Double* _) { return _->Times(this); }
Node* Double::back_Times(String* _) { return _->Times(this); }
Node* Double::back_Times(Array* _) { return _->Times(this); }
Node* Double::back_Times(Object* _) { return _->Times(this); }
Node* Double::back_Times(Function* _) { return _->Times(this); }
Node* String::Times(Node* _) { return _->back_Times(this); }
Node* String::back_Times(Error* _) { return _->Times(this); }
Node* String::back_Times(Member* _) { return _->Times(this); }
Node* String::back_Times(Boolean* _) { return _->Times(this); }
Node* String::back_Times(Integer* _) { return _->Times(this); }
Node* String::back_Times(Double* _) { return _->Times(this); }
Node* String::back_Times(String* _) { return _->Times(this); }
Node* String::back_Times(Array* _) { return _->Times(this); }
Node* String::back_Times(Object* _) { return _->Times(this); }
Node* String::back_Times(Function* _) { return _->Times(this); }
Node* Array::Times(Node* _) { return _->back_Times(this); }
Node* Array::back_Times(Error* _) { return _->Times(this); }
Node* Array::back_Times(Member* _) { return _->Times(this); }
Node* Array::back_Times(Boolean* _) { return _->Times(this); }
Node* Array::back_Times(Integer* _) { return _->Times(this); }
Node* Array::back_Times(Double* _) { return _->Times(this); }
Node* Array::back_Times(String* _) { return _->Times(this); }
Node* Array::back_Times(Array* _) { return _->Times(this); }
Node* Array::back_Times(Object* _) { return _->Times(this); }
Node* Array::back_Times(Function* _) { return _->Times(this); }
Node* Object::Times(Node* _) { return _->back_Times(this); }
Node* Object::back_Times(Error* _) { return _->Times(this); }
Node* Object::back_Times(Member* _) { return _->Times(this); }
Node* Object::back_Times(Boolean* _) { return _->Times(this); }
Node* Object::back_Times(Integer* _) { return _->Times(this); }
Node* Object::back_Times(Double* _) { return _->Times(this); }
Node* Object::back_Times(String* _) { return _->Times(this); }
Node* Object::back_Times(Array* _) { return _->Times(this); }
Node* Object::back_Times(Object* _) { return _->Times(this); }
Node* Object::back_Times(Function* _) { return _->Times(this); }
Node* Function::Times(Node* _) { return _->back_Times(this); }
Node* Function::back_Times(Error* _) { return _->Times(this); }
Node* Function::back_Times(Member* _) { return _->Times(this); }
Node* Function::back_Times(Boolean* _) { return _->Times(this); }
Node* Function::back_Times(Integer* _) { return _->Times(this); }
Node* Function::back_Times(Double* _) { return _->Times(this); }
Node* Function::back_Times(String* _) { return _->Times(this); }
Node* Function::back_Times(Array* _) { return _->Times(this); }
Node* Function::back_Times(Object* _) { return _->Times(this); }
Node* Function::back_Times(Function* _) { return _->Times(this); }
Node* Error::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Error::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Member::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Member::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Member::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* Member::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Member::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Member::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Member::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Member::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Member::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Member::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Boolean::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Boolean::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Integer::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Integer::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Double::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Double::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* String::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* String::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Array::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Array::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Object::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Object::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Function::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Function::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Member* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Error::Mod(Node* _) { return _->back_Mod(this); }
Node* Error::back_Mod(Error* _) { return _->Mod(this); }
Node* Error::back_Mod(Member* _) { return _->Mod(this); }
Node* Error::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Error::back_Mod(Integer* _) { return _->Mod(this); }
Node* Error::back_Mod(Double* _) { return _->Mod(this); }
Node* Error::back_Mod(String* _) { return _->Mod(this); }
Node* Error::back_Mod(Array* _) { return _->Mod(this); }
Node* Error::back_Mod(Object* _) { return _->Mod(this); }
Node* Error::back_Mod(Function* _) { return _->Mod(this); }
Node* Member::Mod(Node* _) { return _->back_Mod(this); }
Node* Member::back_Mod(Error* _) { return _->Mod(this); }
Node* Member::back_Mod(Member* _) { return _->Mod(this); }
Node* Member::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Member::back_Mod(Integer* _) { return _->Mod(this); }
Node* Member::back_Mod(Double* _) { return _->Mod(this); }
Node* Member::back_Mod(String* _) { return _->Mod(this); }
Node* Member::back_Mod(Array* _) { return _->Mod(this); }
Node* Member::back_Mod(Object* _) { return _->Mod(this); }
Node* Member::back_Mod(Function* _) { return _->Mod(this); }
Node* Boolean::Mod(Node* _) { return _->back_Mod(this); }
Node* Boolean::back_Mod(Error* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Member* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Integer* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Double* _) { return _->Mod(this); }
Node* Boolean::back_Mod(String* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Array* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Object* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Function* _) { return _->Mod(this); }
Node* Integer::Mod(Node* _) { return _->back_Mod(this); }
Node* Integer::back_Mod(Error* _) { return _->Mod(this); }
Node* Integer::back_Mod(Member* _) { return _->Mod(this); }
Node* Integer::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Integer::back_Mod(Integer* _) { return _->Mod(this); }
Node* Integer::back_Mod(Double* _) { return _->Mod(this); }
Node* Integer::back_Mod(String* _) { return _->Mod(this); }
Node* Integer::back_Mod(Array* _) { return _->Mod(this); }
Node* Integer::back_Mod(Object* _) { return _->Mod(this); }
Node* Integer::back_Mod(Function* _) { return _->Mod(this); }
Node* Double::Mod(Node* _) { return _->back_Mod(this); }
Node* Double::back_Mod(Error* _) { return _->Mod(this); }
Node* Double::back_Mod(Member* _) { return _->Mod(this); }
Node* Double::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Double::back_Mod(Integer* _) { return _->Mod(this); }
Node* Double::back_Mod(Double* _) { return _->Mod(this); }
Node* Double::back_Mod(String* _) { return _->Mod(this); }
Node* Double::back_Mod(Array* _) { return _->Mod(this); }
Node* Double::back_Mod(Object* _) { return _->Mod(this); }
Node* Double::back_Mod(Function* _) { return _->Mod(this); }
Node* String::Mod(Node* _) { return _->back_Mod(this); }
Node* String::back_Mod(Error* _) { return _->Mod(this); }
Node* String::back_Mod(Member* _) { return _->Mod(this); }
Node* String::back_Mod(Boolean* _) { return _->Mod(this); }
Node* String::back_Mod(Integer* _) { return _->Mod(this); }
Node* String::back_Mod(Double* _) { return _->Mod(this); }
Node* String::back_Mod(String* _) { return _->Mod(this); }
Node* String::back_Mod(Array* _) { return _->Mod(this); }
Node* String::back_Mod(Object* _) { return _->Mod(this); }
Node* String::back_Mod(Function* _) { return _->Mod(this); }
Node* Array::Mod(Node* _) { return _->back_Mod(this); }
Node* Array::back_Mod(Error* _) { return _->Mod(this); }
Node* Array::back_Mod(Member* _) { return _->Mod(this); }
Node* Array::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Array::back_Mod(Integer* _) { return _->Mod(this); }
Node* Array::back_Mod(Double* _) { return _->Mod(this); }
Node* Array::back_Mod(String* _) { return _->Mod(this); }
Node* Array::back_Mod(Array* _) { return _->Mod(this); }
Node* Array::back_Mod(Object* _) { return _->Mod(this); }
Node* Array::back_Mod(Function* _) { return _->Mod(this); }
Node* Object::Mod(Node* _) { return _->back_Mod(this); }
Node* Object::back_Mod(Error* _) { return _->Mod(this); }
Node* Object::back_Mod(Member* _) { return _->Mod(this); }
Node* Object::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Object::back_Mod(Integer* _) { return _->Mod(this); }
Node* Object::back_Mod(Double* _) { return _->Mod(this); }
Node* Object::back_Mod(String* _) { return _->Mod(this); }
Node* Object::back_Mod(Array* _) { return _->Mod(this); }
Node* Object::back_Mod(Object* _) { return _->Mod(this); }
Node* Object::back_Mod(Function* _) { return _->Mod(this); }
Node* Function::Mod(Node* _) { return _->back_Mod(this); }
Node* Function::back_Mod(Error* _) { return _->Mod(this); }
Node* Function::back_Mod(Member* _) { return _->Mod(this); }
Node* Function::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Function::back_Mod(Integer* _) { return _->Mod(this); }
Node* Function::back_Mod(Double* _) { return _->Mod(this); }
Node* Function::back_Mod(String* _) { return _->Mod(this); }
Node* Function::back_Mod(Array* _) { return _->Mod(this); }
Node* Function::back_Mod(Object* _) { return _->Mod(this); }
Node* Function::back_Mod(Function* _) { return _->Mod(this); }
Node* Error::Call(Node* _) { return _->back_Call(this); }
Node* Error::back_Call(Error* _) { return _->Call(this); }
Node* Error::back_Call(Member* _) { return _->Call(this); }
Node* Error::back_Call(Boolean* _) { return _->Call(this); }
Node* Error::back_Call(Integer* _) { return _->Call(this); }
Node* Error::back_Call(Double* _) { return _->Call(this); }
Node* Error::back_Call(String* _) { return _->Call(this); }
Node* Error::back_Call(Array* _) { return _->Call(this); }
Node* Error::back_Call(Object* _) { return _->Call(this); }
Node* Error::back_Call(Function* _) { return _->Call(this); }
Node* Member::Call(Node* _) { return _->back_Call(this); }
Node* Member::back_Call(Error* _) { return _->Call(this); }
Node* Member::back_Call(Member* _) { return _->Call(this); }
Node* Member::back_Call(Boolean* _) { return _->Call(this); }
Node* Member::back_Call(Integer* _) { return _->Call(this); }
Node* Member::back_Call(Double* _) { return _->Call(this); }
Node* Member::back_Call(String* _) { return _->Call(this); }
Node* Member::back_Call(Array* _) { return _->Call(this); }
Node* Member::back_Call(Object* _) { return _->Call(this); }
Node* Member::back_Call(Function* _) { return _->Call(this); }
Node* Boolean::Call(Node* _) { return _->back_Call(this); }
Node* Boolean::back_Call(Error* _) { return _->Call(this); }
Node* Boolean::back_Call(Member* _) { return _->Call(this); }
Node* Boolean::back_Call(Boolean* _) { return _->Call(this); }
Node* Boolean::back_Call(Integer* _) { return _->Call(this); }
Node* Boolean::back_Call(Double* _) { return _->Call(this); }
Node* Boolean::back_Call(String* _) { return _->Call(this); }
Node* Boolean::back_Call(Array* _) { return _->Call(this); }
Node* Boolean::back_Call(Object* _) { return _->Call(this); }
Node* Boolean::back_Call(Function* _) { return _->Call(this); }
Node* Integer::Call(Node* _) { return _->back_Call(this); }
Node* Integer::back_Call(Error* _) { return _->Call(this); }
Node* Integer::back_Call(Member* _) { return _->Call(this); }
Node* Integer::back_Call(Boolean* _) { return _->Call(this); }
Node* Integer::back_Call(Integer* _) { return _->Call(this); }
Node* Integer::back_Call(Double* _) { return _->Call(this); }
Node* Integer::back_Call(String* _) { return _->Call(this); }
Node* Integer::back_Call(Array* _) { return _->Call(this); }
Node* Integer::back_Call(Object* _) { return _->Call(this); }
Node* Integer::back_Call(Function* _) { return _->Call(this); }
Node* Double::Call(Node* _) { return _->back_Call(this); }
Node* Double::back_Call(Error* _) { return _->Call(this); }
Node* Double::back_Call(Member* _) { return _->Call(this); }
Node* Double::back_Call(Boolean* _) { return _->Call(this); }
Node* Double::back_Call(Integer* _) { return _->Call(this); }
Node* Double::back_Call(Double* _) { return _->Call(this); }
Node* Double::back_Call(String* _) { return _->Call(this); }
Node* Double::back_Call(Array* _) { return _->Call(this); }
Node* Double::back_Call(Object* _) { return _->Call(this); }
Node* Double::back_Call(Function* _) { return _->Call(this); }
Node* String::Call(Node* _) { return _->back_Call(this); }
Node* String::back_Call(Error* _) { return _->Call(this); }
Node* String::back_Call(Member* _) { return _->Call(this); }
Node* String::back_Call(Boolean* _) { return _->Call(this); }
Node* String::back_Call(Integer* _) { return _->Call(this); }
Node* String::back_Call(Double* _) { return _->Call(this); }
Node* String::back_Call(String* _) { return _->Call(this); }
Node* String::back_Call(Array* _) { return _->Call(this); }
Node* String::back_Call(Object* _) { return _->Call(this); }
Node* String::back_Call(Function* _) { return _->Call(this); }
Node* Array::Call(Node* _) { return _->back_Call(this); }
Node* Array::back_Call(Error* _) { return _->Call(this); }
Node* Array::back_Call(Member* _) { return _->Call(this); }
Node* Array::back_Call(Boolean* _) { return _->Call(this); }
Node* Array::back_Call(Integer* _) { return _->Call(this); }
Node* Array::back_Call(Double* _) { return _->Call(this); }
Node* Array::back_Call(String* _) { return _->Call(this); }
Node* Array::back_Call(Array* _) { return _->Call(this); }
Node* Array::back_Call(Object* _) { return _->Call(this); }
Node* Array::back_Call(Function* _) { return _->Call(this); }
Node* Object::Call(Node* _) { return _->back_Call(this); }
Node* Object::back_Call(Error* _) { return _->Call(this); }
Node* Object::back_Call(Member* _) { return _->Call(this); }
Node* Object::back_Call(Boolean* _) { return _->Call(this); }
Node* Object::back_Call(Integer* _) { return _->Call(this); }
Node* Object::back_Call(Double* _) { return _->Call(this); }
Node* Object::back_Call(String* _) { return _->Call(this); }
Node* Object::back_Call(Array* _) { return _->Call(this); }
Node* Object::back_Call(Object* _) { return _->Call(this); }
Node* Object::back_Call(Function* _) { return _->Call(this); }
Node* Function::Call(Node* _) { return _->back_Call(this); }
Node* Function::back_Call(Error* _) { return _->Call(this); }
Node* Function::back_Call(Member* _) { return _->Call(this); }
Node* Function::back_Call(Boolean* _) { return _->Call(this); }
Node* Function::back_Call(Integer* _) { return _->Call(this); }
Node* Function::back_Call(Double* _) { return _->Call(this); }
Node* Function::back_Call(String* _) { return _->Call(this); }
Node* Function::back_Call(Array* _) { return _->Call(this); }
Node* Function::back_Call(Object* _) { return _->Call(this); }
Node* Function::back_Call(Function* _) { return _->Call(this); }
Node* Error::Equals(Node* _) { return _->back_Equals(this); }
Node* Error::back_Equals(Error* _) { return _->Equals(this); }
Node* Error::back_Equals(Member* _) { return _->Equals(this); }
Node* Error::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Error::back_Equals(Integer* _) { return _->Equals(this); }
Node* Error::back_Equals(Double* _) { return _->Equals(this); }
Node* Error::back_Equals(String* _) { return _->Equals(this); }
Node* Error::back_Equals(Array* _) { return _->Equals(this); }
Node* Error::back_Equals(Object* _) { return _->Equals(this); }
Node* Error::back_Equals(Function* _) { return _->Equals(this); }
Node* Member::Equals(Node* _) { return _->back_Equals(this); }
Node* Member::back_Equals(Error* _) { return _->Equals(this); }
Node* Member::back_Equals(Member* _) { return _->Equals(this); }
Node* Member::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Member::back_Equals(Integer* _) { return _->Equals(this); }
Node* Member::back_Equals(Double* _) { return _->Equals(this); }
Node* Member::back_Equals(String* _) { return _->Equals(this); }
Node* Member::back_Equals(Array* _) { return _->Equals(this); }
Node* Member::back_Equals(Object* _) { return _->Equals(this); }
Node* Member::back_Equals(Function* _) { return _->Equals(this); }
Node* Boolean::Equals(Node* _) { return _->back_Equals(this); }
Node* Boolean::back_Equals(Error* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Member* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Integer* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Double* _) { return _->Equals(this); }
Node* Boolean::back_Equals(String* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Array* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Object* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Function* _) { return _->Equals(this); }
Node* Integer::Equals(Node* _) { return _->back_Equals(this); }
Node* Integer::back_Equals(Error* _) { return _->Equals(this); }
Node* Integer::back_Equals(Member* _) { return _->Equals(this); }
Node* Integer::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Integer::back_Equals(Integer* _) { return _->Equals(this); }
Node* Integer::back_Equals(Double* _) { return _->Equals(this); }
Node* Integer::back_Equals(String* _) { return _->Equals(this); }
Node* Integer::back_Equals(Array* _) { return _->Equals(this); }
Node* Integer::back_Equals(Object* _) { return _->Equals(this); }
Node* Integer::back_Equals(Function* _) { return _->Equals(this); }
Node* Double::Equals(Node* _) { return _->back_Equals(this); }
Node* Double::back_Equals(Error* _) { return _->Equals(this); }
Node* Double::back_Equals(Member* _) { return _->Equals(this); }
Node* Double::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Double::back_Equals(Integer* _) { return _->Equals(this); }
Node* Double::back_Equals(Double* _) { return _->Equals(this); }
Node* Double::back_Equals(String* _) { return _->Equals(this); }
Node* Double::back_Equals(Array* _) { return _->Equals(this); }
Node* Double::back_Equals(Object* _) { return _->Equals(this); }
Node* Double::back_Equals(Function* _) { return _->Equals(this); }
Node* String::Equals(Node* _) { return _->back_Equals(this); }
Node* String::back_Equals(Error* _) { return _->Equals(this); }
Node* String::back_Equals(Member* _) { return _->Equals(this); }
Node* String::back_Equals(Boolean* _) { return _->Equals(this); }
Node* String::back_Equals(Integer* _) { return _->Equals(this); }
Node* String::back_Equals(Double* _) { return _->Equals(this); }
Node* String::back_Equals(String* _) { return _->Equals(this); }
Node* String::back_Equals(Array* _) { return _->Equals(this); }
Node* String::back_Equals(Object* _) { return _->Equals(this); }
Node* String::back_Equals(Function* _) { return _->Equals(this); }
Node* Array::Equals(Node* _) { return _->back_Equals(this); }
Node* Array::back_Equals(Error* _) { return _->Equals(this); }
Node* Array::back_Equals(Member* _) { return _->Equals(this); }
Node* Array::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Array::back_Equals(Integer* _) { return _->Equals(this); }
Node* Array::back_Equals(Double* _) { return _->Equals(this); }
Node* Array::back_Equals(String* _) { return _->Equals(this); }
Node* Array::back_Equals(Array* _) { return _->Equals(this); }
Node* Array::back_Equals(Object* _) { return _->Equals(this); }
Node* Array::back_Equals(Function* _) { return _->Equals(this); }
Node* Object::Equals(Node* _) { return _->back_Equals(this); }
Node* Object::back_Equals(Error* _) { return _->Equals(this); }
Node* Object::back_Equals(Member* _) { return _->Equals(this); }
Node* Object::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Object::back_Equals(Integer* _) { return _->Equals(this); }
Node* Object::back_Equals(Double* _) { return _->Equals(this); }
Node* Object::back_Equals(String* _) { return _->Equals(this); }
Node* Object::back_Equals(Array* _) { return _->Equals(this); }
Node* Object::back_Equals(Object* _) { return _->Equals(this); }
Node* Object::back_Equals(Function* _) { return _->Equals(this); }
Node* Function::Equals(Node* _) { return _->back_Equals(this); }
Node* Function::back_Equals(Error* _) { return _->Equals(this); }
Node* Function::back_Equals(Member* _) { return _->Equals(this); }
Node* Function::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Function::back_Equals(Integer* _) { return _->Equals(this); }
Node* Function::back_Equals(Double* _) { return _->Equals(this); }
Node* Function::back_Equals(String* _) { return _->Equals(this); }
Node* Function::back_Equals(Array* _) { return _->Equals(this); }
Node* Function::back_Equals(Object* _) { return _->Equals(this); }
Node* Function::back_Equals(Function* _) { return _->Equals(this); }
Node* Error::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Error::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Member::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Member::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Member::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* Member::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Member::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Member::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Member::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Member::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Member::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Member::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Boolean::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Boolean::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Integer::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Integer::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Double::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Double::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* String::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* String::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Array::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Array::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Object::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Object::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Function::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Function::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Member* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Error::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Error::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Member* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Error::back_LessThan(String* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Member::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Member::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Member::back_LessThan(Member* _) { return _->LessThan(this); }
Node* Member::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Member::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Member::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Member::back_LessThan(String* _) { return _->LessThan(this); }
Node* Member::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Member::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Member::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Boolean::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Boolean::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Member* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(String* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Integer::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Integer::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Member* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(String* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Double::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Double::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Member* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Double::back_LessThan(String* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Function* _) { return _->LessThan(this); }
Node* String::LessThan(Node* _) { return _->back_LessThan(this); }
Node* String::back_LessThan(Error* _) { return _->LessThan(this); }
Node* String::back_LessThan(Member* _) { return _->LessThan(this); }
Node* String::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* String::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* String::back_LessThan(Double* _) { return _->LessThan(this); }
Node* String::back_LessThan(String* _) { return _->LessThan(this); }
Node* String::back_LessThan(Array* _) { return _->LessThan(this); }
Node* String::back_LessThan(Object* _) { return _->LessThan(this); }
Node* String::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Array::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Array::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Member* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Array::back_LessThan(String* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Object::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Object::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Member* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Object::back_LessThan(String* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Function::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Function::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Member* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Function::back_LessThan(String* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Error::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Error::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Member::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Member::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Member::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* Member::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Member::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Member::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Member::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Member::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Member::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Member::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Boolean::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Boolean::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Integer::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Integer::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Double::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Double::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* String::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* String::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Array::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Array::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Object::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Object::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Function::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Function::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Member* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Error::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Member::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Member::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Double::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* String::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Array::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Object::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Function::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Member* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Error::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Member::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Member* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }

}