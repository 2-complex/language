#include "objects.h"

namespace object
{
Node::~Node()
{
}

std::string Node::toString() const
{
    return "STANDIN STRING";
}

bool Node::isTrue() const
{
    return false;
}

void Node::setMember(const std::string& name, object::Node* value)
{
}

object::Node* Node::getMember(const std::string& name)
{
    PLACEHOLDER
}

void Node::setMapping(object::Node* key, object::Node* value)
{
}

object::Node* Node::getMapping(object::Node* key)
{
    PLACEHOLDER
}

std::string Error::toString() const
{
    return "ERROR: " + message;
}

Error::Error()
    : message("SOME ERROR.  PLEASE REPLACE WITH MEANINGFUL MESSAGE.")
{
}

Error::Error(const std::string& message)
    : message(message)
{
}

int Error::typeComparor() const
{
    return -1;
}

Node* Error::Negation()
{
    return this;
}

Node* Error::Negative()
{
    return this;
}

Node* Error::And(Error* _)
{
    return _;
}

Node* Error::And(Boolean* _)
{
    return this;
}

Node* Error::And(Integer* _)
{
    return this;
}

Node* Error::And(Double* _)
{
    return this;
}

Node* Error::And(String* _)
{
    return this;
}

Node* Error::And(Array* _)
{
    return this;
}

Node* Error::And(Object* _)
{
    return this;
}

Node* Error::And(Function* _)
{
    return this;
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

int Boolean::typeComparor() const
{
    return 0;
}

Node* Boolean::Negation()
{
    return new Boolean(!value);
}

Node* Boolean::Negative()
{
    PLACEHOLDER
}

Node* Boolean::And(Error* _)
{
    return _;
}

Node* Boolean::And(Boolean* _)
{
    return new Boolean(value && _->value);
}

Node* Boolean::And(Integer* _)
{
    PLACEHOLDER
}

Node* Boolean::And(Double* _)
{
    PLACEHOLDER
}

Node* Boolean::And(String* _)
{
    PLACEHOLDER
}

Node* Boolean::And(Array* _)
{
    PLACEHOLDER
}

Node* Boolean::And(Object* _)
{
    PLACEHOLDER
}

Node* Boolean::And(Function* _)
{
    PLACEHOLDER
}

Integer::Integer(int value)
    : value(value)
{
}

Integer::Integer(const std::string& text)
{
    value = atoi(text.c_str());
}

int Integer::getValue()
{
    return value;
}

std::string Integer::toString() const
{
    return std::to_string(value);
}

int Integer::typeComparor() const
{
    return 1;
}

Node* Integer::Negation()
{
    PLACEHOLDER
}

Node* Integer::Negative()
{
    return new Integer(-value);
}

Node* Integer::And(Error* _)
{
    return _;
}

Node* Integer::And(Boolean* _)
{
    PLACEHOLDER
}

Node* Integer::And(Integer* _)
{
    PLACEHOLDER
}

Node* Integer::And(Double* _)
{
    PLACEHOLDER
}

Node* Integer::And(String* _)
{
    PLACEHOLDER
}

Node* Integer::And(Array* _)
{
    PLACEHOLDER
}

Node* Integer::And(Object* _)
{
    PLACEHOLDER
}

Node* Integer::And(Function* _)
{
    PLACEHOLDER
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

int Double::typeComparor() const
{
    return 1;
}

Node* Double::Negation()
{
    PLACEHOLDER
}

Node* Double::Negative()
{
    return new Double(-value);
}

Node* Double::And(Error* _)
{
    return _;
}

Node* Double::And(Boolean* _)
{
    PLACEHOLDER
}

Node* Double::And(Integer* _)
{
    PLACEHOLDER
}

Node* Double::And(Double* _)
{
    PLACEHOLDER
}

Node* Double::And(String* _)
{
    PLACEHOLDER
}

Node* Double::And(Array* _)
{
    PLACEHOLDER
}

Node* Double::And(Object* _)
{
    PLACEHOLDER
}

Node* Double::And(Function* _)
{
    PLACEHOLDER
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

int String::typeComparor() const
{
    return 2;
}

Node* String::Negation()
{
    PLACEHOLDER
}

Node* String::Negative()
{
    PLACEHOLDER
}

Node* String::And(Error* _)
{
    return _;
}

Node* String::And(Boolean* _)
{
    PLACEHOLDER
}

Node* String::And(Integer* _)
{
    PLACEHOLDER
}

Node* String::And(Double* _)
{
    PLACEHOLDER
}

Node* String::And(String* _)
{
    PLACEHOLDER
}

Node* String::And(Array* _)
{
    PLACEHOLDER
}

Node* String::And(Object* _)
{
    PLACEHOLDER
}

Node* String::And(Function* _)
{
    PLACEHOLDER
}

const std::vector<Node*>& Array::getValue()
{
    return value;
}

std::string Array::toString() const
{
    std::string result = "[";
    for( Node* node : value )
    {
        result += node->toString() + ",";
    }
    result += "]";
    return result;
}

void Array::append(Node* node)
{
    value.push_back(node);
}

int Array::typeComparor() const
{
    return 3;
}

Node* Array::Negation()
{
    PLACEHOLDER
}

Node* Array::Negative()
{
    PLACEHOLDER
}

Node* Array::And(Error* _)
{
    return _;
}

Node* Array::And(Boolean* _)
{
    PLACEHOLDER
}

Node* Array::And(Integer* _)
{
    PLACEHOLDER
}

Node* Array::And(Double* _)
{
    PLACEHOLDER
}

Node* Array::And(String* _)
{
    PLACEHOLDER
}

Node* Array::And(Array* _)
{
    PLACEHOLDER
}

Node* Array::And(Object* _)
{
    PLACEHOLDER
}

Node* Array::And(Function* _)
{
    PLACEHOLDER
}

Key::Key(Node* node)
    : node(node)
{
}

bool Key::operator == (const class Key& other) const
{
    Node* temp = node->Equals(other.node);
    bool result = temp->isTrue();
    delete temp;
    return result;
}

bool Key::operator < (const class Key& other) const
{
    Node* temp = node->LessThan(other.node);
    bool result = temp->isTrue();
    delete temp;
    return result;
}

std::pair<
    std::map<std::string, Node*>,
    std::map<Key, Node*> > Object::getValue()
{
    return std::pair<
        std::map<std::string, Node*>,
        std::map<Key, Node*> >( members, mappings );
}

void Object::setMember(const std::string& name, object::Node* value)
{
    members[name] = value;
}

object::Node* Object::getMember(const std::string& name)
{
    auto itr = members.find(name);
    if( itr == members.end() )
    {
        PLACEHOLDER
    }
    return itr->second;
}

void Object::setMapping(Node* key, Node* value)
{
    mappings[Key(key)] = value;
}

Node* Object::getMapping(Node* key)
{
    auto itr = mappings.find(key);

    if( itr == mappings.end() )
    {
        return new Object;
    }

    return itr->second;
}

int Object::typeComparor() const
{
    return 4;
}

Node* Object::Negation()
{
    PLACEHOLDER
}

Node* Object::Negative()
{
    PLACEHOLDER
}

Node* Object::And(Error* _)
{
    return _;
}

Node* Object::And(Boolean* _)
{
    PLACEHOLDER
}

Node* Object::And(Integer* _)
{
    PLACEHOLDER
}

Node* Object::And(Double* _)
{
    PLACEHOLDER
}

Node* Object::And(String* _)
{
    PLACEHOLDER
}

Node* Object::And(Array* _)
{
    PLACEHOLDER
}

Node* Object::And(Object* _)
{
    PLACEHOLDER
}

Node* Object::And(Function* _)
{
    PLACEHOLDER
}

std::string Function::getValue()
{
    return toString();
}

int Function::typeComparor() const
{
    return 5;
}

Node* Function::Negation()
{
    PLACEHOLDER
}

Node* Function::Negative()
{
    PLACEHOLDER
}

Node* Function::And(Error* _)
{
    return _;
}

Node* Function::And(Boolean* _)
{
    PLACEHOLDER
}

Node* Function::And(Integer* _)
{
    PLACEHOLDER
}

Node* Function::And(Double* _)
{
    PLACEHOLDER
}

Node* Function::And(String* _)
{
    PLACEHOLDER
}

Node* Function::And(Array* _)
{
    PLACEHOLDER
}

Node* Function::And(Object* _)
{
    PLACEHOLDER
}

Node* Function::And(Function* _)
{
    PLACEHOLDER
}

Node* Error::Or(Error* _)
{
    return _;
}

Node* Error::Or(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::Or(Integer* _)
{
    PLACEHOLDER
}

Node* Error::Or(Double* _)
{
    PLACEHOLDER
}

Node* Error::Or(String* _)
{
    PLACEHOLDER
}

Node* Error::Or(Array* _)
{
    PLACEHOLDER
}

Node* Error::Or(Object* _)
{
    PLACEHOLDER
}

Node* Error::Or(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::Or(Error* _)
{
    return _;
}

Node* Boolean::Or(Boolean* _)
{
    return new Boolean(value || _->value);
}

Node* Boolean::Or(Integer* _)
{
    PLACEHOLDER
}

Node* Boolean::Or(Double* _)
{
    PLACEHOLDER
}

Node* Boolean::Or(String* _)
{
    PLACEHOLDER
}

Node* Boolean::Or(Array* _)
{
    PLACEHOLDER
}

Node* Boolean::Or(Object* _)
{
    PLACEHOLDER
}

Node* Boolean::Or(Function* _)
{
    PLACEHOLDER
}

Node* Integer::Or(Error* _)
{
    return _;
}

Node* Integer::Or(Boolean* _)
{
    PLACEHOLDER
}

Node* Integer::Or(Integer* _)
{
    PLACEHOLDER
}

Node* Integer::Or(Double* _)
{
    PLACEHOLDER
}

Node* Integer::Or(String* _)
{
    PLACEHOLDER
}

Node* Integer::Or(Array* _)
{
    PLACEHOLDER
}

Node* Integer::Or(Object* _)
{
    PLACEHOLDER
}

Node* Integer::Or(Function* _)
{
    PLACEHOLDER
}

Node* Double::Or(Error* _)
{
    return _;
}

Node* Double::Or(Boolean* _)
{
    PLACEHOLDER
}

Node* Double::Or(Integer* _)
{
    PLACEHOLDER
}

Node* Double::Or(Double* _)
{
    PLACEHOLDER
}

Node* Double::Or(String* _)
{
    PLACEHOLDER
}

Node* Double::Or(Array* _)
{
    PLACEHOLDER
}

Node* Double::Or(Object* _)
{
    PLACEHOLDER
}

Node* Double::Or(Function* _)
{
    PLACEHOLDER
}

Node* String::Or(Error* _)
{
    return _;
}

Node* String::Or(Boolean* _)
{
    PLACEHOLDER
}

Node* String::Or(Integer* _)
{
    PLACEHOLDER
}

Node* String::Or(Double* _)
{
    PLACEHOLDER
}

Node* String::Or(String* _)
{
    PLACEHOLDER
}

Node* String::Or(Array* _)
{
    PLACEHOLDER
}

Node* String::Or(Object* _)
{
    PLACEHOLDER
}

Node* String::Or(Function* _)
{
    PLACEHOLDER
}

Node* Array::Or(Error* _)
{
    return _;
}

Node* Array::Or(Boolean* _)
{
    PLACEHOLDER
}

Node* Array::Or(Integer* _)
{
    PLACEHOLDER
}

Node* Array::Or(Double* _)
{
    PLACEHOLDER
}

Node* Array::Or(String* _)
{
    PLACEHOLDER
}

Node* Array::Or(Array* _)
{
    PLACEHOLDER
}

Node* Array::Or(Object* _)
{
    PLACEHOLDER
}

Node* Array::Or(Function* _)
{
    PLACEHOLDER
}

Node* Object::Or(Error* _)
{
    return _;
}

Node* Object::Or(Boolean* _)
{
    PLACEHOLDER
}

Node* Object::Or(Integer* _)
{
    PLACEHOLDER
}

Node* Object::Or(Double* _)
{
    PLACEHOLDER
}

Node* Object::Or(String* _)
{
    PLACEHOLDER
}

Node* Object::Or(Array* _)
{
    PLACEHOLDER
}

Node* Object::Or(Object* _)
{
    PLACEHOLDER
}

Node* Object::Or(Function* _)
{
    PLACEHOLDER
}

Node* Function::Or(Error* _)
{
    return _;
}

Node* Function::Or(Boolean* _)
{
    PLACEHOLDER
}

Node* Function::Or(Integer* _)
{
    PLACEHOLDER
}

Node* Function::Or(Double* _)
{
    PLACEHOLDER
}

Node* Function::Or(String* _)
{
    PLACEHOLDER
}

Node* Function::Or(Array* _)
{
    PLACEHOLDER
}

Node* Function::Or(Object* _)
{
    PLACEHOLDER
}

Node* Function::Or(Function* _)
{
    PLACEHOLDER
}

Node* Error::Plus(Error* _)
{
    return _;
}

Node* Error::Plus(Boolean* _)
{
    return this;
}

Node* Error::Plus(Integer* _)
{
    return this;
}

Node* Error::Plus(Double* _)
{
    return this;
}

Node* Error::Plus(String* _)
{
    return this;
}

Node* Error::Plus(Array* _)
{
    return this;
}

Node* Error::Plus(Object* _)
{
    return this;
}

Node* Error::Plus(Function* _)
{
    return this;
}

Node* Boolean::Plus(Error* _)
{
    return _;
}

Node* Boolean::Plus(Boolean* _)
{
    PLACEHOLDER
}

Node* Boolean::Plus(Integer* _)
{
    PLACEHOLDER
}

Node* Boolean::Plus(Double* _)
{
    PLACEHOLDER
}

Node* Boolean::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Boolean::Plus(Array* _)
{
    PLACEHOLDER
}

Node* Boolean::Plus(Object* _)
{
    PLACEHOLDER
}

Node* Boolean::Plus(Function* _)
{
    PLACEHOLDER
}

Node* Integer::Plus(Error* _)
{
    return _;
}

Node* Integer::Plus(Boolean* _)
{
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Integer::Plus(Object* _)
{
    PLACEHOLDER
}

Node* Integer::Plus(Function* _)
{
    PLACEHOLDER
}

Node* Double::Plus(Error* _)
{
    return _;
}

Node* Double::Plus(Boolean* _)
{
    PLACEHOLDER
}

Node* Double::Plus(Integer* _)
{
    return new Double(value + _->getValue());
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
    PLACEHOLDER
}

Node* Double::Plus(Object* _)
{
    PLACEHOLDER
}

Node* Double::Plus(Function* _)
{
    PLACEHOLDER
}

Node* String::Plus(Error* _)
{
    return _;
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
    return _;
}

Node* Array::Plus(Boolean* _)
{
    PLACEHOLDER
}

Node* Array::Plus(Integer* _)
{
    PLACEHOLDER
}

Node* Array::Plus(Double* _)
{
    PLACEHOLDER
}

Node* Array::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Array::Plus(Array* _)
{
    Array* array = new Array;

    for (Node* node : value)
        array->append(node);

    for (Node* node : _->value)
        array->append(node);

    return array;
}

Node* Array::Plus(Object* _)
{
    PLACEHOLDER
}

Node* Array::Plus(Function* _)
{
    PLACEHOLDER
}

Node* Object::Plus(Error* _)
{
    return _;
}

Node* Object::Plus(Boolean* _)
{
    PLACEHOLDER
}

Node* Object::Plus(Integer* _)
{
    PLACEHOLDER
}

Node* Object::Plus(Double* _)
{
    PLACEHOLDER
}

Node* Object::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Object::Plus(Array* _)
{
    PLACEHOLDER
}

Node* Object::Plus(Object* _)
{
    PLACEHOLDER
}

Node* Object::Plus(Function* _)
{
    PLACEHOLDER
}

Node* Function::Plus(Error* _)
{
    return _;
}

Node* Function::Plus(Boolean* _)
{
    PLACEHOLDER
}

Node* Function::Plus(Integer* _)
{
    PLACEHOLDER
}

Node* Function::Plus(Double* _)
{
    PLACEHOLDER
}

Node* Function::Plus(String* _)
{
    return new String(toString() + _->getValue());
}

Node* Function::Plus(Array* _)
{
    PLACEHOLDER
}

Node* Function::Plus(Object* _)
{
    PLACEHOLDER
}

Node* Function::Plus(Function* _)
{
    PLACEHOLDER
}

Node* Error::Minus(Error* _)
{
    return _;
}

Node* Error::Minus(Boolean* _)
{
    return this;
}

Node* Error::Minus(Integer* _)
{
    return this;
}

Node* Error::Minus(Double* _)
{
    return this;
}

Node* Error::Minus(String* _)
{
    return this;
}

Node* Error::Minus(Array* _)
{
    return this;
}

Node* Error::Minus(Object* _)
{
    return this;
}

Node* Error::Minus(Function* _)
{
    return this;
}

Node* Boolean::Minus(Error* _)
{
    return _;
}

Node* Boolean::Minus(Boolean* _)
{
    PLACEHOLDER
}

Node* Boolean::Minus(Integer* _)
{
    PLACEHOLDER
}

Node* Boolean::Minus(Double* _)
{
    PLACEHOLDER
}

Node* Boolean::Minus(String* _)
{
    PLACEHOLDER
}

Node* Boolean::Minus(Array* _)
{
    PLACEHOLDER
}

Node* Boolean::Minus(Object* _)
{
    PLACEHOLDER
}

Node* Boolean::Minus(Function* _)
{
    PLACEHOLDER
}

Node* Integer::Minus(Error* _)
{
    return _;
}

Node* Integer::Minus(Boolean* _)
{
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Integer::Minus(Array* _)
{
    PLACEHOLDER
}

Node* Integer::Minus(Object* _)
{
    PLACEHOLDER
}

Node* Integer::Minus(Function* _)
{
    PLACEHOLDER
}

Node* Double::Minus(Error* _)
{
    return _;
}

Node* Double::Minus(Boolean* _)
{
    PLACEHOLDER
}

Node* Double::Minus(Integer* _)
{
    return new Double(value - _->getValue());
}

Node* Double::Minus(Double* _)
{
    return new Double(value - _->value);
}

Node* Double::Minus(String* _)
{
    PLACEHOLDER
}

Node* Double::Minus(Array* _)
{
    PLACEHOLDER
}

Node* Double::Minus(Object* _)
{
    PLACEHOLDER
}

Node* Double::Minus(Function* _)
{
    PLACEHOLDER
}

Node* String::Minus(Error* _)
{
    return _;
}

Node* String::Minus(Boolean* _)
{
    PLACEHOLDER
}

Node* String::Minus(Integer* _)
{
    PLACEHOLDER
}

Node* String::Minus(Double* _)
{
    PLACEHOLDER
}

Node* String::Minus(String* _)
{
    PLACEHOLDER
}

Node* String::Minus(Array* _)
{
    PLACEHOLDER
}

Node* String::Minus(Object* _)
{
    PLACEHOLDER
}

Node* String::Minus(Function* _)
{
    PLACEHOLDER
}

Node* Array::Minus(Error* _)
{
    return _;
}

Node* Array::Minus(Boolean* _)
{
    PLACEHOLDER
}

Node* Array::Minus(Integer* _)
{
    PLACEHOLDER
}

Node* Array::Minus(Double* _)
{
    PLACEHOLDER
}

Node* Array::Minus(String* _)
{
    PLACEHOLDER
}

Node* Array::Minus(Array* _)
{
    PLACEHOLDER
}

Node* Array::Minus(Object* _)
{
    PLACEHOLDER
}

Node* Array::Minus(Function* _)
{
    PLACEHOLDER
}

Node* Object::Minus(Error* _)
{
    return _;
}

Node* Object::Minus(Boolean* _)
{
    PLACEHOLDER
}

Node* Object::Minus(Integer* _)
{
    PLACEHOLDER
}

Node* Object::Minus(Double* _)
{
    PLACEHOLDER
}

Node* Object::Minus(String* _)
{
    PLACEHOLDER
}

Node* Object::Minus(Array* _)
{
    PLACEHOLDER
}

Node* Object::Minus(Object* _)
{
    PLACEHOLDER
}

Node* Object::Minus(Function* _)
{
    PLACEHOLDER
}

Node* Function::Minus(Error* _)
{
    return _;
}

Node* Function::Minus(Boolean* _)
{
    PLACEHOLDER
}

Node* Function::Minus(Integer* _)
{
    PLACEHOLDER
}

Node* Function::Minus(Double* _)
{
    PLACEHOLDER
}

Node* Function::Minus(String* _)
{
    PLACEHOLDER
}

Node* Function::Minus(Array* _)
{
    PLACEHOLDER
}

Node* Function::Minus(Object* _)
{
    PLACEHOLDER
}

Node* Function::Minus(Function* _)
{
    PLACEHOLDER
}

Node* Error::Times(Error* _)
{
    return this;
}

Node* Error::Times(Boolean* _)
{
    return this;
}

Node* Error::Times(Integer* _)
{
    return this;
}

Node* Error::Times(Double* _)
{
    return this;
}

Node* Error::Times(String* _)
{
    return this;
}

Node* Error::Times(Array* _)
{
    return this;
}

Node* Error::Times(Object* _)
{
    return this;
}

Node* Error::Times(Function* _)
{
    return this;
}

Node* Boolean::Times(Error* _)
{
    return _;
}

Node* Boolean::Times(Boolean* _)
{
    PLACEHOLDER
}

Node* Boolean::Times(Integer* _)
{
    PLACEHOLDER
}

Node* Boolean::Times(Double* _)
{
    PLACEHOLDER
}

Node* Boolean::Times(String* _)
{
    PLACEHOLDER
}

Node* Boolean::Times(Array* _)
{
    PLACEHOLDER
}

Node* Boolean::Times(Object* _)
{
    PLACEHOLDER
}

Node* Boolean::Times(Function* _)
{
    PLACEHOLDER
}

Node* Integer::Times(Error* _)
{
    return _;
}

Node* Integer::Times(Boolean* _)
{
    PLACEHOLDER
}

Node* Integer::Times(Integer* _)
{
    return new Integer(value * _->value);
}

Node* Integer::Times(Double* _)
{
    PLACEHOLDER
}

Node* Integer::Times(String* _)
{
    PLACEHOLDER
}

Node* Integer::Times(Array* _)
{
    PLACEHOLDER
}

Node* Integer::Times(Object* _)
{
    PLACEHOLDER
}

Node* Integer::Times(Function* _)
{
    PLACEHOLDER
}

Node* Double::Times(Error* _)
{
    return _;
}

Node* Double::Times(Boolean* _)
{
    PLACEHOLDER
}

Node* Double::Times(Integer* _)
{
    PLACEHOLDER
}

Node* Double::Times(Double* _)
{
    PLACEHOLDER
}

Node* Double::Times(String* _)
{
    PLACEHOLDER
}

Node* Double::Times(Array* _)
{
    PLACEHOLDER
}

Node* Double::Times(Object* _)
{
    PLACEHOLDER
}

Node* Double::Times(Function* _)
{
    PLACEHOLDER
}

Node* String::Times(Error* _)
{
    return _;
}

Node* String::Times(Boolean* _)
{
    PLACEHOLDER
}

Node* String::Times(Integer* _)
{
    PLACEHOLDER
}

Node* String::Times(Double* _)
{
    PLACEHOLDER
}

Node* String::Times(String* _)
{
    PLACEHOLDER
}

Node* String::Times(Array* _)
{
    PLACEHOLDER
}

Node* String::Times(Object* _)
{
    PLACEHOLDER
}

Node* String::Times(Function* _)
{
    PLACEHOLDER
}

Node* Array::Times(Error* _)
{
    return _;
}

Node* Array::Times(Boolean* _)
{
    PLACEHOLDER
}

Node* Array::Times(Integer* _)
{
    PLACEHOLDER
}

Node* Array::Times(Double* _)
{
    PLACEHOLDER
}

Node* Array::Times(String* _)
{
    PLACEHOLDER
}

Node* Array::Times(Array* _)
{
    PLACEHOLDER
}

Node* Array::Times(Object* _)
{
    PLACEHOLDER
}

Node* Array::Times(Function* _)
{
    PLACEHOLDER
}

Node* Object::Times(Error* _)
{
    return _;
}

Node* Object::Times(Boolean* _)
{
    PLACEHOLDER
}

Node* Object::Times(Integer* _)
{
    PLACEHOLDER
}

Node* Object::Times(Double* _)
{
    PLACEHOLDER
}

Node* Object::Times(String* _)
{
    PLACEHOLDER
}

Node* Object::Times(Array* _)
{
    PLACEHOLDER
}

Node* Object::Times(Object* _)
{
    PLACEHOLDER
}

Node* Object::Times(Function* _)
{
    PLACEHOLDER
}

Node* Function::Times(Error* _)
{
    return _;
}

Node* Function::Times(Boolean* _)
{
    PLACEHOLDER
}

Node* Function::Times(Integer* _)
{
    PLACEHOLDER
}

Node* Function::Times(Double* _)
{
    PLACEHOLDER
}

Node* Function::Times(String* _)
{
    PLACEHOLDER
}

Node* Function::Times(Array* _)
{
    PLACEHOLDER
}

Node* Function::Times(Object* _)
{
    PLACEHOLDER
}

Node* Function::Times(Function* _)
{
    PLACEHOLDER
}

Node* Error::DividedBy(Error* _)
{
    return _;
}

Node* Error::DividedBy(Boolean* _)
{
    return this;
}

Node* Error::DividedBy(Integer* _)
{
    return this;
}

Node* Error::DividedBy(Double* _)
{
    return this;
}

Node* Error::DividedBy(String* _)
{
    return this;
}

Node* Error::DividedBy(Array* _)
{
    return this;
}

Node* Error::DividedBy(Object* _)
{
    return this;
}

Node* Error::DividedBy(Function* _)
{
    return this;
}

Node* Boolean::DividedBy(Error* _)
{
    return _;
}

Node* Boolean::DividedBy(Boolean* _)
{
    PLACEHOLDER
}

Node* Boolean::DividedBy(Integer* _)
{
    PLACEHOLDER
}

Node* Boolean::DividedBy(Double* _)
{
    PLACEHOLDER
}

Node* Boolean::DividedBy(String* _)
{
    PLACEHOLDER
}

Node* Boolean::DividedBy(Array* _)
{
    PLACEHOLDER
}

Node* Boolean::DividedBy(Object* _)
{
    PLACEHOLDER
}

Node* Boolean::DividedBy(Function* _)
{
    PLACEHOLDER
}

Node* Integer::DividedBy(Error* _)
{
    return _;
}

Node* Integer::DividedBy(Boolean* _)
{
    PLACEHOLDER
}

Node* Integer::DividedBy(Integer* _)
{
    return new Integer(value / _->value);
}

Node* Integer::DividedBy(Double* _)
{
    PLACEHOLDER
}

Node* Integer::DividedBy(String* _)
{
    PLACEHOLDER
}

Node* Integer::DividedBy(Array* _)
{
    PLACEHOLDER
}

Node* Integer::DividedBy(Object* _)
{
    PLACEHOLDER
}

Node* Integer::DividedBy(Function* _)
{
    PLACEHOLDER
}

Node* Double::DividedBy(Error* _)
{
    return _;
}

Node* Double::DividedBy(Boolean* _)
{
    PLACEHOLDER
}

Node* Double::DividedBy(Integer* _)
{
    PLACEHOLDER
}

Node* Double::DividedBy(Double* _)
{
    PLACEHOLDER
}

Node* Double::DividedBy(String* _)
{
    PLACEHOLDER
}

Node* Double::DividedBy(Array* _)
{
    PLACEHOLDER
}

Node* Double::DividedBy(Object* _)
{
    PLACEHOLDER
}

Node* Double::DividedBy(Function* _)
{
    PLACEHOLDER
}

Node* String::DividedBy(Error* _)
{
    return _;
}

Node* String::DividedBy(Boolean* _)
{
    PLACEHOLDER
}

Node* String::DividedBy(Integer* _)
{
    PLACEHOLDER
}

Node* String::DividedBy(Double* _)
{
    PLACEHOLDER
}

Node* String::DividedBy(String* _)
{
    PLACEHOLDER
}

Node* String::DividedBy(Array* _)
{
    PLACEHOLDER
}

Node* String::DividedBy(Object* _)
{
    PLACEHOLDER
}

Node* String::DividedBy(Function* _)
{
    PLACEHOLDER
}

Node* Array::DividedBy(Error* _)
{
    return _;
}

Node* Array::DividedBy(Boolean* _)
{
    PLACEHOLDER
}

Node* Array::DividedBy(Integer* _)
{
    PLACEHOLDER
}

Node* Array::DividedBy(Double* _)
{
    PLACEHOLDER
}

Node* Array::DividedBy(String* _)
{
    PLACEHOLDER
}

Node* Array::DividedBy(Array* _)
{
    PLACEHOLDER
}

Node* Array::DividedBy(Object* _)
{
    PLACEHOLDER
}

Node* Array::DividedBy(Function* _)
{
    PLACEHOLDER
}

Node* Object::DividedBy(Error* _)
{
    return _;
}

Node* Object::DividedBy(Boolean* _)
{
    PLACEHOLDER
}

Node* Object::DividedBy(Integer* _)
{
    PLACEHOLDER
}

Node* Object::DividedBy(Double* _)
{
    PLACEHOLDER
}

Node* Object::DividedBy(String* _)
{
    PLACEHOLDER
}

Node* Object::DividedBy(Array* _)
{
    PLACEHOLDER
}

Node* Object::DividedBy(Object* _)
{
    PLACEHOLDER
}

Node* Object::DividedBy(Function* _)
{
    PLACEHOLDER
}

Node* Function::DividedBy(Error* _)
{
    return _;
}

Node* Function::DividedBy(Boolean* _)
{
    PLACEHOLDER
}

Node* Function::DividedBy(Integer* _)
{
    PLACEHOLDER
}

Node* Function::DividedBy(Double* _)
{
    PLACEHOLDER
}

Node* Function::DividedBy(String* _)
{
    PLACEHOLDER
}

Node* Function::DividedBy(Array* _)
{
    PLACEHOLDER
}

Node* Function::DividedBy(Object* _)
{
    PLACEHOLDER
}

Node* Function::DividedBy(Function* _)
{
    PLACEHOLDER
}

Node* Error::Mod(Error* _)
{
    return _;
}

Node* Error::Mod(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::Mod(Integer* _)
{
    PLACEHOLDER
}

Node* Error::Mod(Double* _)
{
    PLACEHOLDER
}

Node* Error::Mod(String* _)
{
    PLACEHOLDER
}

Node* Error::Mod(Array* _)
{
    PLACEHOLDER
}

Node* Error::Mod(Object* _)
{
    PLACEHOLDER
}

Node* Error::Mod(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::Mod(Error* _)
{
    return _;
}

Node* Boolean::Mod(Boolean* _)
{
    PLACEHOLDER
}

Node* Boolean::Mod(Integer* _)
{
    PLACEHOLDER
}

Node* Boolean::Mod(Double* _)
{
    PLACEHOLDER
}

Node* Boolean::Mod(String* _)
{
    PLACEHOLDER
}

Node* Boolean::Mod(Array* _)
{
    PLACEHOLDER
}

Node* Boolean::Mod(Object* _)
{
    PLACEHOLDER
}

Node* Boolean::Mod(Function* _)
{
    PLACEHOLDER
}

Node* Integer::Mod(Error* _)
{
    return _;
}

Node* Integer::Mod(Boolean* _)
{
    PLACEHOLDER
}

Node* Integer::Mod(Integer* _)
{
    return new Integer(value % _->value);
}

Node* Integer::Mod(Double* _)
{
    PLACEHOLDER
}

Node* Integer::Mod(String* _)
{
    PLACEHOLDER
}

Node* Integer::Mod(Array* _)
{
    PLACEHOLDER
}

Node* Integer::Mod(Object* _)
{
    PLACEHOLDER
}

Node* Integer::Mod(Function* _)
{
    PLACEHOLDER
}

Node* Double::Mod(Error* _)
{
    return _;
}

Node* Double::Mod(Boolean* _)
{
    PLACEHOLDER
}

Node* Double::Mod(Integer* _)
{
    PLACEHOLDER
}

Node* Double::Mod(Double* _)
{
    PLACEHOLDER
}

Node* Double::Mod(String* _)
{
    PLACEHOLDER
}

Node* Double::Mod(Array* _)
{
    PLACEHOLDER
}

Node* Double::Mod(Object* _)
{
    PLACEHOLDER
}

Node* Double::Mod(Function* _)
{
    PLACEHOLDER
}

Node* String::Mod(Error* _)
{
    return _;
}

Node* String::Mod(Boolean* _)
{
    PLACEHOLDER
}

Node* String::Mod(Integer* _)
{
    PLACEHOLDER
}

Node* String::Mod(Double* _)
{
    PLACEHOLDER
}

Node* String::Mod(String* _)
{
    PLACEHOLDER
}

Node* String::Mod(Array* _)
{
    PLACEHOLDER
}

Node* String::Mod(Object* _)
{
    PLACEHOLDER
}

Node* String::Mod(Function* _)
{
    PLACEHOLDER
}

Node* Array::Mod(Error* _)
{
    return _;
}

Node* Array::Mod(Boolean* _)
{
    PLACEHOLDER
}

Node* Array::Mod(Integer* _)
{
    PLACEHOLDER
}

Node* Array::Mod(Double* _)
{
    PLACEHOLDER
}

Node* Array::Mod(String* _)
{
    PLACEHOLDER
}

Node* Array::Mod(Array* _)
{
    PLACEHOLDER
}

Node* Array::Mod(Object* _)
{
    PLACEHOLDER
}

Node* Array::Mod(Function* _)
{
    PLACEHOLDER
}

Node* Object::Mod(Error* _)
{
    return _;
}

Node* Object::Mod(Boolean* _)
{
    PLACEHOLDER
}

Node* Object::Mod(Integer* _)
{
    PLACEHOLDER
}

Node* Object::Mod(Double* _)
{
    PLACEHOLDER
}

Node* Object::Mod(String* _)
{
    PLACEHOLDER
}

Node* Object::Mod(Array* _)
{
    PLACEHOLDER
}

Node* Object::Mod(Object* _)
{
    PLACEHOLDER
}

Node* Object::Mod(Function* _)
{
    PLACEHOLDER
}

Node* Function::Mod(Error* _)
{
    return _;
}

Node* Function::Mod(Boolean* _)
{
    PLACEHOLDER
}

Node* Function::Mod(Integer* _)
{
    PLACEHOLDER
}

Node* Function::Mod(Double* _)
{
    PLACEHOLDER
}

Node* Function::Mod(String* _)
{
    PLACEHOLDER
}

Node* Function::Mod(Array* _)
{
    PLACEHOLDER
}

Node* Function::Mod(Object* _)
{
    PLACEHOLDER
}

Node* Function::Mod(Function* _)
{
    PLACEHOLDER
}

Node* Error::Call(Error* _)
{
    return _;
}

Node* Error::Call(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::Call(Integer* _)
{
    PLACEHOLDER
}

Node* Error::Call(Double* _)
{
    PLACEHOLDER
}

Node* Error::Call(String* _)
{
    PLACEHOLDER
}

Node* Error::Call(Array* _)
{
    PLACEHOLDER
}

Node* Error::Call(Object* _)
{
    PLACEHOLDER
}

Node* Error::Call(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::Call(Error* _)
{
    return _;
}

Node* Boolean::Call(Boolean* _)
{
    PLACEHOLDER
}

Node* Boolean::Call(Integer* _)
{
    PLACEHOLDER
}

Node* Boolean::Call(Double* _)
{
    PLACEHOLDER
}

Node* Boolean::Call(String* _)
{
    PLACEHOLDER
}

Node* Boolean::Call(Array* _)
{
    PLACEHOLDER
}

Node* Boolean::Call(Object* _)
{
    PLACEHOLDER
}

Node* Boolean::Call(Function* _)
{
    PLACEHOLDER
}

Node* Integer::Call(Error* _)
{
    return _;
}

Node* Integer::Call(Boolean* _)
{
    PLACEHOLDER
}

Node* Integer::Call(Integer* _)
{
    PLACEHOLDER
}

Node* Integer::Call(Double* _)
{
    PLACEHOLDER
}

Node* Integer::Call(String* _)
{
    PLACEHOLDER
}

Node* Integer::Call(Array* _)
{
    PLACEHOLDER
}

Node* Integer::Call(Object* _)
{
    PLACEHOLDER
}

Node* Integer::Call(Function* _)
{
    PLACEHOLDER
}

Node* Double::Call(Error* _)
{
    return _;
}

Node* Double::Call(Boolean* _)
{
    PLACEHOLDER
}

Node* Double::Call(Integer* _)
{
    PLACEHOLDER
}

Node* Double::Call(Double* _)
{
    PLACEHOLDER
}

Node* Double::Call(String* _)
{
    PLACEHOLDER
}

Node* Double::Call(Array* _)
{
    PLACEHOLDER
}

Node* Double::Call(Object* _)
{
    PLACEHOLDER
}

Node* Double::Call(Function* _)
{
    PLACEHOLDER
}

Node* String::Call(Error* _)
{
    return _;
}

Node* String::Call(Boolean* _)
{
    PLACEHOLDER
}

Node* String::Call(Integer* _)
{
    PLACEHOLDER
}

Node* String::Call(Double* _)
{
    PLACEHOLDER
}

Node* String::Call(String* _)
{
    PLACEHOLDER
}

Node* String::Call(Array* _)
{
    PLACEHOLDER
}

Node* String::Call(Object* _)
{
    PLACEHOLDER
}

Node* String::Call(Function* _)
{
    PLACEHOLDER
}

Node* Array::Call(Error* _)
{
    return _;
}

Node* Array::Call(Boolean* _)
{
    PLACEHOLDER
}

Node* Array::Call(Integer* _)
{
    PLACEHOLDER
}

Node* Array::Call(Double* _)
{
    PLACEHOLDER
}

Node* Array::Call(String* _)
{
    PLACEHOLDER
}

Node* Array::Call(Array* _)
{
    PLACEHOLDER
}

Node* Array::Call(Object* _)
{
    PLACEHOLDER
}

Node* Array::Call(Function* _)
{
    PLACEHOLDER
}

Node* Object::Call(Error* _)
{
    return _;
}

Node* Object::Call(Boolean* _)
{
    PLACEHOLDER
}

Node* Object::Call(Integer* _)
{
    PLACEHOLDER
}

Node* Object::Call(Double* _)
{
    PLACEHOLDER
}

Node* Object::Call(String* _)
{
    PLACEHOLDER
}

Node* Object::Call(Array* _)
{
    PLACEHOLDER
}

Node* Object::Call(Object* _)
{
    PLACEHOLDER
}

Node* Object::Call(Function* _)
{
    PLACEHOLDER
}

Node* Function::Call(Error* _)
{
    return _;
}

Node* Function::Call(Boolean* _)
{
    PLACEHOLDER
}

Node* Function::Call(Integer* _)
{
    PLACEHOLDER
}

Node* Function::Call(Double* _)
{
    PLACEHOLDER
}

Node* Function::Call(String* _)
{
    PLACEHOLDER
}

Node* Function::Call(Array* _)
{
    PLACEHOLDER
}

Node* Function::Call(Object* _)
{
    PLACEHOLDER
}

Node* Function::Call(Function* _)
{
    PLACEHOLDER
}

Node* Error::Equals(Error* _)
{
    PLACEHOLDER
}

Node* Error::Equals(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::Equals(Integer* _)
{
    PLACEHOLDER
}

Node* Error::Equals(Double* _)
{
    PLACEHOLDER
}

Node* Error::Equals(String* _)
{
    PLACEHOLDER
}

Node* Error::Equals(Array* _)
{
    PLACEHOLDER
}

Node* Error::Equals(Object* _)
{
    PLACEHOLDER
}

Node* Error::Equals(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::Equals(Error* _)
{
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Double::Equals(Boolean* _)
{
    return new Boolean(false);
}

Node* Double::Equals(Integer* _)
{
    return new Boolean(getValue() == _->getValue());
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Error::NotEquals(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::NotEquals(Integer* _)
{
    PLACEHOLDER
}

Node* Error::NotEquals(Double* _)
{
    PLACEHOLDER
}

Node* Error::NotEquals(String* _)
{
    PLACEHOLDER
}

Node* Error::NotEquals(Array* _)
{
    PLACEHOLDER
}

Node* Error::NotEquals(Object* _)
{
    PLACEHOLDER
}

Node* Error::NotEquals(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::NotEquals(Error* _)
{
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Double::NotEquals(Boolean* _)
{
    return new Boolean(true);
}

Node* Double::NotEquals(Integer* _)
{
    return new Boolean(getValue() != _->getValue());
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Error::LessThan(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::LessThan(Integer* _)
{
    PLACEHOLDER
}

Node* Error::LessThan(Double* _)
{
    PLACEHOLDER
}

Node* Error::LessThan(String* _)
{
    PLACEHOLDER
}

Node* Error::LessThan(Array* _)
{
    PLACEHOLDER
}

Node* Error::LessThan(Object* _)
{
    PLACEHOLDER
}

Node* Error::LessThan(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::LessThan(Error* _)
{
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Error::GreaterThan(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThan(Integer* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThan(Double* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThan(String* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThan(Array* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThan(Object* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThan(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::GreaterThan(Error* _)
{
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Error::LessThanOrEqualTo(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::LessThanOrEqualTo(Integer* _)
{
    PLACEHOLDER
}

Node* Error::LessThanOrEqualTo(Double* _)
{
    PLACEHOLDER
}

Node* Error::LessThanOrEqualTo(String* _)
{
    PLACEHOLDER
}

Node* Error::LessThanOrEqualTo(Array* _)
{
    PLACEHOLDER
}

Node* Error::LessThanOrEqualTo(Object* _)
{
    PLACEHOLDER
}

Node* Error::LessThanOrEqualTo(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::LessThanOrEqualTo(Error* _)
{
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Double::LessThanOrEqualTo(Boolean* _)
{
    return new Boolean(false);
}

Node* Double::LessThanOrEqualTo(Integer* _)
{
    return new Boolean(getValue() <= _->getValue());
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Error::GreaterThanOrEqualTo(Boolean* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThanOrEqualTo(Integer* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThanOrEqualTo(Double* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThanOrEqualTo(String* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThanOrEqualTo(Array* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThanOrEqualTo(Object* _)
{
    PLACEHOLDER
}

Node* Error::GreaterThanOrEqualTo(Function* _)
{
    PLACEHOLDER
}

Node* Boolean::GreaterThanOrEqualTo(Error* _)
{
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
}

Node* Double::GreaterThanOrEqualTo(Boolean* _)
{
    return new Boolean(true);
}

Node* Double::GreaterThanOrEqualTo(Integer* _)
{
    return new Boolean(getValue() >= _->getValue());
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
    PLACEHOLDER
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
Node* Error::back_And(Boolean* _) { return _->And(this); }
Node* Error::back_And(Integer* _) { return _->And(this); }
Node* Error::back_And(Double* _) { return _->And(this); }
Node* Error::back_And(String* _) { return _->And(this); }
Node* Error::back_And(Array* _) { return _->And(this); }
Node* Error::back_And(Object* _) { return _->And(this); }
Node* Error::back_And(Function* _) { return _->And(this); }
Node* Boolean::And(Node* _) { return _->back_And(this); }
Node* Boolean::back_And(Error* _) { return _->And(this); }
Node* Boolean::back_And(Boolean* _) { return _->And(this); }
Node* Boolean::back_And(Integer* _) { return _->And(this); }
Node* Boolean::back_And(Double* _) { return _->And(this); }
Node* Boolean::back_And(String* _) { return _->And(this); }
Node* Boolean::back_And(Array* _) { return _->And(this); }
Node* Boolean::back_And(Object* _) { return _->And(this); }
Node* Boolean::back_And(Function* _) { return _->And(this); }
Node* Integer::And(Node* _) { return _->back_And(this); }
Node* Integer::back_And(Error* _) { return _->And(this); }
Node* Integer::back_And(Boolean* _) { return _->And(this); }
Node* Integer::back_And(Integer* _) { return _->And(this); }
Node* Integer::back_And(Double* _) { return _->And(this); }
Node* Integer::back_And(String* _) { return _->And(this); }
Node* Integer::back_And(Array* _) { return _->And(this); }
Node* Integer::back_And(Object* _) { return _->And(this); }
Node* Integer::back_And(Function* _) { return _->And(this); }
Node* Double::And(Node* _) { return _->back_And(this); }
Node* Double::back_And(Error* _) { return _->And(this); }
Node* Double::back_And(Boolean* _) { return _->And(this); }
Node* Double::back_And(Integer* _) { return _->And(this); }
Node* Double::back_And(Double* _) { return _->And(this); }
Node* Double::back_And(String* _) { return _->And(this); }
Node* Double::back_And(Array* _) { return _->And(this); }
Node* Double::back_And(Object* _) { return _->And(this); }
Node* Double::back_And(Function* _) { return _->And(this); }
Node* String::And(Node* _) { return _->back_And(this); }
Node* String::back_And(Error* _) { return _->And(this); }
Node* String::back_And(Boolean* _) { return _->And(this); }
Node* String::back_And(Integer* _) { return _->And(this); }
Node* String::back_And(Double* _) { return _->And(this); }
Node* String::back_And(String* _) { return _->And(this); }
Node* String::back_And(Array* _) { return _->And(this); }
Node* String::back_And(Object* _) { return _->And(this); }
Node* String::back_And(Function* _) { return _->And(this); }
Node* Array::And(Node* _) { return _->back_And(this); }
Node* Array::back_And(Error* _) { return _->And(this); }
Node* Array::back_And(Boolean* _) { return _->And(this); }
Node* Array::back_And(Integer* _) { return _->And(this); }
Node* Array::back_And(Double* _) { return _->And(this); }
Node* Array::back_And(String* _) { return _->And(this); }
Node* Array::back_And(Array* _) { return _->And(this); }
Node* Array::back_And(Object* _) { return _->And(this); }
Node* Array::back_And(Function* _) { return _->And(this); }
Node* Object::And(Node* _) { return _->back_And(this); }
Node* Object::back_And(Error* _) { return _->And(this); }
Node* Object::back_And(Boolean* _) { return _->And(this); }
Node* Object::back_And(Integer* _) { return _->And(this); }
Node* Object::back_And(Double* _) { return _->And(this); }
Node* Object::back_And(String* _) { return _->And(this); }
Node* Object::back_And(Array* _) { return _->And(this); }
Node* Object::back_And(Object* _) { return _->And(this); }
Node* Object::back_And(Function* _) { return _->And(this); }
Node* Function::And(Node* _) { return _->back_And(this); }
Node* Function::back_And(Error* _) { return _->And(this); }
Node* Function::back_And(Boolean* _) { return _->And(this); }
Node* Function::back_And(Integer* _) { return _->And(this); }
Node* Function::back_And(Double* _) { return _->And(this); }
Node* Function::back_And(String* _) { return _->And(this); }
Node* Function::back_And(Array* _) { return _->And(this); }
Node* Function::back_And(Object* _) { return _->And(this); }
Node* Function::back_And(Function* _) { return _->And(this); }
Node* Error::Or(Node* _) { return _->back_Or(this); }
Node* Error::back_Or(Error* _) { return _->Or(this); }
Node* Error::back_Or(Boolean* _) { return _->Or(this); }
Node* Error::back_Or(Integer* _) { return _->Or(this); }
Node* Error::back_Or(Double* _) { return _->Or(this); }
Node* Error::back_Or(String* _) { return _->Or(this); }
Node* Error::back_Or(Array* _) { return _->Or(this); }
Node* Error::back_Or(Object* _) { return _->Or(this); }
Node* Error::back_Or(Function* _) { return _->Or(this); }
Node* Boolean::Or(Node* _) { return _->back_Or(this); }
Node* Boolean::back_Or(Error* _) { return _->Or(this); }
Node* Boolean::back_Or(Boolean* _) { return _->Or(this); }
Node* Boolean::back_Or(Integer* _) { return _->Or(this); }
Node* Boolean::back_Or(Double* _) { return _->Or(this); }
Node* Boolean::back_Or(String* _) { return _->Or(this); }
Node* Boolean::back_Or(Array* _) { return _->Or(this); }
Node* Boolean::back_Or(Object* _) { return _->Or(this); }
Node* Boolean::back_Or(Function* _) { return _->Or(this); }
Node* Integer::Or(Node* _) { return _->back_Or(this); }
Node* Integer::back_Or(Error* _) { return _->Or(this); }
Node* Integer::back_Or(Boolean* _) { return _->Or(this); }
Node* Integer::back_Or(Integer* _) { return _->Or(this); }
Node* Integer::back_Or(Double* _) { return _->Or(this); }
Node* Integer::back_Or(String* _) { return _->Or(this); }
Node* Integer::back_Or(Array* _) { return _->Or(this); }
Node* Integer::back_Or(Object* _) { return _->Or(this); }
Node* Integer::back_Or(Function* _) { return _->Or(this); }
Node* Double::Or(Node* _) { return _->back_Or(this); }
Node* Double::back_Or(Error* _) { return _->Or(this); }
Node* Double::back_Or(Boolean* _) { return _->Or(this); }
Node* Double::back_Or(Integer* _) { return _->Or(this); }
Node* Double::back_Or(Double* _) { return _->Or(this); }
Node* Double::back_Or(String* _) { return _->Or(this); }
Node* Double::back_Or(Array* _) { return _->Or(this); }
Node* Double::back_Or(Object* _) { return _->Or(this); }
Node* Double::back_Or(Function* _) { return _->Or(this); }
Node* String::Or(Node* _) { return _->back_Or(this); }
Node* String::back_Or(Error* _) { return _->Or(this); }
Node* String::back_Or(Boolean* _) { return _->Or(this); }
Node* String::back_Or(Integer* _) { return _->Or(this); }
Node* String::back_Or(Double* _) { return _->Or(this); }
Node* String::back_Or(String* _) { return _->Or(this); }
Node* String::back_Or(Array* _) { return _->Or(this); }
Node* String::back_Or(Object* _) { return _->Or(this); }
Node* String::back_Or(Function* _) { return _->Or(this); }
Node* Array::Or(Node* _) { return _->back_Or(this); }
Node* Array::back_Or(Error* _) { return _->Or(this); }
Node* Array::back_Or(Boolean* _) { return _->Or(this); }
Node* Array::back_Or(Integer* _) { return _->Or(this); }
Node* Array::back_Or(Double* _) { return _->Or(this); }
Node* Array::back_Or(String* _) { return _->Or(this); }
Node* Array::back_Or(Array* _) { return _->Or(this); }
Node* Array::back_Or(Object* _) { return _->Or(this); }
Node* Array::back_Or(Function* _) { return _->Or(this); }
Node* Object::Or(Node* _) { return _->back_Or(this); }
Node* Object::back_Or(Error* _) { return _->Or(this); }
Node* Object::back_Or(Boolean* _) { return _->Or(this); }
Node* Object::back_Or(Integer* _) { return _->Or(this); }
Node* Object::back_Or(Double* _) { return _->Or(this); }
Node* Object::back_Or(String* _) { return _->Or(this); }
Node* Object::back_Or(Array* _) { return _->Or(this); }
Node* Object::back_Or(Object* _) { return _->Or(this); }
Node* Object::back_Or(Function* _) { return _->Or(this); }
Node* Function::Or(Node* _) { return _->back_Or(this); }
Node* Function::back_Or(Error* _) { return _->Or(this); }
Node* Function::back_Or(Boolean* _) { return _->Or(this); }
Node* Function::back_Or(Integer* _) { return _->Or(this); }
Node* Function::back_Or(Double* _) { return _->Or(this); }
Node* Function::back_Or(String* _) { return _->Or(this); }
Node* Function::back_Or(Array* _) { return _->Or(this); }
Node* Function::back_Or(Object* _) { return _->Or(this); }
Node* Function::back_Or(Function* _) { return _->Or(this); }
Node* Error::Plus(Node* _) { return _->back_Plus(this); }
Node* Error::back_Plus(Error* _) { return _->Plus(this); }
Node* Error::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Error::back_Plus(Integer* _) { return _->Plus(this); }
Node* Error::back_Plus(Double* _) { return _->Plus(this); }
Node* Error::back_Plus(String* _) { return _->Plus(this); }
Node* Error::back_Plus(Array* _) { return _->Plus(this); }
Node* Error::back_Plus(Object* _) { return _->Plus(this); }
Node* Error::back_Plus(Function* _) { return _->Plus(this); }
Node* Boolean::Plus(Node* _) { return _->back_Plus(this); }
Node* Boolean::back_Plus(Error* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Integer* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Double* _) { return _->Plus(this); }
Node* Boolean::back_Plus(String* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Array* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Object* _) { return _->Plus(this); }
Node* Boolean::back_Plus(Function* _) { return _->Plus(this); }
Node* Integer::Plus(Node* _) { return _->back_Plus(this); }
Node* Integer::back_Plus(Error* _) { return _->Plus(this); }
Node* Integer::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Integer::back_Plus(Integer* _) { return _->Plus(this); }
Node* Integer::back_Plus(Double* _) { return _->Plus(this); }
Node* Integer::back_Plus(String* _) { return _->Plus(this); }
Node* Integer::back_Plus(Array* _) { return _->Plus(this); }
Node* Integer::back_Plus(Object* _) { return _->Plus(this); }
Node* Integer::back_Plus(Function* _) { return _->Plus(this); }
Node* Double::Plus(Node* _) { return _->back_Plus(this); }
Node* Double::back_Plus(Error* _) { return _->Plus(this); }
Node* Double::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Double::back_Plus(Integer* _) { return _->Plus(this); }
Node* Double::back_Plus(Double* _) { return _->Plus(this); }
Node* Double::back_Plus(String* _) { return _->Plus(this); }
Node* Double::back_Plus(Array* _) { return _->Plus(this); }
Node* Double::back_Plus(Object* _) { return _->Plus(this); }
Node* Double::back_Plus(Function* _) { return _->Plus(this); }
Node* String::Plus(Node* _) { return _->back_Plus(this); }
Node* String::back_Plus(Error* _) { return _->Plus(this); }
Node* String::back_Plus(Boolean* _) { return _->Plus(this); }
Node* String::back_Plus(Integer* _) { return _->Plus(this); }
Node* String::back_Plus(Double* _) { return _->Plus(this); }
Node* String::back_Plus(String* _) { return _->Plus(this); }
Node* String::back_Plus(Array* _) { return _->Plus(this); }
Node* String::back_Plus(Object* _) { return _->Plus(this); }
Node* String::back_Plus(Function* _) { return _->Plus(this); }
Node* Array::Plus(Node* _) { return _->back_Plus(this); }
Node* Array::back_Plus(Error* _) { return _->Plus(this); }
Node* Array::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Array::back_Plus(Integer* _) { return _->Plus(this); }
Node* Array::back_Plus(Double* _) { return _->Plus(this); }
Node* Array::back_Plus(String* _) { return _->Plus(this); }
Node* Array::back_Plus(Array* _) { return _->Plus(this); }
Node* Array::back_Plus(Object* _) { return _->Plus(this); }
Node* Array::back_Plus(Function* _) { return _->Plus(this); }
Node* Object::Plus(Node* _) { return _->back_Plus(this); }
Node* Object::back_Plus(Error* _) { return _->Plus(this); }
Node* Object::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Object::back_Plus(Integer* _) { return _->Plus(this); }
Node* Object::back_Plus(Double* _) { return _->Plus(this); }
Node* Object::back_Plus(String* _) { return _->Plus(this); }
Node* Object::back_Plus(Array* _) { return _->Plus(this); }
Node* Object::back_Plus(Object* _) { return _->Plus(this); }
Node* Object::back_Plus(Function* _) { return _->Plus(this); }
Node* Function::Plus(Node* _) { return _->back_Plus(this); }
Node* Function::back_Plus(Error* _) { return _->Plus(this); }
Node* Function::back_Plus(Boolean* _) { return _->Plus(this); }
Node* Function::back_Plus(Integer* _) { return _->Plus(this); }
Node* Function::back_Plus(Double* _) { return _->Plus(this); }
Node* Function::back_Plus(String* _) { return _->Plus(this); }
Node* Function::back_Plus(Array* _) { return _->Plus(this); }
Node* Function::back_Plus(Object* _) { return _->Plus(this); }
Node* Function::back_Plus(Function* _) { return _->Plus(this); }
Node* Error::Minus(Node* _) { return _->back_Minus(this); }
Node* Error::back_Minus(Error* _) { return _->Minus(this); }
Node* Error::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Error::back_Minus(Integer* _) { return _->Minus(this); }
Node* Error::back_Minus(Double* _) { return _->Minus(this); }
Node* Error::back_Minus(String* _) { return _->Minus(this); }
Node* Error::back_Minus(Array* _) { return _->Minus(this); }
Node* Error::back_Minus(Object* _) { return _->Minus(this); }
Node* Error::back_Minus(Function* _) { return _->Minus(this); }
Node* Boolean::Minus(Node* _) { return _->back_Minus(this); }
Node* Boolean::back_Minus(Error* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Integer* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Double* _) { return _->Minus(this); }
Node* Boolean::back_Minus(String* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Array* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Object* _) { return _->Minus(this); }
Node* Boolean::back_Minus(Function* _) { return _->Minus(this); }
Node* Integer::Minus(Node* _) { return _->back_Minus(this); }
Node* Integer::back_Minus(Error* _) { return _->Minus(this); }
Node* Integer::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Integer::back_Minus(Integer* _) { return _->Minus(this); }
Node* Integer::back_Minus(Double* _) { return _->Minus(this); }
Node* Integer::back_Minus(String* _) { return _->Minus(this); }
Node* Integer::back_Minus(Array* _) { return _->Minus(this); }
Node* Integer::back_Minus(Object* _) { return _->Minus(this); }
Node* Integer::back_Minus(Function* _) { return _->Minus(this); }
Node* Double::Minus(Node* _) { return _->back_Minus(this); }
Node* Double::back_Minus(Error* _) { return _->Minus(this); }
Node* Double::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Double::back_Minus(Integer* _) { return _->Minus(this); }
Node* Double::back_Minus(Double* _) { return _->Minus(this); }
Node* Double::back_Minus(String* _) { return _->Minus(this); }
Node* Double::back_Minus(Array* _) { return _->Minus(this); }
Node* Double::back_Minus(Object* _) { return _->Minus(this); }
Node* Double::back_Minus(Function* _) { return _->Minus(this); }
Node* String::Minus(Node* _) { return _->back_Minus(this); }
Node* String::back_Minus(Error* _) { return _->Minus(this); }
Node* String::back_Minus(Boolean* _) { return _->Minus(this); }
Node* String::back_Minus(Integer* _) { return _->Minus(this); }
Node* String::back_Minus(Double* _) { return _->Minus(this); }
Node* String::back_Minus(String* _) { return _->Minus(this); }
Node* String::back_Minus(Array* _) { return _->Minus(this); }
Node* String::back_Minus(Object* _) { return _->Minus(this); }
Node* String::back_Minus(Function* _) { return _->Minus(this); }
Node* Array::Minus(Node* _) { return _->back_Minus(this); }
Node* Array::back_Minus(Error* _) { return _->Minus(this); }
Node* Array::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Array::back_Minus(Integer* _) { return _->Minus(this); }
Node* Array::back_Minus(Double* _) { return _->Minus(this); }
Node* Array::back_Minus(String* _) { return _->Minus(this); }
Node* Array::back_Minus(Array* _) { return _->Minus(this); }
Node* Array::back_Minus(Object* _) { return _->Minus(this); }
Node* Array::back_Minus(Function* _) { return _->Minus(this); }
Node* Object::Minus(Node* _) { return _->back_Minus(this); }
Node* Object::back_Minus(Error* _) { return _->Minus(this); }
Node* Object::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Object::back_Minus(Integer* _) { return _->Minus(this); }
Node* Object::back_Minus(Double* _) { return _->Minus(this); }
Node* Object::back_Minus(String* _) { return _->Minus(this); }
Node* Object::back_Minus(Array* _) { return _->Minus(this); }
Node* Object::back_Minus(Object* _) { return _->Minus(this); }
Node* Object::back_Minus(Function* _) { return _->Minus(this); }
Node* Function::Minus(Node* _) { return _->back_Minus(this); }
Node* Function::back_Minus(Error* _) { return _->Minus(this); }
Node* Function::back_Minus(Boolean* _) { return _->Minus(this); }
Node* Function::back_Minus(Integer* _) { return _->Minus(this); }
Node* Function::back_Minus(Double* _) { return _->Minus(this); }
Node* Function::back_Minus(String* _) { return _->Minus(this); }
Node* Function::back_Minus(Array* _) { return _->Minus(this); }
Node* Function::back_Minus(Object* _) { return _->Minus(this); }
Node* Function::back_Minus(Function* _) { return _->Minus(this); }
Node* Error::Times(Node* _) { return _->back_Times(this); }
Node* Error::back_Times(Error* _) { return _->Times(this); }
Node* Error::back_Times(Boolean* _) { return _->Times(this); }
Node* Error::back_Times(Integer* _) { return _->Times(this); }
Node* Error::back_Times(Double* _) { return _->Times(this); }
Node* Error::back_Times(String* _) { return _->Times(this); }
Node* Error::back_Times(Array* _) { return _->Times(this); }
Node* Error::back_Times(Object* _) { return _->Times(this); }
Node* Error::back_Times(Function* _) { return _->Times(this); }
Node* Boolean::Times(Node* _) { return _->back_Times(this); }
Node* Boolean::back_Times(Error* _) { return _->Times(this); }
Node* Boolean::back_Times(Boolean* _) { return _->Times(this); }
Node* Boolean::back_Times(Integer* _) { return _->Times(this); }
Node* Boolean::back_Times(Double* _) { return _->Times(this); }
Node* Boolean::back_Times(String* _) { return _->Times(this); }
Node* Boolean::back_Times(Array* _) { return _->Times(this); }
Node* Boolean::back_Times(Object* _) { return _->Times(this); }
Node* Boolean::back_Times(Function* _) { return _->Times(this); }
Node* Integer::Times(Node* _) { return _->back_Times(this); }
Node* Integer::back_Times(Error* _) { return _->Times(this); }
Node* Integer::back_Times(Boolean* _) { return _->Times(this); }
Node* Integer::back_Times(Integer* _) { return _->Times(this); }
Node* Integer::back_Times(Double* _) { return _->Times(this); }
Node* Integer::back_Times(String* _) { return _->Times(this); }
Node* Integer::back_Times(Array* _) { return _->Times(this); }
Node* Integer::back_Times(Object* _) { return _->Times(this); }
Node* Integer::back_Times(Function* _) { return _->Times(this); }
Node* Double::Times(Node* _) { return _->back_Times(this); }
Node* Double::back_Times(Error* _) { return _->Times(this); }
Node* Double::back_Times(Boolean* _) { return _->Times(this); }
Node* Double::back_Times(Integer* _) { return _->Times(this); }
Node* Double::back_Times(Double* _) { return _->Times(this); }
Node* Double::back_Times(String* _) { return _->Times(this); }
Node* Double::back_Times(Array* _) { return _->Times(this); }
Node* Double::back_Times(Object* _) { return _->Times(this); }
Node* Double::back_Times(Function* _) { return _->Times(this); }
Node* String::Times(Node* _) { return _->back_Times(this); }
Node* String::back_Times(Error* _) { return _->Times(this); }
Node* String::back_Times(Boolean* _) { return _->Times(this); }
Node* String::back_Times(Integer* _) { return _->Times(this); }
Node* String::back_Times(Double* _) { return _->Times(this); }
Node* String::back_Times(String* _) { return _->Times(this); }
Node* String::back_Times(Array* _) { return _->Times(this); }
Node* String::back_Times(Object* _) { return _->Times(this); }
Node* String::back_Times(Function* _) { return _->Times(this); }
Node* Array::Times(Node* _) { return _->back_Times(this); }
Node* Array::back_Times(Error* _) { return _->Times(this); }
Node* Array::back_Times(Boolean* _) { return _->Times(this); }
Node* Array::back_Times(Integer* _) { return _->Times(this); }
Node* Array::back_Times(Double* _) { return _->Times(this); }
Node* Array::back_Times(String* _) { return _->Times(this); }
Node* Array::back_Times(Array* _) { return _->Times(this); }
Node* Array::back_Times(Object* _) { return _->Times(this); }
Node* Array::back_Times(Function* _) { return _->Times(this); }
Node* Object::Times(Node* _) { return _->back_Times(this); }
Node* Object::back_Times(Error* _) { return _->Times(this); }
Node* Object::back_Times(Boolean* _) { return _->Times(this); }
Node* Object::back_Times(Integer* _) { return _->Times(this); }
Node* Object::back_Times(Double* _) { return _->Times(this); }
Node* Object::back_Times(String* _) { return _->Times(this); }
Node* Object::back_Times(Array* _) { return _->Times(this); }
Node* Object::back_Times(Object* _) { return _->Times(this); }
Node* Object::back_Times(Function* _) { return _->Times(this); }
Node* Function::Times(Node* _) { return _->back_Times(this); }
Node* Function::back_Times(Error* _) { return _->Times(this); }
Node* Function::back_Times(Boolean* _) { return _->Times(this); }
Node* Function::back_Times(Integer* _) { return _->Times(this); }
Node* Function::back_Times(Double* _) { return _->Times(this); }
Node* Function::back_Times(String* _) { return _->Times(this); }
Node* Function::back_Times(Array* _) { return _->Times(this); }
Node* Function::back_Times(Object* _) { return _->Times(this); }
Node* Function::back_Times(Function* _) { return _->Times(this); }
Node* Error::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Error::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Boolean::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Boolean::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Boolean::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Integer::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Integer::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Double::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Double::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* String::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* String::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Array::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Array::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Array::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Object::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Object::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Function::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Function::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Boolean* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Array* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Error::Mod(Node* _) { return _->back_Mod(this); }
Node* Error::back_Mod(Error* _) { return _->Mod(this); }
Node* Error::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Error::back_Mod(Integer* _) { return _->Mod(this); }
Node* Error::back_Mod(Double* _) { return _->Mod(this); }
Node* Error::back_Mod(String* _) { return _->Mod(this); }
Node* Error::back_Mod(Array* _) { return _->Mod(this); }
Node* Error::back_Mod(Object* _) { return _->Mod(this); }
Node* Error::back_Mod(Function* _) { return _->Mod(this); }
Node* Boolean::Mod(Node* _) { return _->back_Mod(this); }
Node* Boolean::back_Mod(Error* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Integer* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Double* _) { return _->Mod(this); }
Node* Boolean::back_Mod(String* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Array* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Object* _) { return _->Mod(this); }
Node* Boolean::back_Mod(Function* _) { return _->Mod(this); }
Node* Integer::Mod(Node* _) { return _->back_Mod(this); }
Node* Integer::back_Mod(Error* _) { return _->Mod(this); }
Node* Integer::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Integer::back_Mod(Integer* _) { return _->Mod(this); }
Node* Integer::back_Mod(Double* _) { return _->Mod(this); }
Node* Integer::back_Mod(String* _) { return _->Mod(this); }
Node* Integer::back_Mod(Array* _) { return _->Mod(this); }
Node* Integer::back_Mod(Object* _) { return _->Mod(this); }
Node* Integer::back_Mod(Function* _) { return _->Mod(this); }
Node* Double::Mod(Node* _) { return _->back_Mod(this); }
Node* Double::back_Mod(Error* _) { return _->Mod(this); }
Node* Double::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Double::back_Mod(Integer* _) { return _->Mod(this); }
Node* Double::back_Mod(Double* _) { return _->Mod(this); }
Node* Double::back_Mod(String* _) { return _->Mod(this); }
Node* Double::back_Mod(Array* _) { return _->Mod(this); }
Node* Double::back_Mod(Object* _) { return _->Mod(this); }
Node* Double::back_Mod(Function* _) { return _->Mod(this); }
Node* String::Mod(Node* _) { return _->back_Mod(this); }
Node* String::back_Mod(Error* _) { return _->Mod(this); }
Node* String::back_Mod(Boolean* _) { return _->Mod(this); }
Node* String::back_Mod(Integer* _) { return _->Mod(this); }
Node* String::back_Mod(Double* _) { return _->Mod(this); }
Node* String::back_Mod(String* _) { return _->Mod(this); }
Node* String::back_Mod(Array* _) { return _->Mod(this); }
Node* String::back_Mod(Object* _) { return _->Mod(this); }
Node* String::back_Mod(Function* _) { return _->Mod(this); }
Node* Array::Mod(Node* _) { return _->back_Mod(this); }
Node* Array::back_Mod(Error* _) { return _->Mod(this); }
Node* Array::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Array::back_Mod(Integer* _) { return _->Mod(this); }
Node* Array::back_Mod(Double* _) { return _->Mod(this); }
Node* Array::back_Mod(String* _) { return _->Mod(this); }
Node* Array::back_Mod(Array* _) { return _->Mod(this); }
Node* Array::back_Mod(Object* _) { return _->Mod(this); }
Node* Array::back_Mod(Function* _) { return _->Mod(this); }
Node* Object::Mod(Node* _) { return _->back_Mod(this); }
Node* Object::back_Mod(Error* _) { return _->Mod(this); }
Node* Object::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Object::back_Mod(Integer* _) { return _->Mod(this); }
Node* Object::back_Mod(Double* _) { return _->Mod(this); }
Node* Object::back_Mod(String* _) { return _->Mod(this); }
Node* Object::back_Mod(Array* _) { return _->Mod(this); }
Node* Object::back_Mod(Object* _) { return _->Mod(this); }
Node* Object::back_Mod(Function* _) { return _->Mod(this); }
Node* Function::Mod(Node* _) { return _->back_Mod(this); }
Node* Function::back_Mod(Error* _) { return _->Mod(this); }
Node* Function::back_Mod(Boolean* _) { return _->Mod(this); }
Node* Function::back_Mod(Integer* _) { return _->Mod(this); }
Node* Function::back_Mod(Double* _) { return _->Mod(this); }
Node* Function::back_Mod(String* _) { return _->Mod(this); }
Node* Function::back_Mod(Array* _) { return _->Mod(this); }
Node* Function::back_Mod(Object* _) { return _->Mod(this); }
Node* Function::back_Mod(Function* _) { return _->Mod(this); }
Node* Error::Call(Node* _) { return _->back_Call(this); }
Node* Error::back_Call(Error* _) { return _->Call(this); }
Node* Error::back_Call(Boolean* _) { return _->Call(this); }
Node* Error::back_Call(Integer* _) { return _->Call(this); }
Node* Error::back_Call(Double* _) { return _->Call(this); }
Node* Error::back_Call(String* _) { return _->Call(this); }
Node* Error::back_Call(Array* _) { return _->Call(this); }
Node* Error::back_Call(Object* _) { return _->Call(this); }
Node* Error::back_Call(Function* _) { return _->Call(this); }
Node* Boolean::Call(Node* _) { return _->back_Call(this); }
Node* Boolean::back_Call(Error* _) { return _->Call(this); }
Node* Boolean::back_Call(Boolean* _) { return _->Call(this); }
Node* Boolean::back_Call(Integer* _) { return _->Call(this); }
Node* Boolean::back_Call(Double* _) { return _->Call(this); }
Node* Boolean::back_Call(String* _) { return _->Call(this); }
Node* Boolean::back_Call(Array* _) { return _->Call(this); }
Node* Boolean::back_Call(Object* _) { return _->Call(this); }
Node* Boolean::back_Call(Function* _) { return _->Call(this); }
Node* Integer::Call(Node* _) { return _->back_Call(this); }
Node* Integer::back_Call(Error* _) { return _->Call(this); }
Node* Integer::back_Call(Boolean* _) { return _->Call(this); }
Node* Integer::back_Call(Integer* _) { return _->Call(this); }
Node* Integer::back_Call(Double* _) { return _->Call(this); }
Node* Integer::back_Call(String* _) { return _->Call(this); }
Node* Integer::back_Call(Array* _) { return _->Call(this); }
Node* Integer::back_Call(Object* _) { return _->Call(this); }
Node* Integer::back_Call(Function* _) { return _->Call(this); }
Node* Double::Call(Node* _) { return _->back_Call(this); }
Node* Double::back_Call(Error* _) { return _->Call(this); }
Node* Double::back_Call(Boolean* _) { return _->Call(this); }
Node* Double::back_Call(Integer* _) { return _->Call(this); }
Node* Double::back_Call(Double* _) { return _->Call(this); }
Node* Double::back_Call(String* _) { return _->Call(this); }
Node* Double::back_Call(Array* _) { return _->Call(this); }
Node* Double::back_Call(Object* _) { return _->Call(this); }
Node* Double::back_Call(Function* _) { return _->Call(this); }
Node* String::Call(Node* _) { return _->back_Call(this); }
Node* String::back_Call(Error* _) { return _->Call(this); }
Node* String::back_Call(Boolean* _) { return _->Call(this); }
Node* String::back_Call(Integer* _) { return _->Call(this); }
Node* String::back_Call(Double* _) { return _->Call(this); }
Node* String::back_Call(String* _) { return _->Call(this); }
Node* String::back_Call(Array* _) { return _->Call(this); }
Node* String::back_Call(Object* _) { return _->Call(this); }
Node* String::back_Call(Function* _) { return _->Call(this); }
Node* Array::Call(Node* _) { return _->back_Call(this); }
Node* Array::back_Call(Error* _) { return _->Call(this); }
Node* Array::back_Call(Boolean* _) { return _->Call(this); }
Node* Array::back_Call(Integer* _) { return _->Call(this); }
Node* Array::back_Call(Double* _) { return _->Call(this); }
Node* Array::back_Call(String* _) { return _->Call(this); }
Node* Array::back_Call(Array* _) { return _->Call(this); }
Node* Array::back_Call(Object* _) { return _->Call(this); }
Node* Array::back_Call(Function* _) { return _->Call(this); }
Node* Object::Call(Node* _) { return _->back_Call(this); }
Node* Object::back_Call(Error* _) { return _->Call(this); }
Node* Object::back_Call(Boolean* _) { return _->Call(this); }
Node* Object::back_Call(Integer* _) { return _->Call(this); }
Node* Object::back_Call(Double* _) { return _->Call(this); }
Node* Object::back_Call(String* _) { return _->Call(this); }
Node* Object::back_Call(Array* _) { return _->Call(this); }
Node* Object::back_Call(Object* _) { return _->Call(this); }
Node* Object::back_Call(Function* _) { return _->Call(this); }
Node* Function::Call(Node* _) { return _->back_Call(this); }
Node* Function::back_Call(Error* _) { return _->Call(this); }
Node* Function::back_Call(Boolean* _) { return _->Call(this); }
Node* Function::back_Call(Integer* _) { return _->Call(this); }
Node* Function::back_Call(Double* _) { return _->Call(this); }
Node* Function::back_Call(String* _) { return _->Call(this); }
Node* Function::back_Call(Array* _) { return _->Call(this); }
Node* Function::back_Call(Object* _) { return _->Call(this); }
Node* Function::back_Call(Function* _) { return _->Call(this); }
Node* Error::Equals(Node* _) { return _->back_Equals(this); }
Node* Error::back_Equals(Error* _) { return _->Equals(this); }
Node* Error::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Error::back_Equals(Integer* _) { return _->Equals(this); }
Node* Error::back_Equals(Double* _) { return _->Equals(this); }
Node* Error::back_Equals(String* _) { return _->Equals(this); }
Node* Error::back_Equals(Array* _) { return _->Equals(this); }
Node* Error::back_Equals(Object* _) { return _->Equals(this); }
Node* Error::back_Equals(Function* _) { return _->Equals(this); }
Node* Boolean::Equals(Node* _) { return _->back_Equals(this); }
Node* Boolean::back_Equals(Error* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Integer* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Double* _) { return _->Equals(this); }
Node* Boolean::back_Equals(String* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Array* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Object* _) { return _->Equals(this); }
Node* Boolean::back_Equals(Function* _) { return _->Equals(this); }
Node* Integer::Equals(Node* _) { return _->back_Equals(this); }
Node* Integer::back_Equals(Error* _) { return _->Equals(this); }
Node* Integer::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Integer::back_Equals(Integer* _) { return _->Equals(this); }
Node* Integer::back_Equals(Double* _) { return _->Equals(this); }
Node* Integer::back_Equals(String* _) { return _->Equals(this); }
Node* Integer::back_Equals(Array* _) { return _->Equals(this); }
Node* Integer::back_Equals(Object* _) { return _->Equals(this); }
Node* Integer::back_Equals(Function* _) { return _->Equals(this); }
Node* Double::Equals(Node* _) { return _->back_Equals(this); }
Node* Double::back_Equals(Error* _) { return _->Equals(this); }
Node* Double::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Double::back_Equals(Integer* _) { return _->Equals(this); }
Node* Double::back_Equals(Double* _) { return _->Equals(this); }
Node* Double::back_Equals(String* _) { return _->Equals(this); }
Node* Double::back_Equals(Array* _) { return _->Equals(this); }
Node* Double::back_Equals(Object* _) { return _->Equals(this); }
Node* Double::back_Equals(Function* _) { return _->Equals(this); }
Node* String::Equals(Node* _) { return _->back_Equals(this); }
Node* String::back_Equals(Error* _) { return _->Equals(this); }
Node* String::back_Equals(Boolean* _) { return _->Equals(this); }
Node* String::back_Equals(Integer* _) { return _->Equals(this); }
Node* String::back_Equals(Double* _) { return _->Equals(this); }
Node* String::back_Equals(String* _) { return _->Equals(this); }
Node* String::back_Equals(Array* _) { return _->Equals(this); }
Node* String::back_Equals(Object* _) { return _->Equals(this); }
Node* String::back_Equals(Function* _) { return _->Equals(this); }
Node* Array::Equals(Node* _) { return _->back_Equals(this); }
Node* Array::back_Equals(Error* _) { return _->Equals(this); }
Node* Array::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Array::back_Equals(Integer* _) { return _->Equals(this); }
Node* Array::back_Equals(Double* _) { return _->Equals(this); }
Node* Array::back_Equals(String* _) { return _->Equals(this); }
Node* Array::back_Equals(Array* _) { return _->Equals(this); }
Node* Array::back_Equals(Object* _) { return _->Equals(this); }
Node* Array::back_Equals(Function* _) { return _->Equals(this); }
Node* Object::Equals(Node* _) { return _->back_Equals(this); }
Node* Object::back_Equals(Error* _) { return _->Equals(this); }
Node* Object::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Object::back_Equals(Integer* _) { return _->Equals(this); }
Node* Object::back_Equals(Double* _) { return _->Equals(this); }
Node* Object::back_Equals(String* _) { return _->Equals(this); }
Node* Object::back_Equals(Array* _) { return _->Equals(this); }
Node* Object::back_Equals(Object* _) { return _->Equals(this); }
Node* Object::back_Equals(Function* _) { return _->Equals(this); }
Node* Function::Equals(Node* _) { return _->back_Equals(this); }
Node* Function::back_Equals(Error* _) { return _->Equals(this); }
Node* Function::back_Equals(Boolean* _) { return _->Equals(this); }
Node* Function::back_Equals(Integer* _) { return _->Equals(this); }
Node* Function::back_Equals(Double* _) { return _->Equals(this); }
Node* Function::back_Equals(String* _) { return _->Equals(this); }
Node* Function::back_Equals(Array* _) { return _->Equals(this); }
Node* Function::back_Equals(Object* _) { return _->Equals(this); }
Node* Function::back_Equals(Function* _) { return _->Equals(this); }
Node* Error::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Error::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Error::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Boolean::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Boolean::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Boolean::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Integer::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Integer::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Integer::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Double::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Double::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Double::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* String::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* String::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* String::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Array::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Array::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Array::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Object::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Object::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Object::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Function::NotEquals(Node* _) { return _->back_NotEquals(this); }
Node* Function::back_NotEquals(Error* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Boolean* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Integer* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Double* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(String* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Array* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Object* _) { return _->NotEquals(this); }
Node* Function::back_NotEquals(Function* _) { return _->NotEquals(this); }
Node* Error::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Error::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Error::back_LessThan(String* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Error::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Boolean::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Boolean::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(String* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Boolean::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Integer::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Integer::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(String* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Integer::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Double::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Double::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Double::back_LessThan(String* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Double::back_LessThan(Function* _) { return _->LessThan(this); }
Node* String::LessThan(Node* _) { return _->back_LessThan(this); }
Node* String::back_LessThan(Error* _) { return _->LessThan(this); }
Node* String::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* String::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* String::back_LessThan(Double* _) { return _->LessThan(this); }
Node* String::back_LessThan(String* _) { return _->LessThan(this); }
Node* String::back_LessThan(Array* _) { return _->LessThan(this); }
Node* String::back_LessThan(Object* _) { return _->LessThan(this); }
Node* String::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Array::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Array::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Array::back_LessThan(String* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Array::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Object::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Object::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Object::back_LessThan(String* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Object::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Function::LessThan(Node* _) { return _->back_LessThan(this); }
Node* Function::back_LessThan(Error* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Boolean* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Integer* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Double* _) { return _->LessThan(this); }
Node* Function::back_LessThan(String* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Array* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Object* _) { return _->LessThan(this); }
Node* Function::back_LessThan(Function* _) { return _->LessThan(this); }
Node* Error::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Error::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Error::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Boolean::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Boolean::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Boolean::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Integer::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Integer::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Integer::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Double::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Double::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Double::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* String::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* String::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* String::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Array::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Array::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Array::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Object::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Object::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Object::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Function::GreaterThan(Node* _) { return _->back_GreaterThan(this); }
Node* Function::back_GreaterThan(Error* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Boolean* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Integer* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Double* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(String* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Array* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Object* _) { return _->GreaterThan(this); }
Node* Function::back_GreaterThan(Function* _) { return _->GreaterThan(this); }
Node* Error::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Error::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Boolean::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Integer::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Double::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Double::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* String::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* String::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Array::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Array::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Object::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Object::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Function::LessThanOrEqualTo(Node* _) { return _->back_LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Error* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Boolean* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Integer* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Double* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(String* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Array* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Object* _) { return _->LessThanOrEqualTo(this); }
Node* Function::back_LessThanOrEqualTo(Function* _) { return _->LessThanOrEqualTo(this); }
Node* Error::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Error::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Boolean::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Integer::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Double::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* String::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Array::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Object::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::GreaterThanOrEqualTo(Node* _) { return _->back_GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Error* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Boolean* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Integer* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Double* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(String* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Array* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Object* _) { return _->GreaterThanOrEqualTo(this); }
Node* Function::back_GreaterThanOrEqualTo(Function* _) { return _->GreaterThanOrEqualTo(this); }

}