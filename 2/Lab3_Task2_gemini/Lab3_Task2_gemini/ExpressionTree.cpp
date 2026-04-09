#include "ExpressionTree.h"
#include <iostream>
#include <cmath>

UExpressionTree::UExpressionTree() : root(nullptr) {}

UExpressionTree::~UExpressionTree()
{
    delete root;
}

int UExpressionTree::mapTokenToValue(const std::string& token) const
{
    //FIX_ME: необходимо отделять if-else фигурными скобками

    /*if (token == "+") return -1;
    if (token == "-") return -2;
    if (token == "*") return -3;
    if (token == "/") return -4;
    if (token == "%") return -5;
    if (token == "^") return -6;*/

    if (token == "+") 
    {
        return -1;
    }
    if (token == "-") 
    {
        return -2;
    }
    if (token == "*") 
    {
        return -3;
    }
    if (token == "/") 
    {
        return -4;
    }
    if (token == "%") 
    {
        return -5;
    }
    if (token == "^") 
    {
        return -6;
    }

    // Если это число
    try 
    {
        return std::stoi(token);
    }
    catch (...) 
    {
        return -999; // Ошибка парсинга
    }
}

bool UExpressionTree::isOperator(int val) const
{
    return val <= -1 && val >= -6;
}

bool UExpressionTree::buildFromPrefix(const std::vector<std::string>& tokens)
{
    int index = 0;
    root = buildRecursive(tokens, index);
    return root != nullptr;
}

FExpressionNode* UExpressionTree::buildRecursive(const std::vector<std::string>& tokens, int& index)
{
    //FIX_ME: необходимо отделять if-else фигурными скобками

    /*if (index >= tokens.size()) return nullptr;*/

    if (index >= tokens.size()) 
    {
        return nullptr;
    }

    int val = mapTokenToValue(tokens[index++]);
    FExpressionNode* node = new FExpressionNode(val);

    // Если узел — оператор, рекурсивно создаем ветви
    if (isOperator(val))
    {
        node->leftChild = buildRecursive(tokens, index);
        node->rightChild = buildRecursive(tokens, index);
    }

    return node;
}

void UExpressionTree::optimize()
{
    root = optimizeRecursive(root);
}

FExpressionNode* UExpressionTree::optimizeRecursive(FExpressionNode* node)
{
    //FIX_ME: необходимо отделять if-else фигурными скобками
    //if (!node) return nullptr;
    if (!node) 
    {
        return nullptr;
    }


    // Если это лист (число), возвращаем как есть
    if (!isOperator(node->value))
    {
        return node;
    }

    // Рекурсивно оптимизируем детей
    node->leftChild = optimizeRecursive(node->leftChild);
    node->rightChild = optimizeRecursive(node->rightChild);

    // Если оба ребенка стали числами, пробуем вычислить
    if (node->leftChild && !isOperator(node->leftChild->value) &&
        node->rightChild && !isOperator(node->rightChild->value))
    {
        int result = calculate(node->value, node->leftChild->value, node->rightChild->value);

        // Если результат — число от 0 до 9, заменяем узел
        if (result >= 0 && result <= 9)
        {
            int newValue = result;
            delete node->leftChild;
            delete node->rightChild;
            node->leftChild = nullptr;
            node->rightChild = nullptr;
            node->value = newValue;
        }
    }

    return node;
}

int UExpressionTree::calculate(int op, int left, int right) const
{
    switch (op)
    {
    case -1: return left + right;
    case -2: return left - right;
    case -3: return left * right;
    case -4: return (right != 0) ? (left / right) : -999;
    case -5: return (right != 0) ? (left % right) : -999;
    case -6: return static_cast<int>(std::pow(left, right));
    default: return -999;
    }
}

std::string UExpressionTree::valueToSymbol(int val) const
{
    switch (val)
    {
    case -1: return "+";
    case -2: return "-";
    case -3: return "*";
    case -4: return "/";
    case -5: return "%";
    case -6: return "^";
    default: return std::to_string(val);
    }
}

void UExpressionTree::printTree(FExpressionNode* node, int depth) const
{
    //FIX_ME: необходимо отделять if-else фигурными скобками
    //if (!node) return;
    if (!node) 
    {
        return;
    }

    for (int i = 0; i < depth; ++i) std::cout << "  ";
    std::cout << valueToSymbol(node->value) << std::endl;
    printTree(node->leftChild, depth + 1);
    printTree(node->rightChild, depth + 1);
}