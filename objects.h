#ifndef _objects_h_
#define _objects_h_

#include <string>
#include <map>
#include <vector>
#include <unordered_map>

#include <stdlib.h>

class Environment;
namespace code
{
    class Program;
}

namespace object
{
class Node;
class Error;
class Nothing;
class Member;
class Boolean;
class Integer;
class Double;
class String;
class Array;
class Object;
class Function;

#define DEFINITIONS \
    virtual Node* Negation();\
    virtual Node* Negative();\
    virtual Node* And(Node*);\
    virtual Node* back_And(Error*);\
    virtual Node* back_And(Nothing*);\
    virtual Node* back_And(Member*);\
    virtual Node* back_And(Boolean*);\
    virtual Node* back_And(Integer*);\
    virtual Node* back_And(Double*);\
    virtual Node* back_And(String*);\
    virtual Node* back_And(Array*);\
    virtual Node* back_And(Object*);\
    virtual Node* back_And(Function*);\
    virtual Node* And(Error*);\
    virtual Node* And(Nothing*);\
    virtual Node* And(Member*);\
    virtual Node* And(Boolean*);\
    virtual Node* And(Integer*);\
    virtual Node* And(Double*);\
    virtual Node* And(String*);\
    virtual Node* And(Array*);\
    virtual Node* And(Object*);\
    virtual Node* And(Function*);\
    virtual Node* Or(Node*);\
    virtual Node* back_Or(Error*);\
    virtual Node* back_Or(Nothing*);\
    virtual Node* back_Or(Member*);\
    virtual Node* back_Or(Boolean*);\
    virtual Node* back_Or(Integer*);\
    virtual Node* back_Or(Double*);\
    virtual Node* back_Or(String*);\
    virtual Node* back_Or(Array*);\
    virtual Node* back_Or(Object*);\
    virtual Node* back_Or(Function*);\
    virtual Node* Or(Error*);\
    virtual Node* Or(Nothing*);\
    virtual Node* Or(Member*);\
    virtual Node* Or(Boolean*);\
    virtual Node* Or(Integer*);\
    virtual Node* Or(Double*);\
    virtual Node* Or(String*);\
    virtual Node* Or(Array*);\
    virtual Node* Or(Object*);\
    virtual Node* Or(Function*);\
    virtual Node* Plus(Node*);\
    virtual Node* back_Plus(Error*);\
    virtual Node* back_Plus(Nothing*);\
    virtual Node* back_Plus(Member*);\
    virtual Node* back_Plus(Boolean*);\
    virtual Node* back_Plus(Integer*);\
    virtual Node* back_Plus(Double*);\
    virtual Node* back_Plus(String*);\
    virtual Node* back_Plus(Array*);\
    virtual Node* back_Plus(Object*);\
    virtual Node* back_Plus(Function*);\
    virtual Node* Plus(Error*);\
    virtual Node* Plus(Nothing*);\
    virtual Node* Plus(Member*);\
    virtual Node* Plus(Boolean*);\
    virtual Node* Plus(Integer*);\
    virtual Node* Plus(Double*);\
    virtual Node* Plus(String*);\
    virtual Node* Plus(Array*);\
    virtual Node* Plus(Object*);\
    virtual Node* Plus(Function*);\
    virtual Node* Minus(Node*);\
    virtual Node* back_Minus(Error*);\
    virtual Node* back_Minus(Nothing*);\
    virtual Node* back_Minus(Member*);\
    virtual Node* back_Minus(Boolean*);\
    virtual Node* back_Minus(Integer*);\
    virtual Node* back_Minus(Double*);\
    virtual Node* back_Minus(String*);\
    virtual Node* back_Minus(Array*);\
    virtual Node* back_Minus(Object*);\
    virtual Node* back_Minus(Function*);\
    virtual Node* Minus(Error*);\
    virtual Node* Minus(Nothing*);\
    virtual Node* Minus(Member*);\
    virtual Node* Minus(Boolean*);\
    virtual Node* Minus(Integer*);\
    virtual Node* Minus(Double*);\
    virtual Node* Minus(String*);\
    virtual Node* Minus(Array*);\
    virtual Node* Minus(Object*);\
    virtual Node* Minus(Function*);\
    virtual Node* Times(Node*);\
    virtual Node* back_Times(Error*);\
    virtual Node* back_Times(Nothing*);\
    virtual Node* back_Times(Member*);\
    virtual Node* back_Times(Boolean*);\
    virtual Node* back_Times(Integer*);\
    virtual Node* back_Times(Double*);\
    virtual Node* back_Times(String*);\
    virtual Node* back_Times(Array*);\
    virtual Node* back_Times(Object*);\
    virtual Node* back_Times(Function*);\
    virtual Node* Times(Error*);\
    virtual Node* Times(Nothing*);\
    virtual Node* Times(Member*);\
    virtual Node* Times(Boolean*);\
    virtual Node* Times(Integer*);\
    virtual Node* Times(Double*);\
    virtual Node* Times(String*);\
    virtual Node* Times(Array*);\
    virtual Node* Times(Object*);\
    virtual Node* Times(Function*);\
    virtual Node* DividedBy(Node*);\
    virtual Node* back_DividedBy(Error*);\
    virtual Node* back_DividedBy(Nothing*);\
    virtual Node* back_DividedBy(Member*);\
    virtual Node* back_DividedBy(Boolean*);\
    virtual Node* back_DividedBy(Integer*);\
    virtual Node* back_DividedBy(Double*);\
    virtual Node* back_DividedBy(String*);\
    virtual Node* back_DividedBy(Array*);\
    virtual Node* back_DividedBy(Object*);\
    virtual Node* back_DividedBy(Function*);\
    virtual Node* DividedBy(Error*);\
    virtual Node* DividedBy(Nothing*);\
    virtual Node* DividedBy(Member*);\
    virtual Node* DividedBy(Boolean*);\
    virtual Node* DividedBy(Integer*);\
    virtual Node* DividedBy(Double*);\
    virtual Node* DividedBy(String*);\
    virtual Node* DividedBy(Array*);\
    virtual Node* DividedBy(Object*);\
    virtual Node* DividedBy(Function*);\
    virtual Node* Mod(Node*);\
    virtual Node* back_Mod(Error*);\
    virtual Node* back_Mod(Nothing*);\
    virtual Node* back_Mod(Member*);\
    virtual Node* back_Mod(Boolean*);\
    virtual Node* back_Mod(Integer*);\
    virtual Node* back_Mod(Double*);\
    virtual Node* back_Mod(String*);\
    virtual Node* back_Mod(Array*);\
    virtual Node* back_Mod(Object*);\
    virtual Node* back_Mod(Function*);\
    virtual Node* Mod(Error*);\
    virtual Node* Mod(Nothing*);\
    virtual Node* Mod(Member*);\
    virtual Node* Mod(Boolean*);\
    virtual Node* Mod(Integer*);\
    virtual Node* Mod(Double*);\
    virtual Node* Mod(String*);\
    virtual Node* Mod(Array*);\
    virtual Node* Mod(Object*);\
    virtual Node* Mod(Function*);\
    virtual Node* Call(Node*);\
    virtual Node* back_Call(Error*);\
    virtual Node* back_Call(Nothing*);\
    virtual Node* back_Call(Member*);\
    virtual Node* back_Call(Boolean*);\
    virtual Node* back_Call(Integer*);\
    virtual Node* back_Call(Double*);\
    virtual Node* back_Call(String*);\
    virtual Node* back_Call(Array*);\
    virtual Node* back_Call(Object*);\
    virtual Node* back_Call(Function*);\
    virtual Node* Call(Error*);\
    virtual Node* Call(Nothing*);\
    virtual Node* Call(Member*);\
    virtual Node* Call(Boolean*);\
    virtual Node* Call(Integer*);\
    virtual Node* Call(Double*);\
    virtual Node* Call(String*);\
    virtual Node* Call(Array*);\
    virtual Node* Call(Object*);\
    virtual Node* Call(Function*);\
    virtual Node* Equals(Node*);\
    virtual Node* back_Equals(Error*);\
    virtual Node* back_Equals(Nothing*);\
    virtual Node* back_Equals(Member*);\
    virtual Node* back_Equals(Boolean*);\
    virtual Node* back_Equals(Integer*);\
    virtual Node* back_Equals(Double*);\
    virtual Node* back_Equals(String*);\
    virtual Node* back_Equals(Array*);\
    virtual Node* back_Equals(Object*);\
    virtual Node* back_Equals(Function*);\
    virtual Node* Equals(Error*);\
    virtual Node* Equals(Nothing*);\
    virtual Node* Equals(Member*);\
    virtual Node* Equals(Boolean*);\
    virtual Node* Equals(Integer*);\
    virtual Node* Equals(Double*);\
    virtual Node* Equals(String*);\
    virtual Node* Equals(Array*);\
    virtual Node* Equals(Object*);\
    virtual Node* Equals(Function*);\
    virtual Node* NotEquals(Node*);\
    virtual Node* back_NotEquals(Error*);\
    virtual Node* back_NotEquals(Nothing*);\
    virtual Node* back_NotEquals(Member*);\
    virtual Node* back_NotEquals(Boolean*);\
    virtual Node* back_NotEquals(Integer*);\
    virtual Node* back_NotEquals(Double*);\
    virtual Node* back_NotEquals(String*);\
    virtual Node* back_NotEquals(Array*);\
    virtual Node* back_NotEquals(Object*);\
    virtual Node* back_NotEquals(Function*);\
    virtual Node* NotEquals(Error*);\
    virtual Node* NotEquals(Nothing*);\
    virtual Node* NotEquals(Member*);\
    virtual Node* NotEquals(Boolean*);\
    virtual Node* NotEquals(Integer*);\
    virtual Node* NotEquals(Double*);\
    virtual Node* NotEquals(String*);\
    virtual Node* NotEquals(Array*);\
    virtual Node* NotEquals(Object*);\
    virtual Node* NotEquals(Function*);\
    virtual Node* LessThan(Node*);\
    virtual Node* back_LessThan(Error*);\
    virtual Node* back_LessThan(Nothing*);\
    virtual Node* back_LessThan(Member*);\
    virtual Node* back_LessThan(Boolean*);\
    virtual Node* back_LessThan(Integer*);\
    virtual Node* back_LessThan(Double*);\
    virtual Node* back_LessThan(String*);\
    virtual Node* back_LessThan(Array*);\
    virtual Node* back_LessThan(Object*);\
    virtual Node* back_LessThan(Function*);\
    virtual Node* LessThan(Error*);\
    virtual Node* LessThan(Nothing*);\
    virtual Node* LessThan(Member*);\
    virtual Node* LessThan(Boolean*);\
    virtual Node* LessThan(Integer*);\
    virtual Node* LessThan(Double*);\
    virtual Node* LessThan(String*);\
    virtual Node* LessThan(Array*);\
    virtual Node* LessThan(Object*);\
    virtual Node* LessThan(Function*);\
    virtual Node* GreaterThan(Node*);\
    virtual Node* back_GreaterThan(Error*);\
    virtual Node* back_GreaterThan(Nothing*);\
    virtual Node* back_GreaterThan(Member*);\
    virtual Node* back_GreaterThan(Boolean*);\
    virtual Node* back_GreaterThan(Integer*);\
    virtual Node* back_GreaterThan(Double*);\
    virtual Node* back_GreaterThan(String*);\
    virtual Node* back_GreaterThan(Array*);\
    virtual Node* back_GreaterThan(Object*);\
    virtual Node* back_GreaterThan(Function*);\
    virtual Node* GreaterThan(Error*);\
    virtual Node* GreaterThan(Nothing*);\
    virtual Node* GreaterThan(Member*);\
    virtual Node* GreaterThan(Boolean*);\
    virtual Node* GreaterThan(Integer*);\
    virtual Node* GreaterThan(Double*);\
    virtual Node* GreaterThan(String*);\
    virtual Node* GreaterThan(Array*);\
    virtual Node* GreaterThan(Object*);\
    virtual Node* GreaterThan(Function*);\
    virtual Node* LessThanOrEqualTo(Node*);\
    virtual Node* back_LessThanOrEqualTo(Error*);\
    virtual Node* back_LessThanOrEqualTo(Nothing*);\
    virtual Node* back_LessThanOrEqualTo(Member*);\
    virtual Node* back_LessThanOrEqualTo(Boolean*);\
    virtual Node* back_LessThanOrEqualTo(Integer*);\
    virtual Node* back_LessThanOrEqualTo(Double*);\
    virtual Node* back_LessThanOrEqualTo(String*);\
    virtual Node* back_LessThanOrEqualTo(Array*);\
    virtual Node* back_LessThanOrEqualTo(Object*);\
    virtual Node* back_LessThanOrEqualTo(Function*);\
    virtual Node* LessThanOrEqualTo(Error*);\
    virtual Node* LessThanOrEqualTo(Nothing*);\
    virtual Node* LessThanOrEqualTo(Member*);\
    virtual Node* LessThanOrEqualTo(Boolean*);\
    virtual Node* LessThanOrEqualTo(Integer*);\
    virtual Node* LessThanOrEqualTo(Double*);\
    virtual Node* LessThanOrEqualTo(String*);\
    virtual Node* LessThanOrEqualTo(Array*);\
    virtual Node* LessThanOrEqualTo(Object*);\
    virtual Node* LessThanOrEqualTo(Function*);\
    virtual Node* GreaterThanOrEqualTo(Node*);\
    virtual Node* back_GreaterThanOrEqualTo(Error*);\
    virtual Node* back_GreaterThanOrEqualTo(Nothing*);\
    virtual Node* back_GreaterThanOrEqualTo(Member*);\
    virtual Node* back_GreaterThanOrEqualTo(Boolean*);\
    virtual Node* back_GreaterThanOrEqualTo(Integer*);\
    virtual Node* back_GreaterThanOrEqualTo(Double*);\
    virtual Node* back_GreaterThanOrEqualTo(String*);\
    virtual Node* back_GreaterThanOrEqualTo(Array*);\
    virtual Node* back_GreaterThanOrEqualTo(Object*);\
    virtual Node* back_GreaterThanOrEqualTo(Function*);\
    virtual Node* GreaterThanOrEqualTo(Error*);\
    virtual Node* GreaterThanOrEqualTo(Nothing*);\
    virtual Node* GreaterThanOrEqualTo(Member*);\
    virtual Node* GreaterThanOrEqualTo(Boolean*);\
    virtual Node* GreaterThanOrEqualTo(Integer*);\
    virtual Node* GreaterThanOrEqualTo(Double*);\
    virtual Node* GreaterThanOrEqualTo(String*);\
    virtual Node* GreaterThanOrEqualTo(Array*);\
    virtual Node* GreaterThanOrEqualTo(Object*);\
    virtual Node* GreaterThanOrEqualTo(Function*);


class Node
{
public:
    virtual ~Node();
    virtual std::string toString() const;
    virtual bool isTrue() const;
    virtual void setMember(const std::string& name, object::Node* value);
    virtual object::Node* getMember(const std::string& name);
    virtual void setMapping(object::Node* key, object::Node* value);
    virtual object::Node* getMapping(object::Node* key);

