#pragma once

#include "ExpressionNode.h"
#include <string>
#include <vector>

/**
 * Класс управления деревом выражений.
 */
class UExpressionTree
{
public:
    UExpressionTree();
    ~UExpressionTree();

    // Построение дерева из строки префиксного выражения
    bool buildFromPrefix(const std::vector<std::string>& tokens);

    // Оптимизация дерева согласно условию (свертка значений 0-9)
    void optimize();

    // Вывод структуры дерева (для наглядности)
    void printTree(FExpressionNode* node, int depth = 0) const;
    //FIX_ME: фигурные скобки стоят в неправильных местах
    //Изменено: все скобки перенесены
    FExpressionNode* getRoot() const 
    { 
        return root; 
    }

private:
    FExpressionNode* root;

    // Рекурсивный метод построения
    FExpressionNode* buildRecursive(const std::vector<std::string>& tokens, int& index);

    // Рекурсивный метод оптимизации
    FExpressionNode* optimizeRecursive(FExpressionNode* node);

    // Вспомогательные методы
    bool isOperator(int val) const;
    int calculate(int op, int left, int right) const;
    int mapTokenToValue(const std::string& token) const;
    std::string valueToSymbol(int val) const;
};