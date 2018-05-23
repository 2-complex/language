#ifndef _objects_h_
#define _objects_h_

#include <string>
#include <stdlib.h>

namespace object
{
class Node;
class Error;
class Bool;
class Integer;
class Double;
class String;
class List;
class Object;
class Function;

#define DEFINITIONS \
    virtual Node* And(Node*);\
    virtual Node* back_And(Error*);\
    virtual Node* back_And(Bool*);\
    virtual Node* back_And(Integer*);\
    virtual Node* back_And(Double*);\
    virtual Node* back_And(String*);\
    virtual Node* back_And(List*);\
    virtual Node* back_And(Object*);\
    virtual Node* back_And(Function*);\
    virtual Node* And(Error*);\
    virtual Node* And(Bool*);\
    virtual Node* And(Integer*);\
    virtual Node* And(Double*);\
    virtual Node* And(String*);\
    virtual Node* And(List*);\
    virtual Node* And(Object*);\
    virtual Node* And(Function*);\
    virtual Node* Or(Node*);\
    virtual Node* back_Or(Error*);\
    virtual Node* back_Or(Bool*);\
    virtual Node* back_Or(Integer*);\
    virtual Node* back_Or(Double*);\
    virtual Node* back_Or(String*);\
    virtual Node* back_Or(List*);\
    virtual Node* back_Or(Object*);\
    virtual Node* back_Or(Function*);\
    virtual Node* Or(Error*);\
    virtual Node* Or(Bool*);\
    virtual Node* Or(Integer*);\
    virtual Node* Or(Double*);\
    virtual Node* Or(String*);\
    virtual Node* Or(List*);\
    virtual Node* Or(Object*);\
    virtual Node* Or(Function*);\
    virtual Node* Plus(Node*);\
    virtual Node* back_Plus(Error*);\
    virtual Node* back_Plus(Bool*);\
    virtual Node* back_Plus(Integer*);\
    virtual Node* back_Plus(Double*);\
    virtual Node* back_Plus(String*);\
    virtual Node* back_Plus(List*);\
    virtual Node* back_Plus(Object*);\
    virtual Node* back_Plus(Function*);\
    virtual Node* Plus(Error*);\
    virtual Node* Plus(Bool*);\
    virtual Node* Plus(Integer*);\
    virtual Node* Plus(Double*);\
    virtual Node* Plus(String*);\
    virtual Node* Plus(List*);\
    virtual Node* Plus(Object*);\
    virtual Node* Plus(Function*);\
    virtual Node* Minus(Node*);\
    virtual Node* back_Minus(Error*);\
    virtual Node* back_Minus(Bool*);\
    virtual Node* back_Minus(Integer*);\
    virtual Node* back_Minus(Double*);\
    virtual Node* back_Minus(String*);\
    virtual Node* back_Minus(List*);\
    virtual Node* back_Minus(Object*);\
    virtual Node* back_Minus(Function*);\
    virtual Node* Minus(Error*);\
    virtual Node* Minus(Bool*);\
    virtual Node* Minus(Integer*);\
    virtual Node* Minus(Double*);\
    virtual Node* Minus(String*);\
    virtual Node* Minus(List*);\
    virtual Node* Minus(Object*);\
    virtual Node* Minus(Function*);\
    virtual Node* Times(Node*);\
    virtual Node* back_Times(Error*);\
    virtual Node* back_Times(Bool*);\
    virtual Node* back_Times(Integer*);\
    virtual Node* back_Times(Double*);\
    virtual Node* back_Times(String*);\
    virtual Node* back_Times(List*);\
    virtual Node* back_Times(Object*);\
    virtual Node* back_Times(Function*);\
    virtual Node* Times(Error*);\
    virtual Node* Times(Bool*);\
    virtual Node* Times(Integer*);\
    virtual Node* Times(Double*);\
    virtual Node* Times(String*);\
    virtual Node* Times(List*);\
    virtual Node* Times(Object*);\
    virtual Node* Times(Function*);\
    virtual Node* DividedBy(Node*);\
    virtual Node* back_DividedBy(Error*);\
    virtual Node* back_DividedBy(Bool*);\
    virtual Node* back_DividedBy(Integer*);\
    virtual Node* back_DividedBy(Double*);\
    virtual Node* back_DividedBy(String*);\
    virtual Node* back_DividedBy(List*);\
    virtual Node* back_DividedBy(Object*);\
    virtual Node* back_DividedBy(Function*);\
    virtual Node* DividedBy(Error*);\
    virtual Node* DividedBy(Bool*);\
    virtual Node* DividedBy(Integer*);\
    virtual Node* DividedBy(Double*);\
    virtual Node* DividedBy(String*);\
    virtual Node* DividedBy(List*);\
    virtual Node* DividedBy(Object*);\
    virtual Node* DividedBy(Function*);\
    virtual Node* Mod(Node*);\
    virtual Node* back_Mod(Error*);\
    virtual Node* back_Mod(Bool*);\
    virtual Node* back_Mod(Integer*);\
    virtual Node* back_Mod(Double*);\
    virtual Node* back_Mod(String*);\
    virtual Node* back_Mod(List*);\
    virtual Node* back_Mod(Object*);\
    virtual Node* back_Mod(Function*);\
    virtual Node* Mod(Error*);\
    virtual Node* Mod(Bool*);\
    virtual Node* Mod(Integer*);\
    virtual Node* Mod(Double*);\
    virtual Node* Mod(String*);\
    virtual Node* Mod(List*);\
    virtual Node* Mod(Object*);\
    virtual Node* Mod(Function*);\
    virtual Node* Call(Node*);\
    virtual Node* back_Call(Error*);\
    virtual Node* back_Call(Bool*);\
    virtual Node* back_Call(Integer*);\
    virtual Node* back_Call(Double*);\
    virtual Node* back_Call(String*);\
    virtual Node* back_Call(List*);\
    virtual Node* back_Call(Object*);\
    virtual Node* back_Call(Function*);\
    virtual Node* Call(Error*);\
    virtual Node* Call(Bool*);\
    virtual Node* Call(Integer*);\
    virtual Node* Call(Double*);\
    virtual Node* Call(String*);\
    virtual Node* Call(List*);\
    virtual Node* Call(Object*);\
    virtual Node* Call(Function*);


class Node
{
public:
    virtual ~Node();
    virtual std::string toString() const;

