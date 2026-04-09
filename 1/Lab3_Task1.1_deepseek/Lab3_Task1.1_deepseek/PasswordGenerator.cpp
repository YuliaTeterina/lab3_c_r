// PasswordGenerator.cpp
#include "PasswordGenerator.h"
#include <random>
#include <algorithm>
#include <stdexcept>

//FIX_ME: для имён переменных, параметров функций и методов необходимо использовать lowerCamelCase

/**
 * @brief Конструктор.
 * @param InComplexity Уровень сложности.
 */
FPasswordGenerator::FPasswordGenerator(EPasswordComplexity inComplexity)
    : complexity(inComplexity)
{
}

/**
 * @brief Возвращает строку со всеми символами, разрешёнными для текущей сложности.
 * @return Строка разрешённых символов.
 */
std::string FPasswordGenerator::getAllowedCharacters() const
{
    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    switch (complexity)
    {
    case EPasswordComplexity::Easy:
        return lowercase;
    case EPasswordComplexity::Medium:
        return lowercase + uppercase + digits;
    case EPasswordComplexity::Hard:
        return lowercase + uppercase + digits + special;
    default:
        throw std::invalid_argument("Неизвестный уровень сложности");
    }
}

/**
 * @brief Возвращает длину пароля для текущей сложности.
 * @return Длина пароля.
 */
int FPasswordGenerator::getPasswordLength() const
{
    switch (complexity)
    {
    case EPasswordComplexity::Easy:   return 6;
    case EPasswordComplexity::Medium: return 10;
    case EPasswordComplexity::Hard:   return 14;
    default:
        throw std::invalid_argument("Неизвестный уровень сложности");
    }
}

/**
 * @brief Генерирует случайный пароль.
 * @return Сгенерированный пароль.
 */
std::string FPasswordGenerator::generatePassword() const
{
    const std::string AllowedChars = getAllowedCharacters();
    const int Length = getPasswordLength();

    // Проверка, что набор символов не пуст
    if (AllowedChars.empty())
    {
        throw std::runtime_error("Набор символов для генерации пароля пуст");
    }

    // Используем криптографически стойкий генератор случайных чисел
    std::random_device RandomDevice;
    std::mt19937 Generator(RandomDevice());
    std::uniform_int_distribution<size_t> Distribution(0, AllowedChars.size() - 1);

    std::string Password;
    Password.reserve(Length);

    for (int i = 0; i < Length; ++i)
    {
        Password.push_back(AllowedChars[Distribution(Generator)]);
    }

    return Password;
}