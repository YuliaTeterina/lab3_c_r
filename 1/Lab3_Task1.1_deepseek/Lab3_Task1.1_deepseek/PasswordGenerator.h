// PasswordGenerator.h
#pragma once

#include <string>

/**
 * @brief Перечисление уровней сложности пароля.
 */
enum class EPasswordComplexity
{
    Easy,   // только строчные буквы, длина 6
    Medium, // строчные + прописные + цифры, длина 10
    Hard    // строчные + прописные + цифры + спецсимволы, длина 14
};

/**
 * @brief Класс для генерации паролей заданной сложности.
 */
class FPasswordGenerator
{
public:
    /**
     * @brief Конструктор, принимающий уровень сложности.
     * @param InComplexity Уровень сложности пароля.
     */
    explicit FPasswordGenerator(EPasswordComplexity InComplexity);

    /**
     * @brief Генерирует случайный пароль в соответствии с заданной сложностью.
     * @return Сгенерированный пароль.
     */
    std::string generatePassword() const;

private:
    /** Уровень сложности. */
    EPasswordComplexity complexity;

    /** Возвращает строку с разрешёнными символами для текущей сложности. */
    std::string getAllowedCharacters() const;

    /** Возвращает длину пароля для текущей сложности. */
    int getPasswordLength() const;
};