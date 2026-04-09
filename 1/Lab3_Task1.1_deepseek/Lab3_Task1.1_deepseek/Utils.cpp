// Utils.cpp
#include "Utils.h"
#include "PasswordGenerator.h"
#include <iostream>
#include <limits>

/**
 * @brief Очищает входной буфер.
 */
void clearInputStream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
 * @brief Выводит меню и запрашивает выбор пользователя.
 * @return Выбранный уровень сложности.
 */
EPasswordComplexity getComplexityFromUser()
{
    std::cout << "=== Генератор паролей ===\n";
    std::cout << "Выберите уровень сложности:\n";
    std::cout << "1 - Лёгкий (только строчные буквы, длина 6)\n";
    std::cout << "2 - Средний (строчные + прописные + цифры, длина 10)\n";
    std::cout << "3 - Сложный (строчные + прописные + цифры + символы, длина 14)\n";
    std::cout << "Введите номер (1-3): ";

    int choice = 0;
    std::cin >> choice;

    // Проверка на ошибку ввода
    if (std::cin.fail() || choice < 1 || choice > 3)
    {
        clearInputStream();
        std::cout << "Ошибка: введите число от 1 до 3.\n";
        // Рекурсивно запрашиваем снова
        return getComplexityFromUser();
    }

    clearInputStream(); // Очищаем буфер после успешного ввода

    switch (choice)
    {
    case 1: return EPasswordComplexity::Easy;
    case 2: return EPasswordComplexity::Medium;
    case 3: return EPasswordComplexity::Hard;
    default: return getComplexityFromUser(); // Защита от невозможного
    }
}