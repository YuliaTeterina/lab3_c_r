//FIX_ME: фигурные скобки стоят в неправильных местах
//Изменено: все скобки перенесены
#include "Node.h"

Node::Node(int value)
    : type(Type::Operand)
    , value(value)
    , left(nullptr)
    , right(nullptr) {
}

Node::Node(int opCode, Node* left, Node* right)
    : type(Type::Operator)
    , value(opCode)
    , left(left)
    , right(right) {
}

Node::~Node() 
{
    delete left;
    delete right;
}

//Изменено: все скобки у методов перенесены
Node::Type Node::getType() const 
{ 
    return type; 
}
int Node::getValue() const 
{
    return value; 
}
Node* Node::getLeft() const 
{ 
    return left; 
}
Node* Node::getRight() const 
{
    return right; 
}
void Node::setLeft(Node* node) 
{ 
    left = node; 
}
void Node::setRight(Node* node) 
{ 
    right = node; 
}
void Node::setValue(int val) 
{ 
    value = val; 
}
void Node::setType(Type t) 
{ 
    type = t; 
}