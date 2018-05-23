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

Node* Error::And(Error* _)
{
    return new Error;
}

Node* Error::And(Bool* _)
{
    return new Error;
}

Node* Error::And(Integer* _)
{
    return new Error;
}

Node* Error::And(Double* _)
{
    return new Error;
}

Node* Error::And(String* _)
{
    return new Error;
}

Node* Error::And(List* _)
{
    return new Error;
}

Node* Error::And(Object* _)
{
    return new Error;
}

Node* Error::And(Function* _)
{
    return new Error;
}

Node* Bool::And(Error* _)
{
    return new Error;
}

Node* Bool::And(Bool* _)
{
    return new Error;
}

Node* Bool::And(Integer* _)
{
    return new Error;
}

Node* Bool::And(Double* _)
{
    return new Error;
}

Node* Bool::And(String* _)
{
    return new Error;
}

Node* Bool::And(List* _)
{
    return new Error;
}

Node* Bool::And(Object* _)
{
    return new Error;
}

Node* Bool::And(Function* _)
{
    return new Error;
}

Integer::Integer(int value)
    : value(value)
{
}

Integer::Integer(const std::string& text)
{
    value = atoi(text.c_str());
}

std::string Integer::toString() const
{
    return std::to_string(value);
}

Node* Integer::And(Error* _)
{
    return new Error;
}

Node* Integer::And(Bool* _)
{
    return new Error;
}

Node* Integer::And(Integer* _)
{
    return new Error;
}

Node* Integer::And(Double* _)
{
    return new Error;
}

Node* Integer::And(String* _)
{
    return new Error;
}

Node* Integer::And(List* _)
{
    return new Error;
}

Node* Integer::And(Object* _)
{
    return new Error;
}

Node* Integer::And(Function* _)
{
    return new Error;
}

Double::Double(const std::string& text)
{
    value = atof(text.c_str());
}

std::string Double::toString() const
{
    return std::to_string(value);
}

Node* Double::And(Error* _)
{
    return new Error;
}

Node* Double::And(Bool* _)
{
    return new Error;
}

Node* Double::And(Integer* _)
{
    return new Error;
}

Node* Double::And(Double* _)
{
    return new Error;
}

Node* Double::And(String* _)
{
    return new Error;
}

Node* Double::And(List* _)
{
    return new Error;
}

Node* Double::And(Object* _)
{
    return new Error;
}

Node* Double::And(Function* _)
{
    return new Error;
}

Node* String::And(Error* _)
{
    return new Error;
}

Node* String::And(Bool* _)
{
    return new Error;
}

Node* String::And(Integer* _)
{
    return new Error;
}

Node* String::And(Double* _)
{
    return new Error;
}

Node* String::And(String* _)
{
    return new Error;
}

Node* String::And(List* _)
{
    return new Error;
}

Node* String::And(Object* _)
{
    return new Error;
}

Node* String::And(Function* _)
{
    return new Error;
}

Node* List::And(Error* _)
{
    return new Error;
}

Node* List::And(Bool* _)
{
    return new Error;
}

Node* List::And(Integer* _)
{
    return new Error;
}

Node* List::And(Double* _)
{
    return new Error;
}

Node* List::And(String* _)
{
    return new Error;
}

Node* List::And(List* _)
{
    return new Error;
}

Node* List::And(Object* _)
{
    return new Error;
}

Node* List::And(Function* _)
{
    return new Error;
}

Node* Object::And(Error* _)
{
    return new Error;
}

Node* Object::And(Bool* _)
{
    return new Error;
}

Node* Object::And(Integer* _)
{
    return new Error;
}

Node* Object::And(Double* _)
{
    return new Error;
}

Node* Object::And(String* _)
{
    return new Error;
}

Node* Object::And(List* _)
{
    return new Error;
}

Node* Object::And(Object* _)
{
    return new Error;
}

Node* Object::And(Function* _)
{
    return new Error;
}

Node* Function::And(Error* _)
{
    return new Error;
}

Node* Function::And(Bool* _)
{
    return new Error;
}

Node* Function::And(Integer* _)
{
    return new Error;
}

Node* Function::And(Double* _)
{
    return new Error;
}

Node* Function::And(String* _)
{
    return new Error;
}

Node* Function::And(List* _)
{
    return new Error;
}

Node* Function::And(Object* _)
{
    return new Error;
}

Node* Function::And(Function* _)
{
    return new Error;
}

Node* Error::Or(Error* _)
{
    return new Error;
}

Node* Error::Or(Bool* _)
{
    return new Error;
}

Node* Error::Or(Integer* _)
{
    return new Error;
}

Node* Error::Or(Double* _)
{
    return new Error;
}

Node* Error::Or(String* _)
{
    return new Error;
}

Node* Error::Or(List* _)
{
    return new Error;
}

Node* Error::Or(Object* _)
{
    return new Error;
}

Node* Error::Or(Function* _)
{
    return new Error;
}

Node* Bool::Or(Error* _)
{
    return new Error;
}

Node* Bool::Or(Bool* _)
{
    return new Error;
}

Node* Bool::Or(Integer* _)
{
    return new Error;
}

Node* Bool::Or(Double* _)
{
    return new Error;
}

Node* Bool::Or(String* _)
{
    return new Error;
}

Node* Bool::Or(List* _)
{
    return new Error;
}

Node* Bool::Or(Object* _)
{
    return new Error;
}

Node* Bool::Or(Function* _)
{
    return new Error;
}

Node* Integer::Or(Error* _)
{
    return new Error;
}

Node* Integer::Or(Bool* _)
{
    return new Error;
}

Node* Integer::Or(Integer* _)
{
    return new Error;
}

Node* Integer::Or(Double* _)
{
    return new Error;
}

Node* Integer::Or(String* _)
{
    return new Error;
}

Node* Integer::Or(List* _)
{
    return new Error;
}

Node* Integer::Or(Object* _)
{
    return new Error;
}

Node* Integer::Or(Function* _)
{
    return new Error;
}

Node* Double::Or(Error* _)
{
    return new Error;
}

Node* Double::Or(Bool* _)
{
    return new Error;
}

Node* Double::Or(Integer* _)
{
    return new Error;
}

Node* Double::Or(Double* _)
{
    return new Error;
}

Node* Double::Or(String* _)
{
    return new Error;
}

Node* Double::Or(List* _)
{
    return new Error;
}

Node* Double::Or(Object* _)
{
    return new Error;
}

Node* Double::Or(Function* _)
{
    return new Error;
}

Node* String::Or(Error* _)
{
    return new Error;
}

Node* String::Or(Bool* _)
{
    return new Error;
}

Node* String::Or(Integer* _)
{
    return new Error;
}

Node* String::Or(Double* _)
{
    return new Error;
}

Node* String::Or(String* _)
{
    return new Error;
}

Node* String::Or(List* _)
{
    return new Error;
}

Node* String::Or(Object* _)
{
    return new Error;
}

Node* String::Or(Function* _)
{
    return new Error;
}

Node* List::Or(Error* _)
{
    return new Error;
}

Node* List::Or(Bool* _)
{
    return new Error;
}

Node* List::Or(Integer* _)
{
    return new Error;
}

Node* List::Or(Double* _)
{
    return new Error;
}

Node* List::Or(String* _)
{
    return new Error;
}

Node* List::Or(List* _)
{
    return new Error;
}

Node* List::Or(Object* _)
{
    return new Error;
}

Node* List::Or(Function* _)
{
    return new Error;
}

Node* Object::Or(Error* _)
{
    return new Error;
}

Node* Object::Or(Bool* _)
{
    return new Error;
}

Node* Object::Or(Integer* _)
{
    return new Error;
}

Node* Object::Or(Double* _)
{
    return new Error;
}

Node* Object::Or(String* _)
{
    return new Error;
}

Node* Object::Or(List* _)
{
    return new Error;
}

Node* Object::Or(Object* _)
{
    return new Error;
}

Node* Object::Or(Function* _)
{
    return new Error;
}

Node* Function::Or(Error* _)
{
    return new Error;
}

Node* Function::Or(Bool* _)
{
    return new Error;
}

Node* Function::Or(Integer* _)
{
    return new Error;
}

Node* Function::Or(Double* _)
{
    return new Error;
}

Node* Function::Or(String* _)
{
    return new Error;
}

Node* Function::Or(List* _)
{
    return new Error;
}

Node* Function::Or(Object* _)
{
    return new Error;
}

Node* Function::Or(Function* _)
{
    return new Error;
}

Node* Error::Plus(Error* _)
{
    return new Error;
}

Node* Error::Plus(Bool* _)
{
    return new Error;
}

Node* Error::Plus(Integer* _)
{
    return new Error;
}

Node* Error::Plus(Double* _)
{
    return new Error;
}

