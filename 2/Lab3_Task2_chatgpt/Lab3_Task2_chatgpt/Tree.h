#pragma once
#include <memory>

// Узел дерева выражения
struct TreeNode
{
    int value; // значение или код операции
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int value);
};

// Проверка: является ли узел операцией
bool isOperator(int value);

// Вычисление операции
int calculate(int op, int left, int right);

// Преобразование дерева (свёртка поддеревьев)
std::shared_ptr<TreeNode> simplifyTree(std::shared_ptr<TreeNode> node);

//FIX_ME: отсутствует объявление функции для вывода дерева
// Добавлена функция для вывода дерева в консоль

// Вывод дерева в консоль
void printTree(const std::shared_ptr<TreeNode>& node, int depth = 0);