    virtual Node* Negation() = 0;
    virtual Node* Negative() = 0;

    virtual Node* And(Node*) = 0;
    virtual Node* back_And(Error*) = 0;
    virtual Node* back_And(Nothing*) = 0;
    virtual Node* back_And(Member*) = 0;
    virtual Node* back_And(Boolean*) = 0;
    virtual Node* back_And(Integer*) = 0;
    virtual Node* back_And(Double*) = 0;
    virtual Node* back_And(String*) = 0;
    virtual Node* back_And(Array*) = 0;
    virtual Node* back_And(Object*) = 0;
    virtual Node* back_And(Function*) = 0;
    virtual Node* Or(Node*) = 0;
    virtual Node* back_Or(Error*) = 0;
    virtual Node* back_Or(Nothing*) = 0;
    virtual Node* back_Or(Member*) = 0;
    virtual Node* back_Or(Boolean*) = 0;
    virtual Node* back_Or(Integer*) = 0;
    virtual Node* back_Or(Double*) = 0;
    virtual Node* back_Or(String*) = 0;
    virtual Node* back_Or(Array*) = 0;
    virtual Node* back_Or(Object*) = 0;
    virtual Node* back_Or(Function*) = 0;
    virtual Node* Plus(Node*) = 0;
    virtual Node* back_Plus(Error*) = 0;
    virtual Node* back_Plus(Nothing*) = 0;
    virtual Node* back_Plus(Member*) = 0;
    virtual Node* back_Plus(Boolean*) = 0;
    virtual Node* back_Plus(Integer*) = 0;
    virtual Node* back_Plus(Double*) = 0;
    virtual Node* back_Plus(String*) = 0;
    virtual Node* back_Plus(Array*) = 0;
    virtual Node* back_Plus(Object*) = 0;
    virtual Node* back_Plus(Function*) = 0;
    virtual Node* Minus(Node*) = 0;
    virtual Node* back_Minus(Error*) = 0;
    virtual Node* back_Minus(Nothing*) = 0;
    virtual Node* back_Minus(Member*) = 0;
    virtual Node* back_Minus(Boolean*) = 0;
    virtual Node* back_Minus(Integer*) = 0;
    virtual Node* back_Minus(Double*) = 0;
    virtual Node* back_Minus(String*) = 0;
    virtual Node* back_Minus(Array*) = 0;
    virtual Node* back_Minus(Object*) = 0;
    virtual Node* back_Minus(Function*) = 0;
    virtual Node* Times(Node*) = 0;
    virtual Node* back_Times(Error*) = 0;
    virtual Node* back_Times(Nothing*) = 0;
    virtual Node* back_Times(Member*) = 0;
    virtual Node* back_Times(Boolean*) = 0;
    virtual Node* back_Times(Integer*) = 0;
    virtual Node* back_Times(Double*) = 0;
    virtual Node* back_Times(String*) = 0;
    virtual Node* back_Times(Array*) = 0;
    virtual Node* back_Times(Object*) = 0;
    virtual Node* back_Times(Function*) = 0;
    virtual Node* DividedBy(Node*) = 0;
    virtual Node* back_DividedBy(Error*) = 0;
    virtual Node* back_DividedBy(Nothing*) = 0;
    virtual Node* back_DividedBy(Member*) = 0;
    virtual Node* back_DividedBy(Boolean*) = 0;
    virtual Node* back_DividedBy(Integer*) = 0;
    virtual Node* back_DividedBy(Double*) = 0;
    virtual Node* back_DividedBy(String*) = 0;
    virtual Node* back_DividedBy(Array*) = 0;
    virtual Node* back_DividedBy(Object*) = 0;
    virtual Node* back_DividedBy(Function*) = 0;
    virtual Node* Mod(Node*) = 0;
    virtual Node* back_Mod(Error*) = 0;
    virtual Node* back_Mod(Nothing*) = 0;
    virtual Node* back_Mod(Member*) = 0;
    virtual Node* back_Mod(Boolean*) = 0;
    virtual Node* back_Mod(Integer*) = 0;
    virtual Node* back_Mod(Double*) = 0;
    virtual Node* back_Mod(String*) = 0;
    virtual Node* back_Mod(Array*) = 0;
    virtual Node* back_Mod(Object*) = 0;
    virtual Node* back_Mod(Function*) = 0;
    virtual Node* Call(Node*) = 0;
    virtual Node* back_Call(Error*) = 0;
    virtual Node* back_Call(Nothing*) = 0;
    virtual Node* back_Call(Member*) = 0;
    virtual Node* back_Call(Boolean*) = 0;
    virtual Node* back_Call(Integer*) = 0;
    virtual Node* back_Call(Double*) = 0;
    virtual Node* back_Call(String*) = 0;
    virtual Node* back_Call(Array*) = 0;
    virtual Node* back_Call(Object*) = 0;
    virtual Node* back_Call(Function*) = 0;
    virtual Node* Equals(Node*) = 0;
    virtual Node* back_Equals(Error*) = 0;
    virtual Node* back_Equals(Nothing*) = 0;
    virtual Node* back_Equals(Member*) = 0;
    virtual Node* back_Equals(Boolean*) = 0;
    virtual Node* back_Equals(Integer*) = 0;
    virtual Node* back_Equals(Double*) = 0;
    virtual Node* back_Equals(String*) = 0;
    virtual Node* back_Equals(Array*) = 0;
    virtual Node* back_Equals(Object*) = 0;
    virtual Node* back_Equals(Function*) = 0;
    virtual Node* NotEquals(Node*) = 0;
    virtual Node* back_NotEquals(Error*) = 0;
    virtual Node* back_NotEquals(Nothing*) = 0;
    virtual Node* back_NotEquals(Member*) = 0;
    virtual Node* back_NotEquals(Boolean*) = 0;
    virtual Node* back_NotEquals(Integer*) = 0;
    virtual Node* back_NotEquals(Double*) = 0;
    virtual Node* back_NotEquals(String*) = 0;
    virtual Node* back_NotEquals(Array*) = 0;
    virtual Node* back_NotEquals(Object*) = 0;
    virtual Node* back_NotEquals(Function*) = 0;
    virtual Node* LessThan(Node*) = 0;
    virtual Node* back_LessThan(Error*) = 0;
    virtual Node* back_LessThan(Nothing*) = 0;
    virtual Node* back_LessThan(Member*) = 0;
    virtual Node* back_LessThan(Boolean*) = 0;
    virtual Node* back_LessThan(Integer*) = 0;
    virtual Node* back_LessThan(Double*) = 0;
    virtual Node* back_LessThan(String*) = 0;
    virtual Node* back_LessThan(Array*) = 0;
    virtual Node* back_LessThan(Object*) = 0;
    virtual Node* back_LessThan(Function*) = 0;
    virtual Node* GreaterThan(Node*) = 0;
    virtual Node* back_GreaterThan(Error*) = 0;
    virtual Node* back_GreaterThan(Nothing*) = 0;
    virtual Node* back_GreaterThan(Member*) = 0;
    virtual Node* back_GreaterThan(Boolean*) = 0;
    virtual Node* back_GreaterThan(Integer*) = 0;
    virtual Node* back_GreaterThan(Double*) = 0;
    virtual Node* back_GreaterThan(String*) = 0;
    virtual Node* back_GreaterThan(Array*) = 0;
    virtual Node* back_GreaterThan(Object*) = 0;
    virtual Node* back_GreaterThan(Function*) = 0;
    virtual Node* LessThanOrEqualTo(Node*) = 0;
    virtual Node* back_LessThanOrEqualTo(Error*) = 0;
    virtual Node* back_LessThanOrEqualTo(Nothing*) = 0;
    virtual Node* back_LessThanOrEqualTo(Member*) = 0;
    virtual Node* back_LessThanOrEqualTo(Boolean*) = 0;
    virtual Node* back_LessThanOrEqualTo(Integer*) = 0;
    virtual Node* back_LessThanOrEqualTo(Double*) = 0;
    virtual Node* back_LessThanOrEqualTo(String*) = 0;
    virtual Node* back_LessThanOrEqualTo(Array*) = 0;
    virtual Node* back_LessThanOrEqualTo(Object*) = 0;
    virtual Node* back_LessThanOrEqualTo(Function*) = 0;
    virtual Node* GreaterThanOrEqualTo(Node*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Error*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Nothing*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Member*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Boolean*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Integer*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Double*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(String*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Array*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Object*) = 0;
    virtual Node* back_GreaterThanOrEqualTo(Function*) = 0;
};

class Error : public Node
{
    std::string message;
public:
    Error();
    Error(const std::string& message);