Node* Error::Plus(String* _)
{
    return new Error;
}

Node* Error::Plus(List* _)
{
    return new Error;
}

Node* Error::Plus(Object* _)
{
    return new Error;
}

Node* Error::Plus(Function* _)
{
    return new Error;
}

Node* Bool::Plus(Error* _)
{
    return new Error;
}

Node* Bool::Plus(Bool* _)
{
    return new Error;
}

Node* Bool::Plus(Integer* _)
{
    return new Error;
}

Node* Bool::Plus(Double* _)
{
    return new Error;
}

Node* Bool::Plus(String* _)
{
    return new Error;
}

Node* Bool::Plus(List* _)
{
    return new Error;
}

Node* Bool::Plus(Object* _)
{
    return new Error;
}

Node* Bool::Plus(Function* _)
{
    return new Error;
}

Node* Integer::Plus(Error* _)
{
    return new Error;
}

Node* Integer::Plus(Bool* _)
{
    return new Error;
}

Node* Integer::Plus(Integer* _)
{
    return new Integer(value + _->value);
}

Node* Integer::Plus(Double* _)
{
    return new Error;
}

Node* Integer::Plus(String* _)
{
    return new Error;
}

Node* Integer::Plus(List* _)
{
    return new Error;
}

Node* Integer::Plus(Object* _)
{
    return new Error;
}

Node* Integer::Plus(Function* _)
{
    return new Error;
}

Node* Double::Plus(Error* _)
{
    return new Error;
}

Node* Double::Plus(Bool* _)
{
    return new Error;
}

Node* Double::Plus(Integer* _)
{
    return new Error;
}

Node* Double::Plus(Double* _)
{
    return new Error;
}

Node* Double::Plus(String* _)
{
    return new Error;
}

Node* Double::Plus(List* _)
{
    return new Error;
}

Node* Double::Plus(Object* _)
{
    return new Error;
}

Node* Double::Plus(Function* _)
{
    return new Error;
}

Node* String::Plus(Error* _)
{
    return new Error;
}

Node* String::Plus(Bool* _)
{
    return new Error;
}

Node* String::Plus(Integer* _)
{
    return new Error;
}

Node* String::Plus(Double* _)
{
    return new Error;
}

Node* String::Plus(String* _)
{
    return new Error;
}

Node* String::Plus(List* _)
{
    return new Error;
}

Node* String::Plus(Object* _)
{
    return new Error;
}

Node* String::Plus(Function* _)
{
    return new Error;
}

Node* List::Plus(Error* _)
{
    return new Error;
}

Node* List::Plus(Bool* _)
{
    return new Error;
}

Node* List::Plus(Integer* _)
{
    return new Error;
}

Node* List::Plus(Double* _)
{
    return new Error;
}

Node* List::Plus(String* _)
{
    return new Error;
}

Node* List::Plus(List* _)
{
    return new Error;
}

Node* List::Plus(Object* _)
{
    return new Error;
}

Node* List::Plus(Function* _)
{
    return new Error;
}

Node* Object::Plus(Error* _)
{
    return new Error;
}

Node* Object::Plus(Bool* _)
{
    return new Error;
}

Node* Object::Plus(Integer* _)
{
    return new Error;
}

Node* Object::Plus(Double* _)
{
    return new Error;
}

Node* Object::Plus(String* _)
{
    return new Error;
}

Node* Object::Plus(List* _)
{
    return new Error;
}

Node* Object::Plus(Object* _)
{
    return new Error;
}

Node* Object::Plus(Function* _)
{
    return new Error;
}

Node* Function::Plus(Error* _)
{
    return new Error;
}

Node* Function::Plus(Bool* _)
{
    return new Error;
}

Node* Function::Plus(Integer* _)
{
    return new Error;
}

Node* Function::Plus(Double* _)
{
    return new Error;
}

Node* Function::Plus(String* _)
{
    return new Error;
}

Node* Function::Plus(List* _)
{
    return new Error;
}

Node* Function::Plus(Object* _)
{
    return new Error;
}

Node* Function::Plus(Function* _)
{
    return new Error;
}

Node* Error::Minus(Error* _)
{
    return new Error;
}

Node* Error::Minus(Bool* _)
{
    return new Error;
}

Node* Error::Minus(Integer* _)
{
    return new Error;
}

Node* Error::Minus(Double* _)
{
    return new Error;
}

Node* Error::Minus(String* _)
{
    return new Error;
}

Node* Error::Minus(List* _)
{
    return new Error;
}

Node* Error::Minus(Object* _)
{
    return new Error;
}

Node* Error::Minus(Function* _)
{
    return new Error;
}

Node* Bool::Minus(Error* _)
{
    return new Error;
}

Node* Bool::Minus(Bool* _)
{
    return new Error;
}

Node* Bool::Minus(Integer* _)
{
    return new Error;
}

Node* Bool::Minus(Double* _)
{
    return new Error;
}

Node* Bool::Minus(String* _)
{
    return new Error;
}

Node* Bool::Minus(List* _)
{
    return new Error;
}

Node* Bool::Minus(Object* _)
{
    return new Error;
}

Node* Bool::Minus(Function* _)
{
    return new Error;
}

Node* Integer::Minus(Error* _)
{
    return _;
}

Node* Integer::Minus(Bool* _)
{
    return new Error;
}

Node* Integer::Minus(Integer* _)
{
    return new Integer(value - _->value);
}

Node* Integer::Minus(Double* _)
{
    return new Error;
}

Node* Integer::Minus(String* _)
{
    return new Error;
}

Node* Integer::Minus(List* _)
{
    return new Error;
}

Node* Integer::Minus(Object* _)
{
    return new Error;
}

Node* Integer::Minus(Function* _)
{
    return new Error;
}

Node* Double::Minus(Error* _)
{
    return new Error;
}

Node* Double::Minus(Bool* _)
{
    return new Error;
}

Node* Double::Minus(Integer* _)
{
    return new Error;
}

Node* Double::Minus(Double* _)
{
    return new Error;
}

Node* Double::Minus(String* _)
{
    return new Error;
}

Node* Double::Minus(List* _)
{
    return new Error;
}

Node* Double::Minus(Object* _)
{
    return new Error;
}

Node* Double::Minus(Function* _)
{
    return new Error;
}

Node* String::Minus(Error* _)
{
    return new Error;
}

Node* String::Minus(Bool* _)
{
    return new Error;
}

Node* String::Minus(Integer* _)
{
    return new Error;
}

Node* String::Minus(Double* _)
{
    return new Error;
}

Node* String::Minus(String* _)
{
    return new Error;
}

Node* String::Minus(List* _)
{
    return new Error;
}

Node* String::Minus(Object* _)
{
    return new Error;
}

Node* String::Minus(Function* _)
{
    return new Error;
}

Node* List::Minus(Error* _)
{
    return new Error;
}

Node* List::Minus(Bool* _)
{
    return new Error;
}

Node* List::Minus(Integer* _)
{
    return new Error;
}

Node* List::Minus(Double* _)
{
    return new Error;
}

Node* List::Minus(String* _)
{
    return new Error;
}

Node* List::Minus(List* _)
{
    return new Error;
}

Node* List::Minus(Object* _)
{
    return new Error;
}

Node* List::Minus(Function* _)
{
    return new Error;
}

Node* Object::Minus(Error* _)
{
    return new Error;
}

Node* Object::Minus(Bool* _)
{
    return new Error;
}

Node* Object::Minus(Integer* _)
{
    return new Error;
}

Node* Object::Minus(Double* _)
{
    return new Error;
}

Node* Object::Minus(String* _)
{
    return new Error;
}

Node* Object::Minus(List* _)
{
    return new Error;
}

Node* Object::Minus(Object* _)
{
    return new Error;
}

Node* Object::Minus(Function* _)
{
    return new Error;
}

Node* Function::Minus(Error* _)
{
    return new Error;
}

Node* Function::Minus(Bool* _)
{
    return new Error;
}

Node* Function::Minus(Integer* _)
{
    return new Error;
}

Node* Function::Minus(Double* _)
{
    return new Error;
}

Node* Function::Minus(String* _)
{
    return new Error;
}

Node* Function::Minus(List* _)
{
    return new Error;
}

Node* Function::Minus(Object* _)
{
    return new Error;
}

Node* Function::Minus(Function* _)
{
    return new Error;
}

Node* Error::Times(Error* _)
{
    return new Error;
}

Node* Error::Times(Bool* _)
{
    return new Error;
}

Node* Error::Times(Integer* _)
{
    return new Error;
}

Node* Error::Times(Double* _)
{
    return new Error;
}

Node* Error::Times(String* _)
{
    return new Error;
}

Node* Error::Times(List* _)
{
    return new Error;
}

