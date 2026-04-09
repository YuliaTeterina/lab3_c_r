// ============================
// File: PasswordGenerator.h
// ============================
#pragma once

#include <string>

// Перечисление уровней сложности
enum class EPasswordStrength
{
    Easy = 1,
    Medium,
    Hard
};

class FPasswordGenerator
{
public:
    // Основная функция генерации пароля
    static std::string generatePassword(EPasswordStrength strength);

private:
    static std::string getCharacters(EPasswordStrength strength);
    static int getLength(EPasswordStrength strength);
};