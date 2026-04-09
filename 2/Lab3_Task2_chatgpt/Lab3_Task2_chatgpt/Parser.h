#pragma once
#include <memory>
#include <string>
#include "tree.h"

// Построение дерева из префиксного выражения
std::shared_ptr<TreeNode> parseExpression(const std::string& expression);