Node* Error::Times(Object* _)
{
    return new Error;
}

Node* Error::Times(Function* _)
{
    return new Error;
}

Node* Bool::Times(Error* _)
{
    return new Error;
}

Node* Bool::Times(Bool* _)
{
    return new Error;
}

Node* Bool::Times(Integer* _)
{
    return new Error;
}

Node* Bool::Times(Double* _)
{
    return new Error;
}

Node* Bool::Times(String* _)
{
    return new Error;
}

Node* Bool::Times(List* _)
{
    return new Error;
}

Node* Bool::Times(Object* _)
{
    return new Error;
}

Node* Bool::Times(Function* _)
{
    return new Error;
}

Node* Integer::Times(Error* _)
{
    return new Error;
}

Node* Integer::Times(Bool* _)
{
    return new Error;
}

Node* Integer::Times(Integer* _)
{
    return new Error;
}

Node* Integer::Times(Double* _)
{
    return new Error;
}

Node* Integer::Times(String* _)
{
    return new Error;
}

Node* Integer::Times(List* _)
{
    return new Error;
}

Node* Integer::Times(Object* _)
{
    return new Error;
}

Node* Integer::Times(Function* _)
{
    return new Error;
}

Node* Double::Times(Error* _)
{
    return new Error;
}

Node* Double::Times(Bool* _)
{
    return new Error;
}

Node* Double::Times(Integer* _)
{
    return new Error;
}

Node* Double::Times(Double* _)
{
    return new Error;
}

Node* Double::Times(String* _)
{
    return new Error;
}

Node* Double::Times(List* _)
{
    return new Error;
}

Node* Double::Times(Object* _)
{
    return new Error;
}

Node* Double::Times(Function* _)
{
    return new Error;
}

Node* String::Times(Error* _)
{
    return new Error;
}

Node* String::Times(Bool* _)
{
    return new Error;
}

Node* String::Times(Integer* _)
{
    return new Error;
}

Node* String::Times(Double* _)
{
    return new Error;
}

Node* String::Times(String* _)
{
    return new Error;
}

Node* String::Times(List* _)
{
    return new Error;
}

Node* String::Times(Object* _)
{
    return new Error;
}

Node* String::Times(Function* _)
{
    return new Error;
}

Node* List::Times(Error* _)
{
    return new Error;
}

Node* List::Times(Bool* _)
{
    return new Error;
}

Node* List::Times(Integer* _)
{
    return new Error;
}

Node* List::Times(Double* _)
{
    return new Error;
}

Node* List::Times(String* _)
{
    return new Error;
}

Node* List::Times(List* _)
{
    return new Error;
}

Node* List::Times(Object* _)
{
    return new Error;
}

Node* List::Times(Function* _)
{
    return new Error;
}

Node* Object::Times(Error* _)
{
    return new Error;
}

Node* Object::Times(Bool* _)
{
    return new Error;
}

Node* Object::Times(Integer* _)
{
    return new Error;
}

Node* Object::Times(Double* _)
{
    return new Error;
}

Node* Object::Times(String* _)
{
    return new Error;
}

Node* Object::Times(List* _)
{
    return new Error;
}

Node* Object::Times(Object* _)
{
    return new Error;
}

Node* Object::Times(Function* _)
{
    return new Error;
}

Node* Function::Times(Error* _)
{
    return new Error;
}

Node* Function::Times(Bool* _)
{
    return new Error;
}

Node* Function::Times(Integer* _)
{
    return new Error;
}

Node* Function::Times(Double* _)
{
    return new Error;
}

Node* Function::Times(String* _)
{
    return new Error;
}

Node* Function::Times(List* _)
{
    return new Error;
}

Node* Function::Times(Object* _)
{
    return new Error;
}

Node* Function::Times(Function* _)
{
    return new Error;
}

Node* Error::DividedBy(Error* _)
{
    return new Error;
}

Node* Error::DividedBy(Bool* _)
{
    return new Error;
}

Node* Error::DividedBy(Integer* _)
{
    return new Error;
}

Node* Error::DividedBy(Double* _)
{
    return new Error;
}

Node* Error::DividedBy(String* _)
{
    return new Error;
}

Node* Error::DividedBy(List* _)
{
    return new Error;
}

Node* Error::DividedBy(Object* _)
{
    return new Error;
}

Node* Error::DividedBy(Function* _)
{
    return new Error;
}

Node* Bool::DividedBy(Error* _)
{
    return new Error;
}

Node* Bool::DividedBy(Bool* _)
{
    return new Error;
}

Node* Bool::DividedBy(Integer* _)
{
    return new Error;
}

Node* Bool::DividedBy(Double* _)
{
    return new Error;
}

Node* Bool::DividedBy(String* _)
{
    return new Error;
}

Node* Bool::DividedBy(List* _)
{
    return new Error;
}

Node* Bool::DividedBy(Object* _)
{
    return new Error;
}

Node* Bool::DividedBy(Function* _)
{
    return new Error;
}

Node* Integer::DividedBy(Error* _)
{
    return new Error;
}

Node* Integer::DividedBy(Bool* _)
{
    return new Error;
}

Node* Integer::DividedBy(Integer* _)
{
    return new Error;
}

Node* Integer::DividedBy(Double* _)
{
    return new Error;
}

Node* Integer::DividedBy(String* _)
{
    return new Error;
}

Node* Integer::DividedBy(List* _)
{
    return new Error;
}

Node* Integer::DividedBy(Object* _)
{
    return new Error;
}

Node* Integer::DividedBy(Function* _)
{
    return new Error;
}

Node* Double::DividedBy(Error* _)
{
    return new Error;
}

Node* Double::DividedBy(Bool* _)
{
    return new Error;
}

Node* Double::DividedBy(Integer* _)
{
    return new Error;
}

Node* Double::DividedBy(Double* _)
{
    return new Error;
}

Node* Double::DividedBy(String* _)
{
    return new Error;
}

Node* Double::DividedBy(List* _)
{
    return new Error;
}

Node* Double::DividedBy(Object* _)
{
    return new Error;
}

Node* Double::DividedBy(Function* _)
{
    return new Error;
}

Node* String::DividedBy(Error* _)
{
    return new Error;
}

Node* String::DividedBy(Bool* _)
{
    return new Error;
}

Node* String::DividedBy(Integer* _)
{
    return new Error;
}

Node* String::DividedBy(Double* _)
{
    return new Error;
}

Node* String::DividedBy(String* _)
{
    return new Error;
}

Node* String::DividedBy(List* _)
{
    return new Error;
}

Node* String::DividedBy(Object* _)
{
    return new Error;
}

Node* String::DividedBy(Function* _)
{
    return new Error;
}

Node* List::DividedBy(Error* _)
{
    return new Error;
}

Node* List::DividedBy(Bool* _)
{
    return new Error;
}

Node* List::DividedBy(Integer* _)
{
    return new Error;
}

Node* List::DividedBy(Double* _)
{
    return new Error;
}

Node* List::DividedBy(String* _)
{
    return new Error;
}

Node* List::DividedBy(List* _)
{
    return new Error;
}

Node* List::DividedBy(Object* _)
{
    return new Error;
}

Node* List::DividedBy(Function* _)
{
    return new Error;
}

Node* Object::DividedBy(Error* _)
{
    return new Error;
}

Node* Object::DividedBy(Bool* _)
{
    return new Error;
}

Node* Object::DividedBy(Integer* _)
{
    return new Error;
}

Node* Object::DividedBy(Double* _)
{
    return new Error;
}

Node* Object::DividedBy(String* _)
{
    return new Error;
}

Node* Object::DividedBy(List* _)
{
    return new Error;
}

Node* Object::DividedBy(Object* _)
{
    return new Error;
}

Node* Object::DividedBy(Function* _)
{
    return new Error;
}

Node* Function::DividedBy(Error* _)
{
    return new Error;
}

Node* Function::DividedBy(Bool* _)
{
    return new Error;
}

Node* Function::DividedBy(Integer* _)
{
    return new Error;
}

Node* Function::DividedBy(Double* _)
{
    return new Error;
}

Node* Function::DividedBy(String* _)
{
    return new Error;
}

Node* Function::DividedBy(List* _)
{
    return new Error;
}

Node* Function::DividedBy(Object* _)
{
    return new Error;
}

Node* Function::DividedBy(Function* _)
{
    return new Error;
}

Node* Error::Mod(Error* _)
{
    return new Error;
}

Node* Error::Mod(Bool* _)
{
    return new Error;
}

Node* Error::Mod(Integer* _)
{
    return new Error;
}

Node* Error::Mod(Double* _)
{
    return new Error;
}

Node* Error::Mod(String* _)
{
    return new Error;
}

