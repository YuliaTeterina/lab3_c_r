#include "parser.h"
#include <sstream>
#include <vector>
#include <stdexcept>

/**
 * Преобразует символ операции в код
 */
int getOperatorCode(char op)
{
    switch (op)
    {
    case '+': return -1;
    case '-': return -2;
    case '*': return -3;
    case '/': return -4;
    case '%': return -5;
    case '^': return -6;
    default:
        throw std::runtime_error("Неизвестный оператор");
    }
}

/**
 * Рекурсивный разбор префиксного выражения
 */
std::shared_ptr<TreeNode> parse(std::vector<std::string>& tokens, int& index)
{
    //FIX_ME: необходимо отделять if-else фигурными скобками

    /*if (index >= tokens.size())
        throw std::runtime_error("Ошибка разбора выражения");*/

    if (index >= tokens.size())
    {
        throw std::runtime_error("Ошибка разбора выражения");
    }

    std::string token = tokens[index++];

    // Если это число
    if (isdigit(token[0]))
    {
        int value = token[0] - '0';
        return std::make_shared<TreeNode>(value);
    }

    // Если это оператор
    int op = getOperatorCode(token[0]);
    auto node = std::make_shared<TreeNode>(op);

    node->left = parse(tokens, index);
    node->right = parse(tokens, index);

    return node;
}

std::shared_ptr<TreeNode> parseExpression(const std::string& expression)
{
    std::stringstream ss(expression);
    std::vector<std::string> tokens;
    std::string token;

    //FIX_ME: необходимо отделять циклы фигурными скобками
    while (ss >> token)
    {
        tokens.push_back(token);
    }

    int index = 0;
    return parse(tokens, index);
}