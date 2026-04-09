#pragma once

#include <vector>
#include <string>

class Node;

/**
 * Рекурсивно строит дерево из списка токенов.
 * @param tokens список токенов (числа или символы операций)
 * @param index текущая позиция в списке (изменяется по ходу построения)
 * @return указатель на корень построенного поддерева
 * @throws std::runtime_error при ошибках разбора
 */
Node* buildTree(const std::vector<std::string>& tokens, size_t& index);