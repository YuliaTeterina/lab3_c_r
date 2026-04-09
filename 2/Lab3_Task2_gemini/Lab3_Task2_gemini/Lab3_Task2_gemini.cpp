#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "ExpressionTree.h"

/**
 * Функция для разбиения строки на токены
 */
std::vector<std::string> tokenize(const std::string& str)
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string temp;
    while (ss >> temp)
    {
        tokens.push_back(temp);
    }
    return tokens;
}

int main()
{
    // Установка русской локали для консоли
    setlocale(LC_ALL, "Russian");

    std::string fileName;
    std::cout << "Введите имя файла с префиксным выражением: ";
    std::cin >> fileName;

    std::ifstream file(fileName);
    if (!file.is_open())
    {
        std::cerr << "Ошибка: Не удалось открыть файл " << fileName << std::endl;
        return 1;
    }

    std::string expression;
    std::getline(file, expression);
    file.close();

    if (expression.empty())
    {
        std::cerr << "Ошибка: Файл пуст." << std::endl;
        return 1;
    }

    std::vector<std::string> tokens = tokenize(expression);
    UExpressionTree tree;

    std::cout << "\n--- Построение дерева ---" << std::endl;
    if (!tree.buildFromPrefix(tokens))
    {
        std::cerr << "Ошибка при разборе выражения." << std::endl;
        return 1;
    }

    std::cout << "Исходное дерево:" << std::endl;
    tree.printTree(tree.getRoot());

    std::cout << "\n--- Оптимизация (свертка поддеревьев 0-9) ---" << std::endl;
    tree.optimize();

    std::cout << "Результирующее дерево:" << std::endl;
    tree.printTree(tree.getRoot());

    std::cout << "\nУказатель на корень полученного дерева: " << tree.getRoot() << std::endl;

    return 0;
}