    virtual std::string toString() const override;
DEFINITIONS
};

class Nothing : public Node
{
public:
DEFINITIONS
};

class Member : public Node
{
    std::string value;
public:
    std::string getValue();
DEFINITIONS
};

class Boolean : public Node
{
    bool value;
public:
    Boolean(bool value);
    bool getValue();

    std::string toString() const override;
DEFINITIONS
};

class Integer : public Node
{
    int value;
public:
    Integer(int value);
    Integer(const std::string& text);
    int getValue();

    virtual std::string toString() const override;
DEFINITIONS
};

class Double : public Node
{
    double value;
public:
    Double(double value);
    Double(const std::string& text);
    double getValue() const;

    virtual std::string toString() const override;
DEFINITIONS
};

class String : public Node
{
    std::string value;
public:
    String(const std::string& value);
    std::string toString() const;
    const std::string& getValue() const;

DEFINITIONS
};

class Array : public Node
{
    std::vector<Node*> value;
public:
    const std::vector<Node*>& getValue();
    void append(Node*);

    std::string toString() const;
DEFINITIONS
};

class Key
{
    Node* node;
public:
    Key(Node* node);

    bool operator == (const class Key& other) const;
    bool operator < (const class Key& other) const;
};

class Object : public Node
{
    std::map<std::string, Node*> members;
    std::map<Key, Node*> mappings;
public:
    std::pair<
        std::map<std::string, Node*>,
        std::map<Key, Node*> > getValue();

    virtual void setMember(const std::string& name, object::Node* value) override;
    virtual object::Node* getMember(const std::string& name) override;

    virtual void setMapping(object::Node* key, object::Node* value);
    virtual object::Node* getMapping(object::Node* key);
DEFINITIONS
};

class Function : public Node
{
    code::Program* program;
    Environment* context;

public:
    Function(Environment* context, code::Program* program);

    std::string getValue();
DEFINITIONS
};

}

#endif
