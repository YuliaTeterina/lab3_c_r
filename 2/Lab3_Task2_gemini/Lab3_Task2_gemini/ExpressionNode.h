#pragma once

/**
 * Структура узла арифметического дерева.
 * Согласно Epic Games Style, используем префикс F для структур.
 */
struct FExpressionNode
{
    int value; // Значение: 0-9 для чисел, -1..-6 для операций
    FExpressionNode* leftChild;
    FExpressionNode* rightChild;

    FExpressionNode(int inValue)
        : value(inValue)
        , leftChild(nullptr)
        , rightChild(nullptr)
    {
    }

    ~FExpressionNode()
    {
        delete leftChild;
        delete rightChild;
    }
};