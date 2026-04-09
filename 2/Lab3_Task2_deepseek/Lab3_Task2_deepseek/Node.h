#pragma once

//FIX_ME: фигурные скобки стоят в неправильных местах
//Изменено: все скобки перенесены

/**
 * Класс узла дерева выражения.
 * Узел может быть операндом (целое число 0..9) или оператором (код операции -1..-6).
 */
class Node 
{
public:
    enum class Type 
    {
        Operand,   // число
        Operator   // операция
    };

    // Конструктор для операнда
    Node(int value);
    // Конструктор для оператора
    Node(int opCode, Node* left, Node* right);
    ~Node();

    // Геттеры
    Type getType() const;
    int getValue() const;
    Node* getLeft() const;
    Node* getRight() const;

    // Сеттеры (для преобразования)
    void setLeft(Node* node);
    void setRight(Node* node);
    void setValue(int val);
    void setType(Type t);

private:
    Type type;
    int value;      // для операнда: число 0..9, для оператора: код (-1..-6)
    Node* left;
    Node* right;
};