Node* Error::Mod(List* _)
{
    return new Error;
}

Node* Error::Mod(Object* _)
{
    return new Error;
}

Node* Error::Mod(Function* _)
{
    return new Error;
}

Node* Bool::Mod(Error* _)
{
    return new Error;
}

Node* Bool::Mod(Bool* _)
{
    return new Error;
}

Node* Bool::Mod(Integer* _)
{
    return new Error;
}

Node* Bool::Mod(Double* _)
{
    return new Error;
}

Node* Bool::Mod(String* _)
{
    return new Error;
}

Node* Bool::Mod(List* _)
{
    return new Error;
}

Node* Bool::Mod(Object* _)
{
    return new Error;
}

Node* Bool::Mod(Function* _)
{
    return new Error;
}

Node* Integer::Mod(Error* _)
{
    return new Error;
}

Node* Integer::Mod(Bool* _)
{
    return new Error;
}

Node* Integer::Mod(Integer* _)
{
    return new Error;
}

Node* Integer::Mod(Double* _)
{
    return new Error;
}

Node* Integer::Mod(String* _)
{
    return new Error;
}

Node* Integer::Mod(List* _)
{
    return new Error;
}

Node* Integer::Mod(Object* _)
{
    return new Error;
}

Node* Integer::Mod(Function* _)
{
    return new Error;
}

Node* Double::Mod(Error* _)
{
    return new Error;
}

Node* Double::Mod(Bool* _)
{
    return new Error;
}

Node* Double::Mod(Integer* _)
{
    return new Error;
}

Node* Double::Mod(Double* _)
{
    return new Error;
}

Node* Double::Mod(String* _)
{
    return new Error;
}

Node* Double::Mod(List* _)
{
    return new Error;
}

Node* Double::Mod(Object* _)
{
    return new Error;
}

Node* Double::Mod(Function* _)
{
    return new Error;
}

Node* String::Mod(Error* _)
{
    return new Error;
}

Node* String::Mod(Bool* _)
{
    return new Error;
}

Node* String::Mod(Integer* _)
{
    return new Error;
}

Node* String::Mod(Double* _)
{
    return new Error;
}

Node* String::Mod(String* _)
{
    return new Error;
}

Node* String::Mod(List* _)
{
    return new Error;
}

Node* String::Mod(Object* _)
{
    return new Error;
}

Node* String::Mod(Function* _)
{
    return new Error;
}

Node* List::Mod(Error* _)
{
    return new Error;
}

Node* List::Mod(Bool* _)
{
    return new Error;
}

Node* List::Mod(Integer* _)
{
    return new Error;
}

Node* List::Mod(Double* _)
{
    return new Error;
}

Node* List::Mod(String* _)
{
    return new Error;
}

Node* List::Mod(List* _)
{
    return new Error;
}

Node* List::Mod(Object* _)
{
    return new Error;
}

Node* List::Mod(Function* _)
{
    return new Error;
}

Node* Object::Mod(Error* _)
{
    return new Error;
}

Node* Object::Mod(Bool* _)
{
    return new Error;
}

Node* Object::Mod(Integer* _)
{
    return new Error;
}

Node* Object::Mod(Double* _)
{
    return new Error;
}

Node* Object::Mod(String* _)
{
    return new Error;
}

Node* Object::Mod(List* _)
{
    return new Error;
}

Node* Object::Mod(Object* _)
{
    return new Error;
}

Node* Object::Mod(Function* _)
{
    return new Error;
}

Node* Function::Mod(Error* _)
{
    return new Error;
}

Node* Function::Mod(Bool* _)
{
    return new Error;
}

Node* Function::Mod(Integer* _)
{
    return new Error;
}

Node* Function::Mod(Double* _)
{
    return new Error;
}

Node* Function::Mod(String* _)
{
    return new Error;
}

Node* Function::Mod(List* _)
{
    return new Error;
}

Node* Function::Mod(Object* _)
{
    return new Error;
}

Node* Function::Mod(Function* _)
{
    return new Error;
}

Node* Error::Call(Error* _)
{
    return new Error;
}

Node* Error::Call(Bool* _)
{
    return new Error;
}

Node* Error::Call(Integer* _)
{
    return new Error;
}

Node* Error::Call(Double* _)
{
    return new Error;
}

Node* Error::Call(String* _)
{
    return new Error;
}

Node* Error::Call(List* _)
{
    return new Error;
}

Node* Error::Call(Object* _)
{
    return new Error;
}

Node* Error::Call(Function* _)
{
    return new Error;
}

Node* Bool::Call(Error* _)
{
    return new Error;
}

Node* Bool::Call(Bool* _)
{
    return new Error;
}

Node* Bool::Call(Integer* _)
{
    return new Error;
}

Node* Bool::Call(Double* _)
{
    return new Error;
}

Node* Bool::Call(String* _)
{
    return new Error;
}

Node* Bool::Call(List* _)
{
    return new Error;
}

Node* Bool::Call(Object* _)
{
    return new Error;
}

Node* Bool::Call(Function* _)
{
    return new Error;
}

Node* Integer::Call(Error* _)
{
    return new Error;
}

Node* Integer::Call(Bool* _)
{
    return new Error;
}

Node* Integer::Call(Integer* _)
{
    return new Error;
}

Node* Integer::Call(Double* _)
{
    return new Error;
}

Node* Integer::Call(String* _)
{
    return new Error;
}

Node* Integer::Call(List* _)
{
    return new Error;
}

Node* Integer::Call(Object* _)
{
    return new Error;
}

Node* Integer::Call(Function* _)
{
    return new Error;
}

Node* Double::Call(Error* _)
{
    return new Error;
}

Node* Double::Call(Bool* _)
{
    return new Error;
}

Node* Double::Call(Integer* _)
{
    return new Error;
}

Node* Double::Call(Double* _)
{
    return new Error;
}

Node* Double::Call(String* _)
{
    return new Error;
}

Node* Double::Call(List* _)
{
    return new Error;
}

Node* Double::Call(Object* _)
{
    return new Error;
}

Node* Double::Call(Function* _)
{
    return new Error;
}

Node* String::Call(Error* _)
{
    return new Error;
}

Node* String::Call(Bool* _)
{
    return new Error;
}

Node* String::Call(Integer* _)
{
    return new Error;
}

Node* String::Call(Double* _)
{
    return new Error;
}

Node* String::Call(String* _)
{
    return new Error;
}

Node* String::Call(List* _)
{
    return new Error;
}

Node* String::Call(Object* _)
{
    return new Error;
}

Node* String::Call(Function* _)
{
    return new Error;
}

Node* List::Call(Error* _)
{
    return new Error;
}

Node* List::Call(Bool* _)
{
    return new Error;
}

Node* List::Call(Integer* _)
{
    return new Error;
}

Node* List::Call(Double* _)
{
    return new Error;
}

Node* List::Call(String* _)
{
    return new Error;
}

Node* List::Call(List* _)
{
    return new Error;
}

Node* List::Call(Object* _)
{
    return new Error;
}

Node* List::Call(Function* _)
{
    return new Error;
}

Node* Object::Call(Error* _)
{
    return new Error;
}

Node* Object::Call(Bool* _)
{
    return new Error;
}

Node* Object::Call(Integer* _)
{
    return new Error;
}

Node* Object::Call(Double* _)
{
    return new Error;
}

Node* Object::Call(String* _)
{
    return new Error;
}

Node* Object::Call(List* _)
{
    return new Error;
}

Node* Object::Call(Object* _)
{
    return new Error;
}

Node* Object::Call(Function* _)
{
    return new Error;
}

Node* Function::Call(Error* _)
{
    return new Error;
}

Node* Function::Call(Bool* _)
{
    return new Error;
}

Node* Function::Call(Integer* _)
{
    return new Error;
}

Node* Function::Call(Double* _)
{
    return new Error;
}

Node* Function::Call(String* _)
{
    return new Error;
}

Node* Function::Call(List* _)
{
    return new Error;
}

Node* Function::Call(Object* _)
{
    return new Error;
}

