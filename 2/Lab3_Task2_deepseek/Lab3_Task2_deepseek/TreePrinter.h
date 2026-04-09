#pragma once

#include <iostream>

class Node;

//FIX_ME: изменена логика вывода дерева

/**
 * Выводит дерево в текстовом виде с отступами (по одному узлу на строку).
 * @param node корень дерева или поддерева
 * @param depth текущая глубина (количество отступов)
 */
void printTreeIndented(Node* node, int depth = 0);
