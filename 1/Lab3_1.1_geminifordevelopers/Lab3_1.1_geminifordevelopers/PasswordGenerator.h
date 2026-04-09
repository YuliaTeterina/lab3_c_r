#pragma once

#include <string>
#include <cstdint>

/** Перечисление уровней сложности пароля */
enum class EDifficultyLevel : uint8_t
{
	Easy = 1,
	Medium,
	Hard
};

/** Структура настроек сложности */
struct FComplexitySettings
{
	int32_t length;
	std::string charset;
};

/**
 * Класс для генерации случайных паролей.
 */
class FPasswordGenerator
{
public:
	FPasswordGenerator();

	/**
	 * Генерирует пароль на основе выбранного уровня сложности
	 * @param inLevel - выбранный уровень
	 * @return Сгенерированная строка пароля
	 */
	std::string generatePassword(EDifficultyLevel inLevel);

private:
	/** Инициализация наборов символов для разных уровней */
	void initializeDifficultySettings();

	/** Вспомогательная функция для получения случайного числа */
	int32_t getRandomInt(int32_t inMin, int32_t inMax);

	FComplexitySettings easySettings;
	FComplexitySettings mediumSettings;
	FComplexitySettings hardSettings;

	/** Наборы символов для формирования сложности */
	const std::string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
	const std::string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string digits = "0123456789";
	const std::string specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";
};