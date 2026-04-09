#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include "Node.h"
#include "TreeBuilder.h"
#include "TreeTransformer.h"
#include "TreePrinter.h"

//FIX_ME: фигурные скобки стоят в неправильных местах
//Изменено: все скобки перенесены

/**
 * Разбивает строку на токены по пробелам и переводам строк.
 */
std::vector<std::string> tokenize(const std::string& str) 
{
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (iss >> token) 
    {
        tokens.push_back(token);
    }
    return tokens;
}

/**
 * Проверяет, что все токены являются допустимыми (цифры 0-9 или операции + - * / % ^).
 */
bool validateTokens(const std::vector<std::string>& tokens) 
{
    for (const auto& token : tokens) 
    {
        if (token.size() == 1 && std::isdigit(token[0])) 
        {
            continue;
        }
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%" || token == "^") 
        {
            continue;
        }
        return false;
    }
    return true;
}

//FIX_ME:

/**
 * Возвращает строковое представление кода операции.
 */
std::string opCodeToString(int opCode) {
    switch (opCode) {
    case -1: return "+";
    case -2: return "-";
    case -3: return "*";
    case -4: return "/";
    case -5: return "%";
    case -6: return "^";
    default: return "?";
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian"); // для вывода сообщений на русском

    std::string filename = "C:/Users/Julia/source/repos/laba3_c_r/2/Lab3_Task2_deepseek/Lab3_Task2_deepseek/tree.txt";
    std::ifstream file(filename);

    if (!file.is_open()) 
    {
        std::cerr << "Ошибка: не удалось открыть файл " << filename << std::endl;
        return 1;
    }

    // Читаем весь файл в одну строку
    std::string content;
    std::string line;
    while (std::getline(file, line)) 
    {
        content += line + " ";
    }
    file.close();

    if (content.empty()) {
        std::cerr << "Ошибка: файл пуст" << std::endl;
        return 1;
    }

    // Разбор на токены
    std::vector<std::string> tokens = tokenize(content);
    if (tokens.empty()) 
    {
        std::cerr << "Ошибка: в файле нет токенов" << std::endl;
        return 1;
    }

    // Проверка корректности токенов
    if (!validateTokens(tokens)) 
    {
        std::cerr << "Ошибка: обнаружены недопустимые символы в выражении" << std::endl;
        return 1;
    }

    Node* root = nullptr;
    try {
        size_t index = 0;
        root = buildTree(tokens, index);
        if (index != tokens.size()) 
        {
            throw std::runtime_error("После построения дерева остались лишние токены");
        }
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка при построении дерева: " << e.what() << std::endl;
        delete root;
        return 1;
    }

    //FIX_ME: Добавлен вывод изначального дерева
    std::cout << "Исходное дерево:" << std::endl;
    printTreeIndented(root);


    // Преобразование дерева
    try 
    {
        transformTree(root);
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка при вычислении: " << e.what() << std::endl;
        delete root;
        return 1;
    }


    // Вывод результата
    std::cout << "\nПреобразованное дерево: ";
    printTreeIndented(root);
    std::cout << std::endl;

    //Добавлено: Вывод указателя на корень
    std::cout << "Указатель на корень: " << static_cast<void*>(root) << std::endl;

    //Добавлено: Вывод значения корневого узла
    if (root->getType() == Node::Type::Operand) {
        std::cout << "Корень: операнд, значение = " << root->getValue() << std::endl;
    }
    else {
        std::cout << "Корень: оператор, код = " << root->getValue()
            << " (" << opCodeToString(root->getValue()) << ")" << std::endl;
    }

    delete root;
    return 0;
}