Node* Function::Call(Function* _)
{
    return new Error;
}
Node* Error::And(Node* _) { return _->back_And(this); }
Node* Error::back_And(Error* _) { return _->And(this); }
Node* Error::back_And(Bool* _) { return _->And(this); }
Node* Error::back_And(Integer* _) { return _->And(this); }
Node* Error::back_And(Double* _) { return _->And(this); }
Node* Error::back_And(String* _) { return _->And(this); }
Node* Error::back_And(List* _) { return _->And(this); }
Node* Error::back_And(Object* _) { return _->And(this); }
Node* Error::back_And(Function* _) { return _->And(this); }
Node* Bool::And(Node* _) { return _->back_And(this); }
Node* Bool::back_And(Error* _) { return _->And(this); }
Node* Bool::back_And(Bool* _) { return _->And(this); }
Node* Bool::back_And(Integer* _) { return _->And(this); }
Node* Bool::back_And(Double* _) { return _->And(this); }
Node* Bool::back_And(String* _) { return _->And(this); }
Node* Bool::back_And(List* _) { return _->And(this); }
Node* Bool::back_And(Object* _) { return _->And(this); }
Node* Bool::back_And(Function* _) { return _->And(this); }
Node* Integer::And(Node* _) { return _->back_And(this); }
Node* Integer::back_And(Error* _) { return _->And(this); }
Node* Integer::back_And(Bool* _) { return _->And(this); }
Node* Integer::back_And(Integer* _) { return _->And(this); }
Node* Integer::back_And(Double* _) { return _->And(this); }
Node* Integer::back_And(String* _) { return _->And(this); }
Node* Integer::back_And(List* _) { return _->And(this); }
Node* Integer::back_And(Object* _) { return _->And(this); }
Node* Integer::back_And(Function* _) { return _->And(this); }
Node* Double::And(Node* _) { return _->back_And(this); }
Node* Double::back_And(Error* _) { return _->And(this); }
Node* Double::back_And(Bool* _) { return _->And(this); }
Node* Double::back_And(Integer* _) { return _->And(this); }
Node* Double::back_And(Double* _) { return _->And(this); }
Node* Double::back_And(String* _) { return _->And(this); }
Node* Double::back_And(List* _) { return _->And(this); }
Node* Double::back_And(Object* _) { return _->And(this); }
Node* Double::back_And(Function* _) { return _->And(this); }
Node* String::And(Node* _) { return _->back_And(this); }
Node* String::back_And(Error* _) { return _->And(this); }
Node* String::back_And(Bool* _) { return _->And(this); }
Node* String::back_And(Integer* _) { return _->And(this); }
Node* String::back_And(Double* _) { return _->And(this); }
Node* String::back_And(String* _) { return _->And(this); }
Node* String::back_And(List* _) { return _->And(this); }
Node* String::back_And(Object* _) { return _->And(this); }
Node* String::back_And(Function* _) { return _->And(this); }
Node* List::And(Node* _) { return _->back_And(this); }
Node* List::back_And(Error* _) { return _->And(this); }
Node* List::back_And(Bool* _) { return _->And(this); }
Node* List::back_And(Integer* _) { return _->And(this); }
Node* List::back_And(Double* _) { return _->And(this); }
Node* List::back_And(String* _) { return _->And(this); }
Node* List::back_And(List* _) { return _->And(this); }
Node* List::back_And(Object* _) { return _->And(this); }
Node* List::back_And(Function* _) { return _->And(this); }
Node* Object::And(Node* _) { return _->back_And(this); }
Node* Object::back_And(Error* _) { return _->And(this); }
Node* Object::back_And(Bool* _) { return _->And(this); }
Node* Object::back_And(Integer* _) { return _->And(this); }
Node* Object::back_And(Double* _) { return _->And(this); }
Node* Object::back_And(String* _) { return _->And(this); }
Node* Object::back_And(List* _) { return _->And(this); }
Node* Object::back_And(Object* _) { return _->And(this); }
Node* Object::back_And(Function* _) { return _->And(this); }
Node* Function::And(Node* _) { return _->back_And(this); }
Node* Function::back_And(Error* _) { return _->And(this); }
Node* Function::back_And(Bool* _) { return _->And(this); }
Node* Function::back_And(Integer* _) { return _->And(this); }
Node* Function::back_And(Double* _) { return _->And(this); }
Node* Function::back_And(String* _) { return _->And(this); }
Node* Function::back_And(List* _) { return _->And(this); }
Node* Function::back_And(Object* _) { return _->And(this); }
Node* Function::back_And(Function* _) { return _->And(this); }
Node* Error::Or(Node* _) { return _->back_Or(this); }
Node* Error::back_Or(Error* _) { return _->Or(this); }
Node* Error::back_Or(Bool* _) { return _->Or(this); }
Node* Error::back_Or(Integer* _) { return _->Or(this); }
Node* Error::back_Or(Double* _) { return _->Or(this); }
Node* Error::back_Or(String* _) { return _->Or(this); }
Node* Error::back_Or(List* _) { return _->Or(this); }
Node* Error::back_Or(Object* _) { return _->Or(this); }
Node* Error::back_Or(Function* _) { return _->Or(this); }
Node* Bool::Or(Node* _) { return _->back_Or(this); }
Node* Bool::back_Or(Error* _) { return _->Or(this); }
Node* Bool::back_Or(Bool* _) { return _->Or(this); }
Node* Bool::back_Or(Integer* _) { return _->Or(this); }
Node* Bool::back_Or(Double* _) { return _->Or(this); }
Node* Bool::back_Or(String* _) { return _->Or(this); }
Node* Bool::back_Or(List* _) { return _->Or(this); }
Node* Bool::back_Or(Object* _) { return _->Or(this); }
Node* Bool::back_Or(Function* _) { return _->Or(this); }
Node* Integer::Or(Node* _) { return _->back_Or(this); }
Node* Integer::back_Or(Error* _) { return _->Or(this); }
Node* Integer::back_Or(Bool* _) { return _->Or(this); }
Node* Integer::back_Or(Integer* _) { return _->Or(this); }
Node* Integer::back_Or(Double* _) { return _->Or(this); }
Node* Integer::back_Or(String* _) { return _->Or(this); }
Node* Integer::back_Or(List* _) { return _->Or(this); }
Node* Integer::back_Or(Object* _) { return _->Or(this); }
Node* Integer::back_Or(Function* _) { return _->Or(this); }
Node* Double::Or(Node* _) { return _->back_Or(this); }
Node* Double::back_Or(Error* _) { return _->Or(this); }
Node* Double::back_Or(Bool* _) { return _->Or(this); }
Node* Double::back_Or(Integer* _) { return _->Or(this); }
Node* Double::back_Or(Double* _) { return _->Or(this); }
Node* Double::back_Or(String* _) { return _->Or(this); }
Node* Double::back_Or(List* _) { return _->Or(this); }
Node* Double::back_Or(Object* _) { return _->Or(this); }
Node* Double::back_Or(Function* _) { return _->Or(this); }
Node* String::Or(Node* _) { return _->back_Or(this); }
Node* String::back_Or(Error* _) { return _->Or(this); }
Node* String::back_Or(Bool* _) { return _->Or(this); }
Node* String::back_Or(Integer* _) { return _->Or(this); }
Node* String::back_Or(Double* _) { return _->Or(this); }
Node* String::back_Or(String* _) { return _->Or(this); }
Node* String::back_Or(List* _) { return _->Or(this); }
Node* String::back_Or(Object* _) { return _->Or(this); }
Node* String::back_Or(Function* _) { return _->Or(this); }
Node* List::Or(Node* _) { return _->back_Or(this); }
Node* List::back_Or(Error* _) { return _->Or(this); }
Node* List::back_Or(Bool* _) { return _->Or(this); }
Node* List::back_Or(Integer* _) { return _->Or(this); }
Node* List::back_Or(Double* _) { return _->Or(this); }
Node* List::back_Or(String* _) { return _->Or(this); }
Node* List::back_Or(List* _) { return _->Or(this); }
Node* List::back_Or(Object* _) { return _->Or(this); }
Node* List::back_Or(Function* _) { return _->Or(this); }
Node* Object::Or(Node* _) { return _->back_Or(this); }
Node* Object::back_Or(Error* _) { return _->Or(this); }
Node* Object::back_Or(Bool* _) { return _->Or(this); }
Node* Object::back_Or(Integer* _) { return _->Or(this); }
Node* Object::back_Or(Double* _) { return _->Or(this); }
Node* Object::back_Or(String* _) { return _->Or(this); }
Node* Object::back_Or(List* _) { return _->Or(this); }
Node* Object::back_Or(Object* _) { return _->Or(this); }
Node* Object::back_Or(Function* _) { return _->Or(this); }
Node* Function::Or(Node* _) { return _->back_Or(this); }
Node* Function::back_Or(Error* _) { return _->Or(this); }
Node* Function::back_Or(Bool* _) { return _->Or(this); }
Node* Function::back_Or(Integer* _) { return _->Or(this); }
Node* Function::back_Or(Double* _) { return _->Or(this); }
Node* Function::back_Or(String* _) { return _->Or(this); }
Node* Function::back_Or(List* _) { return _->Or(this); }
Node* Function::back_Or(Object* _) { return _->Or(this); }
Node* Function::back_Or(Function* _) { return _->Or(this); }
Node* Error::Plus(Node* _) { return _->back_Plus(this); }
Node* Error::back_Plus(Error* _) { return _->Plus(this); }
Node* Error::back_Plus(Bool* _) { return _->Plus(this); }
Node* Error::back_Plus(Integer* _) { return _->Plus(this); }
Node* Error::back_Plus(Double* _) { return _->Plus(this); }
Node* Error::back_Plus(String* _) { return _->Plus(this); }
Node* Error::back_Plus(List* _) { return _->Plus(this); }
Node* Error::back_Plus(Object* _) { return _->Plus(this); }
Node* Error::back_Plus(Function* _) { return _->Plus(this); }
Node* Bool::Plus(Node* _) { return _->back_Plus(this); }
Node* Bool::back_Plus(Error* _) { return _->Plus(this); }
Node* Bool::back_Plus(Bool* _) { return _->Plus(this); }
Node* Bool::back_Plus(Integer* _) { return _->Plus(this); }
Node* Bool::back_Plus(Double* _) { return _->Plus(this); }
Node* Bool::back_Plus(String* _) { return _->Plus(this); }
Node* Bool::back_Plus(List* _) { return _->Plus(this); }
Node* Bool::back_Plus(Object* _) { return _->Plus(this); }
Node* Bool::back_Plus(Function* _) { return _->Plus(this); }
Node* Integer::Plus(Node* _) { return _->back_Plus(this); }
Node* Integer::back_Plus(Error* _) { return _->Plus(this); }
Node* Integer::back_Plus(Bool* _) { return _->Plus(this); }
Node* Integer::back_Plus(Integer* _) { return _->Plus(this); }
Node* Integer::back_Plus(Double* _) { return _->Plus(this); }
Node* Integer::back_Plus(String* _) { return _->Plus(this); }
Node* Integer::back_Plus(List* _) { return _->Plus(this); }
Node* Integer::back_Plus(Object* _) { return _->Plus(this); }
Node* Integer::back_Plus(Function* _) { return _->Plus(this); }
Node* Double::Plus(Node* _) { return _->back_Plus(this); }
Node* Double::back_Plus(Error* _) { return _->Plus(this); }
Node* Double::back_Plus(Bool* _) { return _->Plus(this); }
Node* Double::back_Plus(Integer* _) { return _->Plus(this); }
Node* Double::back_Plus(Double* _) { return _->Plus(this); }
Node* Double::back_Plus(String* _) { return _->Plus(this); }
Node* Double::back_Plus(List* _) { return _->Plus(this); }
Node* Double::back_Plus(Object* _) { return _->Plus(this); }
Node* Double::back_Plus(Function* _) { return _->Plus(this); }
Node* String::Plus(Node* _) { return _->back_Plus(this); }
Node* String::back_Plus(Error* _) { return _->Plus(this); }
Node* String::back_Plus(Bool* _) { return _->Plus(this); }
Node* String::back_Plus(Integer* _) { return _->Plus(this); }
Node* String::back_Plus(Double* _) { return _->Plus(this); }
Node* String::back_Plus(String* _) { return _->Plus(this); }
Node* String::back_Plus(List* _) { return _->Plus(this); }
Node* String::back_Plus(Object* _) { return _->Plus(this); }
Node* String::back_Plus(Function* _) { return _->Plus(this); }
Node* List::Plus(Node* _) { return _->back_Plus(this); }
Node* List::back_Plus(Error* _) { return _->Plus(this); }
Node* List::back_Plus(Bool* _) { return _->Plus(this); }
Node* List::back_Plus(Integer* _) { return _->Plus(this); }
Node* List::back_Plus(Double* _) { return _->Plus(this); }
Node* List::back_Plus(String* _) { return _->Plus(this); }
Node* List::back_Plus(List* _) { return _->Plus(this); }
Node* List::back_Plus(Object* _) { return _->Plus(this); }
Node* List::back_Plus(Function* _) { return _->Plus(this); }
Node* Object::Plus(Node* _) { return _->back_Plus(this); }
Node* Object::back_Plus(Error* _) { return _->Plus(this); }
Node* Object::back_Plus(Bool* _) { return _->Plus(this); }
Node* Object::back_Plus(Integer* _) { return _->Plus(this); }
Node* Object::back_Plus(Double* _) { return _->Plus(this); }
Node* Object::back_Plus(String* _) { return _->Plus(this); }
Node* Object::back_Plus(List* _) { return _->Plus(this); }
Node* Object::back_Plus(Object* _) { return _->Plus(this); }
Node* Object::back_Plus(Function* _) { return _->Plus(this); }
Node* Function::Plus(Node* _) { return _->back_Plus(this); }
Node* Function::back_Plus(Error* _) { return _->Plus(this); }
Node* Function::back_Plus(Bool* _) { return _->Plus(this); }
Node* Function::back_Plus(Integer* _) { return _->Plus(this); }
Node* Function::back_Plus(Double* _) { return _->Plus(this); }
Node* Function::back_Plus(String* _) { return _->Plus(this); }
Node* Function::back_Plus(List* _) { return _->Plus(this); }
Node* Function::back_Plus(Object* _) { return _->Plus(this); }
Node* Function::back_Plus(Function* _) { return _->Plus(this); }
Node* Error::Minus(Node* _) { return _->back_Minus(this); }
Node* Error::back_Minus(Error* _) { return _->Minus(this); }
Node* Error::back_Minus(Bool* _) { return _->Minus(this); }
Node* Error::back_Minus(Integer* _) { return _->Minus(this); }
Node* Error::back_Minus(Double* _) { return _->Minus(this); }
Node* Error::back_Minus(String* _) { return _->Minus(this); }
Node* Error::back_Minus(List* _) { return _->Minus(this); }
Node* Error::back_Minus(Object* _) { return _->Minus(this); }
Node* Error::back_Minus(Function* _) { return _->Minus(this); }
Node* Bool::Minus(Node* _) { return _->back_Minus(this); }
Node* Bool::back_Minus(Error* _) { return _->Minus(this); }
Node* Bool::back_Minus(Bool* _) { return _->Minus(this); }
Node* Bool::back_Minus(Integer* _) { return _->Minus(this); }
Node* Bool::back_Minus(Double* _) { return _->Minus(this); }
Node* Bool::back_Minus(String* _) { return _->Minus(this); }
Node* Bool::back_Minus(List* _) { return _->Minus(this); }
Node* Bool::back_Minus(Object* _) { return _->Minus(this); }
Node* Bool::back_Minus(Function* _) { return _->Minus(this); }
Node* Integer::Minus(Node* _) { return _->back_Minus(this); }
Node* Integer::back_Minus(Error* _) { return _->Minus(this); }
Node* Integer::back_Minus(Bool* _) { return _->Minus(this); }
Node* Integer::back_Minus(Integer* _) { return _->Minus(this); }
Node* Integer::back_Minus(Double* _) { return _->Minus(this); }
Node* Integer::back_Minus(String* _) { return _->Minus(this); }
Node* Integer::back_Minus(List* _) { return _->Minus(this); }
Node* Integer::back_Minus(Object* _) { return _->Minus(this); }
Node* Integer::back_Minus(Function* _) { return _->Minus(this); }
Node* Double::Minus(Node* _) { return _->back_Minus(this); }
Node* Double::back_Minus(Error* _) { return _->Minus(this); }
Node* Double::back_Minus(Bool* _) { return _->Minus(this); }
Node* Double::back_Minus(Integer* _) { return _->Minus(this); }
Node* Double::back_Minus(Double* _) { return _->Minus(this); }
Node* Double::back_Minus(String* _) { return _->Minus(this); }
Node* Double::back_Minus(List* _) { return _->Minus(this); }
Node* Double::back_Minus(Object* _) { return _->Minus(this); }
Node* Double::back_Minus(Function* _) { return _->Minus(this); }
Node* String::Minus(Node* _) { return _->back_Minus(this); }
Node* String::back_Minus(Error* _) { return _->Minus(this); }
Node* String::back_Minus(Bool* _) { return _->Minus(this); }
Node* String::back_Minus(Integer* _) { return _->Minus(this); }
Node* String::back_Minus(Double* _) { return _->Minus(this); }
Node* String::back_Minus(String* _) { return _->Minus(this); }
Node* String::back_Minus(List* _) { return _->Minus(this); }
Node* String::back_Minus(Object* _) { return _->Minus(this); }
Node* String::back_Minus(Function* _) { return _->Minus(this); }
Node* List::Minus(Node* _) { return _->back_Minus(this); }
Node* List::back_Minus(Error* _) { return _->Minus(this); }
Node* List::back_Minus(Bool* _) { return _->Minus(this); }
Node* List::back_Minus(Integer* _) { return _->Minus(this); }
Node* List::back_Minus(Double* _) { return _->Minus(this); }
Node* List::back_Minus(String* _) { return _->Minus(this); }
Node* List::back_Minus(List* _) { return _->Minus(this); }
Node* List::back_Minus(Object* _) { return _->Minus(this); }
Node* List::back_Minus(Function* _) { return _->Minus(this); }
Node* Object::Minus(Node* _) { return _->back_Minus(this); }
Node* Object::back_Minus(Error* _) { return _->Minus(this); }
Node* Object::back_Minus(Bool* _) { return _->Minus(this); }
Node* Object::back_Minus(Integer* _) { return _->Minus(this); }
Node* Object::back_Minus(Double* _) { return _->Minus(this); }
Node* Object::back_Minus(String* _) { return _->Minus(this); }
Node* Object::back_Minus(List* _) { return _->Minus(this); }
Node* Object::back_Minus(Object* _) { return _->Minus(this); }
Node* Object::back_Minus(Function* _) { return _->Minus(this); }
Node* Function::Minus(Node* _) { return _->back_Minus(this); }
Node* Function::back_Minus(Error* _) { return _->Minus(this); }
Node* Function::back_Minus(Bool* _) { return _->Minus(this); }
Node* Function::back_Minus(Integer* _) { return _->Minus(this); }
Node* Function::back_Minus(Double* _) { return _->Minus(this); }
Node* Function::back_Minus(String* _) { return _->Minus(this); }
Node* Function::back_Minus(List* _) { return _->Minus(this); }
Node* Function::back_Minus(Object* _) { return _->Minus(this); }
Node* Function::back_Minus(Function* _) { return _->Minus(this); }
Node* Error::Times(Node* _) { return _->back_Times(this); }
Node* Error::back_Times(Error* _) { return _->Times(this); }
Node* Error::back_Times(Bool* _) { return _->Times(this); }
Node* Error::back_Times(Integer* _) { return _->Times(this); }
Node* Error::back_Times(Double* _) { return _->Times(this); }
Node* Error::back_Times(String* _) { return _->Times(this); }
Node* Error::back_Times(List* _) { return _->Times(this); }
Node* Error::back_Times(Object* _) { return _->Times(this); }
Node* Error::back_Times(Function* _) { return _->Times(this); }
Node* Bool::Times(Node* _) { return _->back_Times(this); }
Node* Bool::back_Times(Error* _) { return _->Times(this); }
Node* Bool::back_Times(Bool* _) { return _->Times(this); }
Node* Bool::back_Times(Integer* _) { return _->Times(this); }
Node* Bool::back_Times(Double* _) { return _->Times(this); }
Node* Bool::back_Times(String* _) { return _->Times(this); }
Node* Bool::back_Times(List* _) { return _->Times(this); }
Node* Bool::back_Times(Object* _) { return _->Times(this); }
Node* Bool::back_Times(Function* _) { return _->Times(this); }
Node* Integer::Times(Node* _) { return _->back_Times(this); }
Node* Integer::back_Times(Error* _) { return _->Times(this); }
Node* Integer::back_Times(Bool* _) { return _->Times(this); }
Node* Integer::back_Times(Integer* _) { return _->Times(this); }
Node* Integer::back_Times(Double* _) { return _->Times(this); }
Node* Integer::back_Times(String* _) { return _->Times(this); }
Node* Integer::back_Times(List* _) { return _->Times(this); }
Node* Integer::back_Times(Object* _) { return _->Times(this); }
Node* Integer::back_Times(Function* _) { return _->Times(this); }
Node* Double::Times(Node* _) { return _->back_Times(this); }
Node* Double::back_Times(Error* _) { return _->Times(this); }
Node* Double::back_Times(Bool* _) { return _->Times(this); }
Node* Double::back_Times(Integer* _) { return _->Times(this); }
Node* Double::back_Times(Double* _) { return _->Times(this); }
Node* Double::back_Times(String* _) { return _->Times(this); }
Node* Double::back_Times(List* _) { return _->Times(this); }
Node* Double::back_Times(Object* _) { return _->Times(this); }
Node* Double::back_Times(Function* _) { return _->Times(this); }
Node* String::Times(Node* _) { return _->back_Times(this); }
Node* String::back_Times(Error* _) { return _->Times(this); }
Node* String::back_Times(Bool* _) { return _->Times(this); }
Node* String::back_Times(Integer* _) { return _->Times(this); }
Node* String::back_Times(Double* _) { return _->Times(this); }
Node* String::back_Times(String* _) { return _->Times(this); }
Node* String::back_Times(List* _) { return _->Times(this); }
Node* String::back_Times(Object* _) { return _->Times(this); }
Node* String::back_Times(Function* _) { return _->Times(this); }
Node* List::Times(Node* _) { return _->back_Times(this); }
Node* List::back_Times(Error* _) { return _->Times(this); }
Node* List::back_Times(Bool* _) { return _->Times(this); }
Node* List::back_Times(Integer* _) { return _->Times(this); }
Node* List::back_Times(Double* _) { return _->Times(this); }
Node* List::back_Times(String* _) { return _->Times(this); }
Node* List::back_Times(List* _) { return _->Times(this); }
Node* List::back_Times(Object* _) { return _->Times(this); }
Node* List::back_Times(Function* _) { return _->Times(this); }
Node* Object::Times(Node* _) { return _->back_Times(this); }
Node* Object::back_Times(Error* _) { return _->Times(this); }
Node* Object::back_Times(Bool* _) { return _->Times(this); }
Node* Object::back_Times(Integer* _) { return _->Times(this); }
Node* Object::back_Times(Double* _) { return _->Times(this); }
Node* Object::back_Times(String* _) { return _->Times(this); }
Node* Object::back_Times(List* _) { return _->Times(this); }
Node* Object::back_Times(Object* _) { return _->Times(this); }
Node* Object::back_Times(Function* _) { return _->Times(this); }
Node* Function::Times(Node* _) { return _->back_Times(this); }
Node* Function::back_Times(Error* _) { return _->Times(this); }
Node* Function::back_Times(Bool* _) { return _->Times(this); }
Node* Function::back_Times(Integer* _) { return _->Times(this); }
Node* Function::back_Times(Double* _) { return _->Times(this); }
Node* Function::back_Times(String* _) { return _->Times(this); }
Node* Function::back_Times(List* _) { return _->Times(this); }
Node* Function::back_Times(Object* _) { return _->Times(this); }
Node* Function::back_Times(Function* _) { return _->Times(this); }
Node* Error::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Error::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Bool* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(List* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Error::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Bool::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Bool::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Bool::back_DividedBy(Bool* _) { return _->DividedBy(this); }
Node* Bool::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Bool::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Bool::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Bool::back_DividedBy(List* _) { return _->DividedBy(this); }
Node* Bool::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Bool::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Integer::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Integer::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Bool* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(List* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Integer::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Double::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Double::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Bool* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(List* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Double::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* String::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* String::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Bool* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(List* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* String::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* List::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* List::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* List::back_DividedBy(Bool* _) { return _->DividedBy(this); }
Node* List::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* List::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* List::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* List::back_DividedBy(List* _) { return _->DividedBy(this); }
Node* List::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* List::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Object::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Object::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Bool* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(List* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Object::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Function::DividedBy(Node* _) { return _->back_DividedBy(this); }
Node* Function::back_DividedBy(Error* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Bool* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Integer* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Double* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(String* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(List* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Object* _) { return _->DividedBy(this); }
Node* Function::back_DividedBy(Function* _) { return _->DividedBy(this); }
Node* Error::Mod(Node* _) { return _->back_Mod(this); }
Node* Error::back_Mod(Error* _) { return _->Mod(this); }
Node* Error::back_Mod(Bool* _) { return _->Mod(this); }
Node* Error::back_Mod(Integer* _) { return _->Mod(this); }
Node* Error::back_Mod(Double* _) { return _->Mod(this); }
Node* Error::back_Mod(String* _) { return _->Mod(this); }
Node* Error::back_Mod(List* _) { return _->Mod(this); }
Node* Error::back_Mod(Object* _) { return _->Mod(this); }
Node* Error::back_Mod(Function* _) { return _->Mod(this); }
Node* Bool::Mod(Node* _) { return _->back_Mod(this); }
Node* Bool::back_Mod(Error* _) { return _->Mod(this); }
Node* Bool::back_Mod(Bool* _) { return _->Mod(this); }
Node* Bool::back_Mod(Integer* _) { return _->Mod(this); }
Node* Bool::back_Mod(Double* _) { return _->Mod(this); }
Node* Bool::back_Mod(String* _) { return _->Mod(this); }
Node* Bool::back_Mod(List* _) { return _->Mod(this); }
Node* Bool::back_Mod(Object* _) { return _->Mod(this); }
Node* Bool::back_Mod(Function* _) { return _->Mod(this); }
Node* Integer::Mod(Node* _) { return _->back_Mod(this); }
Node* Integer::back_Mod(Error* _) { return _->Mod(this); }
Node* Integer::back_Mod(Bool* _) { return _->Mod(this); }
Node* Integer::back_Mod(Integer* _) { return _->Mod(this); }
Node* Integer::back_Mod(Double* _) { return _->Mod(this); }
Node* Integer::back_Mod(String* _) { return _->Mod(this); }
Node* Integer::back_Mod(List* _) { return _->Mod(this); }
Node* Integer::back_Mod(Object* _) { return _->Mod(this); }
Node* Integer::back_Mod(Function* _) { return _->Mod(this); }
Node* Double::Mod(Node* _) { return _->back_Mod(this); }
Node* Double::back_Mod(Error* _) { return _->Mod(this); }
Node* Double::back_Mod(Bool* _) { return _->Mod(this); }
Node* Double::back_Mod(Integer* _) { return _->Mod(this); }
Node* Double::back_Mod(Double* _) { return _->Mod(this); }
Node* Double::back_Mod(String* _) { return _->Mod(this); }
Node* Double::back_Mod(List* _) { return _->Mod(this); }
Node* Double::back_Mod(Object* _) { return _->Mod(this); }
Node* Double::back_Mod(Function* _) { return _->Mod(this); }
Node* String::Mod(Node* _) { return _->back_Mod(this); }
Node* String::back_Mod(Error* _) { return _->Mod(this); }
Node* String::back_Mod(Bool* _) { return _->Mod(this); }
Node* String::back_Mod(Integer* _) { return _->Mod(this); }
Node* String::back_Mod(Double* _) { return _->Mod(this); }
Node* String::back_Mod(String* _) { return _->Mod(this); }
Node* String::back_Mod(List* _) { return _->Mod(this); }
Node* String::back_Mod(Object* _) { return _->Mod(this); }
Node* String::back_Mod(Function* _) { return _->Mod(this); }
Node* List::Mod(Node* _) { return _->back_Mod(this); }
Node* List::back_Mod(Error* _) { return _->Mod(this); }
Node* List::back_Mod(Bool* _) { return _->Mod(this); }
Node* List::back_Mod(Integer* _) { return _->Mod(this); }
Node* List::back_Mod(Double* _) { return _->Mod(this); }
Node* List::back_Mod(String* _) { return _->Mod(this); }
Node* List::back_Mod(List* _) { return _->Mod(this); }
Node* List::back_Mod(Object* _) { return _->Mod(this); }
Node* List::back_Mod(Function* _) { return _->Mod(this); }
Node* Object::Mod(Node* _) { return _->back_Mod(this); }
Node* Object::back_Mod(Error* _) { return _->Mod(this); }
Node* Object::back_Mod(Bool* _) { return _->Mod(this); }
Node* Object::back_Mod(Integer* _) { return _->Mod(this); }
Node* Object::back_Mod(Double* _) { return _->Mod(this); }
Node* Object::back_Mod(String* _) { return _->Mod(this); }
Node* Object::back_Mod(List* _) { return _->Mod(this); }
Node* Object::back_Mod(Object* _) { return _->Mod(this); }
Node* Object::back_Mod(Function* _) { return _->Mod(this); }
Node* Function::Mod(Node* _) { return _->back_Mod(this); }
Node* Function::back_Mod(Error* _) { return _->Mod(this); }
Node* Function::back_Mod(Bool* _) { return _->Mod(this); }
Node* Function::back_Mod(Integer* _) { return _->Mod(this); }
Node* Function::back_Mod(Double* _) { return _->Mod(this); }
Node* Function::back_Mod(String* _) { return _->Mod(this); }
Node* Function::back_Mod(List* _) { return _->Mod(this); }
Node* Function::back_Mod(Object* _) { return _->Mod(this); }
Node* Function::back_Mod(Function* _) { return _->Mod(this); }
Node* Error::Call(Node* _) { return _->back_Call(this); }
Node* Error::back_Call(Error* _) { return _->Call(this); }
Node* Error::back_Call(Bool* _) { return _->Call(this); }
Node* Error::back_Call(Integer* _) { return _->Call(this); }
Node* Error::back_Call(Double* _) { return _->Call(this); }
Node* Error::back_Call(String* _) { return _->Call(this); }
Node* Error::back_Call(List* _) { return _->Call(this); }
Node* Error::back_Call(Object* _) { return _->Call(this); }
Node* Error::back_Call(Function* _) { return _->Call(this); }
Node* Bool::Call(Node* _) { return _->back_Call(this); }
Node* Bool::back_Call(Error* _) { return _->Call(this); }
Node* Bool::back_Call(Bool* _) { return _->Call(this); }
Node* Bool::back_Call(Integer* _) { return _->Call(this); }
Node* Bool::back_Call(Double* _) { return _->Call(this); }
Node* Bool::back_Call(String* _) { return _->Call(this); }
Node* Bool::back_Call(List* _) { return _->Call(this); }
Node* Bool::back_Call(Object* _) { return _->Call(this); }
Node* Bool::back_Call(Function* _) { return _->Call(this); }
Node* Integer::Call(Node* _) { return _->back_Call(this); }
Node* Integer::back_Call(Error* _) { return _->Call(this); }
Node* Integer::back_Call(Bool* _) { return _->Call(this); }
Node* Integer::back_Call(Integer* _) { return _->Call(this); }
Node* Integer::back_Call(Double* _) { return _->Call(this); }
Node* Integer::back_Call(String* _) { return _->Call(this); }
Node* Integer::back_Call(List* _) { return _->Call(this); }
Node* Integer::back_Call(Object* _) { return _->Call(this); }
Node* Integer::back_Call(Function* _) { return _->Call(this); }
Node* Double::Call(Node* _) { return _->back_Call(this); }
Node* Double::back_Call(Error* _) { return _->Call(this); }
Node* Double::back_Call(Bool* _) { return _->Call(this); }
Node* Double::back_Call(Integer* _) { return _->Call(this); }
Node* Double::back_Call(Double* _) { return _->Call(this); }
Node* Double::back_Call(String* _) { return _->Call(this); }
Node* Double::back_Call(List* _) { return _->Call(this); }
Node* Double::back_Call(Object* _) { return _->Call(this); }
Node* Double::back_Call(Function* _) { return _->Call(this); }
Node* String::Call(Node* _) { return _->back_Call(this); }
Node* String::back_Call(Error* _) { return _->Call(this); }
Node* String::back_Call(Bool* _) { return _->Call(this); }
Node* String::back_Call(Integer* _) { return _->Call(this); }
Node* String::back_Call(Double* _) { return _->Call(this); }
Node* String::back_Call(String* _) { return _->Call(this); }
Node* String::back_Call(List* _) { return _->Call(this); }
Node* String::back_Call(Object* _) { return _->Call(this); }
Node* String::back_Call(Function* _) { return _->Call(this); }
Node* List::Call(Node* _) { return _->back_Call(this); }
Node* List::back_Call(Error* _) { return _->Call(this); }
Node* List::back_Call(Bool* _) { return _->Call(this); }
Node* List::back_Call(Integer* _) { return _->Call(this); }
Node* List::back_Call(Double* _) { return _->Call(this); }
Node* List::back_Call(String* _) { return _->Call(this); }
Node* List::back_Call(List* _) { return _->Call(this); }
Node* List::back_Call(Object* _) { return _->Call(this); }
Node* List::back_Call(Function* _) { return _->Call(this); }
Node* Object::Call(Node* _) { return _->back_Call(this); }
Node* Object::back_Call(Error* _) { return _->Call(this); }
Node* Object::back_Call(Bool* _) { return _->Call(this); }
Node* Object::back_Call(Integer* _) { return _->Call(this); }
Node* Object::back_Call(Double* _) { return _->Call(this); }
Node* Object::back_Call(String* _) { return _->Call(this); }
Node* Object::back_Call(List* _) { return _->Call(this); }
Node* Object::back_Call(Object* _) { return _->Call(this); }
Node* Object::back_Call(Function* _) { return _->Call(this); }
Node* Function::Call(Node* _) { return _->back_Call(this); }
Node* Function::back_Call(Error* _) { return _->Call(this); }
Node* Function::back_Call(Bool* _) { return _->Call(this); }
Node* Function::back_Call(Integer* _) { return _->Call(this); }
Node* Function::back_Call(Double* _) { return _->Call(this); }
Node* Function::back_Call(String* _) { return _->Call(this); }
Node* Function::back_Call(List* _) { return _->Call(this); }
Node* Function::back_Call(Object* _) { return _->Call(this); }
Node* Function::back_Call(Function* _) { return _->Call(this); }

}