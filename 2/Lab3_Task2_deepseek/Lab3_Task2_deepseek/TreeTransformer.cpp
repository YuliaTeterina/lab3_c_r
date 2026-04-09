#include "TreeTransformer.h"
#include "Node.h"
#include <cmath>
#include <stdexcept>

//FIX_ME: фигурные скобки стоят в неправильных местах
//Изменено: все скобки перенесены

/**
 * Вычисляет значение поддерева (рекурсивно).
 */
int evaluate(Node* node) 
{
    if (node->getType() == Node::Type::Operand) 
    {
        return node->getValue();
    }

    int leftVal = evaluate(node->getLeft());
    int rightVal = evaluate(node->getRight());
    int op = node->getValue();

    switch (op) 
    {
    case -1: return leftVal + rightVal;
    case -2: return leftVal - rightVal;
    case -3: return leftVal * rightVal;
    case -4:
        //FIX_ME: необходимо отделять if-else фигурными скобками
        //if (rightVal == 0) throw std::runtime_error("Деление на ноль");
        if (rightVal == 0) 
        {
            throw std::runtime_error("Деление на ноль");
        }

        return leftVal / rightVal;
    case -5:
        //if (rightVal == 0) throw std::runtime_error("Остаток от деления на ноль");
        if (rightVal == 0) 
        {
            throw std::runtime_error("Остаток от деления на ноль");
        }
        return leftVal % rightVal;
    case -6:
        return static_cast<int>(std::pow(leftVal, rightVal));
    default:
        throw std::runtime_error("Неизвестная операция");
    }
}

void transformTree(Node* node) 
{
    if (node->getType() == Node::Type::Operand) 
    {
        return; // лист – нечего преобразовывать
    }

    // Сначала преобразуем поддеревья
    transformTree(node->getLeft());
    transformTree(node->getRight());

    // Вычисляем значение текущего поддерева
    int result = evaluate(node);

    // Если результат – однозначное число, заменяем узел на лист
    if (result >= 0 && result <= 9) 
    {
        delete node->getLeft();
        delete node->getRight();
        node->setLeft(nullptr);
        node->setRight(nullptr);
        node->setType(Node::Type::Operand);
        node->setValue(result);
    }
}