    virtual Node* And(Node*) = 0;
    virtual Node* back_And(Error*) = 0;
    virtual Node* back_And(Bool*) = 0;
    virtual Node* back_And(Integer*) = 0;
    virtual Node* back_And(Double*) = 0;
    virtual Node* back_And(String*) = 0;
    virtual Node* back_And(List*) = 0;
    virtual Node* back_And(Object*) = 0;
    virtual Node* back_And(Function*) = 0;
    virtual Node* Or(Node*) = 0;
    virtual Node* back_Or(Error*) = 0;
    virtual Node* back_Or(Bool*) = 0;
    virtual Node* back_Or(Integer*) = 0;
    virtual Node* back_Or(Double*) = 0;
    virtual Node* back_Or(String*) = 0;
    virtual Node* back_Or(List*) = 0;
    virtual Node* back_Or(Object*) = 0;
    virtual Node* back_Or(Function*) = 0;
    virtual Node* Plus(Node*) = 0;
    virtual Node* back_Plus(Error*) = 0;
    virtual Node* back_Plus(Bool*) = 0;
    virtual Node* back_Plus(Integer*) = 0;
    virtual Node* back_Plus(Double*) = 0;
    virtual Node* back_Plus(String*) = 0;
    virtual Node* back_Plus(List*) = 0;
    virtual Node* back_Plus(Object*) = 0;
    virtual Node* back_Plus(Function*) = 0;
    virtual Node* Minus(Node*) = 0;
    virtual Node* back_Minus(Error*) = 0;
    virtual Node* back_Minus(Bool*) = 0;
    virtual Node* back_Minus(Integer*) = 0;
    virtual Node* back_Minus(Double*) = 0;
    virtual Node* back_Minus(String*) = 0;
    virtual Node* back_Minus(List*) = 0;
    virtual Node* back_Minus(Object*) = 0;
    virtual Node* back_Minus(Function*) = 0;
    virtual Node* Times(Node*) = 0;
    virtual Node* back_Times(Error*) = 0;
    virtual Node* back_Times(Bool*) = 0;
    virtual Node* back_Times(Integer*) = 0;
    virtual Node* back_Times(Double*) = 0;
    virtual Node* back_Times(String*) = 0;
    virtual Node* back_Times(List*) = 0;
    virtual Node* back_Times(Object*) = 0;
    virtual Node* back_Times(Function*) = 0;
    virtual Node* DividedBy(Node*) = 0;
    virtual Node* back_DividedBy(Error*) = 0;
    virtual Node* back_DividedBy(Bool*) = 0;
    virtual Node* back_DividedBy(Integer*) = 0;
    virtual Node* back_DividedBy(Double*) = 0;
    virtual Node* back_DividedBy(String*) = 0;
    virtual Node* back_DividedBy(List*) = 0;
    virtual Node* back_DividedBy(Object*) = 0;
    virtual Node* back_DividedBy(Function*) = 0;
    virtual Node* Mod(Node*) = 0;
    virtual Node* back_Mod(Error*) = 0;
    virtual Node* back_Mod(Bool*) = 0;
    virtual Node* back_Mod(Integer*) = 0;
    virtual Node* back_Mod(Double*) = 0;
    virtual Node* back_Mod(String*) = 0;
    virtual Node* back_Mod(List*) = 0;
    virtual Node* back_Mod(Object*) = 0;
    virtual Node* back_Mod(Function*) = 0;
    virtual Node* Call(Node*) = 0;
    virtual Node* back_Call(Error*) = 0;
    virtual Node* back_Call(Bool*) = 0;
    virtual Node* back_Call(Integer*) = 0;
    virtual Node* back_Call(Double*) = 0;
    virtual Node* back_Call(String*) = 0;
    virtual Node* back_Call(List*) = 0;
    virtual Node* back_Call(Object*) = 0;
    virtual Node* back_Call(Function*) = 0;
};

class Error : public Node
{
public:
DEFINITIONS
};

class Bool : public Node
{
public:
DEFINITIONS
};

class Integer : public Node
{
    int value;
public:
    Integer(int value);
    Integer(const std::string& text);

    virtual std::string toString() const override;
DEFINITIONS
};

class Double : public Node
{
    double value;
public:
    Double(const std::string& text);

    virtual std::string toString() const override;
DEFINITIONS
};

class String : public Node
{
public:
DEFINITIONS
};

class List : public Node
{
public:
DEFINITIONS
};

class Object : public Node
{
public:
DEFINITIONS
};

class Function : public Node
{
public:
DEFINITIONS
};


}

#endif
