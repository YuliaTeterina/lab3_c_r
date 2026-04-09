// ============================
// File: main.cpp
// ============================

#include <iostream>
#include "PasswordGenerator.h"

// Проверка корректности ввода пользователя
bool isValidInput(int input)
{
    return input >= 1 && input <= 3;
}

int main()
{
    setlocale(LC_ALL, "ru");

    std::cout << "=== Генератор паролей ===\n";
    std::cout << "Выберите уровень сложности:\n";
    std::cout << "1 - Легкий (8 символов, буквы + цифры)\n";
    std::cout << "2 - Средний (12 символов, буквы разного регистра + цифры)\n";
    std::cout << "3 - Сложный (16 символов, буквы + цифры + символы)\n";

    int userChoice = 0;
    std::cin >> userChoice;

    if (!std::cin || !isValidInput(userChoice))
    {
        std::cerr << "Ошибка: введено некорректное значение!\n";
        return 1;
    }

    EPasswordStrength strength = static_cast<EPasswordStrength>(userChoice);

    std::string password = FPasswordGenerator::generatePassword(strength);

    std::cout << "\nСгенерированный пароль: " << password << "\n";

    return 0;
}
