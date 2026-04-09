// ============================
// File: PasswordGenerator.cpp
// ============================

#include "PasswordGenerator.h"
#include <random>
#include <stdexcept>

// Возвращает набор символов в зависимости от сложности
std::string FPasswordGenerator::getCharacters(EPasswordStrength strength)
{
    const std::string lower = "abcdefghijklmnopqrstuvwxyz";
    const std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string digits = "0123456789";
    const std::string symbols = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    switch (strength)
    {
    case EPasswordStrength::Easy:
        return lower + digits;
    case EPasswordStrength::Medium:
        return lower + upper + digits;
    case EPasswordStrength::Hard:
        return lower + upper + digits + symbols;
    default:
        throw std::invalid_argument("Некорректный уровень сложности");
    }
}

// Возвращает длину пароля в зависимости от сложности
int FPasswordGenerator::getLength(EPasswordStrength strength)
{
    switch (strength)
    {
    case EPasswordStrength::Easy:
        return 8;
    case EPasswordStrength::Medium:
        return 12;
    case EPasswordStrength::Hard:
        return 16;
    default:
        throw std::invalid_argument("Некорректный уровень сложности");
    }
}

// Генерация случайного пароля
std::string FPasswordGenerator::generatePassword(EPasswordStrength strength)
{
    const std::string characters = getCharacters(strength);
    const int length = getLength(strength);

    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> distribution(0, static_cast<int>(characters.size() - 1));

    std::string result;
    result.reserve(length);

    for (int i = 0; i < length; ++i)
    {
        result += characters[distribution(generator)];
    }

    return result;
}