#include "TreeBuilder.h"
#include "Node.h"
#include <stdexcept>
#include <cctype>

//FIX_ME: фигурные скобки стоят в неправильных местах
//Изменено: все скобки перенесены

Node* buildTree(const std::vector<std::string>& tokens, size_t& index) 
{
    if (index >= tokens.size()) 
    {
        throw std::runtime_error("Неожиданный конец выражения");
    }

    const std::string& token = tokens[index++];

    // Если токен – число (одна цифра)
    if (token.size() == 1 && std::isdigit(token[0])) 
    {
        int value = token[0] - '0';
        return new Node(value);
    }

    //FIX_ME: необходимо отделять ifelse фигурными скобками
    // Иначе оператор
    /*int opCode;
    if (token == "+") opCode = -1;
    else if (token == "-") opCode = -2;
    else if (token == "*") opCode = -3;
    else if (token == "/") opCode = -4;
    else if (token == "%") opCode = -5;
    else if (token == "^") opCode = -6;
    else {
        throw std::runtime_error("Неизвестный оператор: " + token);
    }*/

    int opCode;
    if (token == "+") 
    {
        opCode = -1;
    }
    else if (token == "-") 
    {
        opCode = -2;
    }
    else if (token == "*") 
    {
        opCode = -3;
    }
    else if (token == "/") 
    {
        opCode = -4;
    }
    else if (token == "%") 
    {
        opCode = -5;
    }
    else if (token == "^") 
    {
        opCode = -6;
    }
    else 
    {
        throw std::runtime_error("Неизвестный оператор: " + token);
    }

    // Рекурсивно строим левое и правое поддеревья
    Node* left = buildTree(tokens, index);
    Node* right = buildTree(tokens, index);
    return new Node(opCode, left, right);
}