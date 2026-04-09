#include <iostream>
#include <fstream>
#include "parser.h"
#include "tree.h"
#include <filesystem>

int main()
{
    std::setlocale(LC_ALL, "Russian");

    std::ifstream file("C:/Users/Julia/source/repos/laba3_c_r/2/Lab3_Task2_chatgpt/Lab3_Task2_chatgpt/tree.txt");

    if (!file.is_open())
    {
        std::cout << "Ошибка: не удалось открыть файл\n";
        return 1;
    }

    std::string expression;
    std::getline(file, expression);

    if (expression.empty())
    {
        std::cout << "Ошибка: файл пуст\n";
        return 1;
    }

    try
    {
        auto root = parseExpression(expression);
        
		//FIX_ME: отсутствует вывод исходного дерева до упрощения
		// Добавлен вывод исходного дерева до и после упрощения 
        std::cout << "\nИсходное дерево:\n";
        printTree(root);

        root = simplifyTree(root);

        std::cout << "\nПреобразованное дерево:\n";
        printTree(root);

        std::cout << "\nАдрес корня дерева: " << root.get() << std::endl;
        std::cout << "Значение корня: " << root->value << std::endl;

    }
    catch (const std::exception& ex)
    {
        std::cout << "Ошибка: " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}