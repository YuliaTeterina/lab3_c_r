#include "PasswordGenerator.h"
#include <random>

FPasswordGenerator::FPasswordGenerator()
{
	initializeDifficultySettings();
}

void FPasswordGenerator::initializeDifficultySettings()
{
	// Легкий: Только строчные буквы, длина 8
	easySettings.length = 8;
	easySettings.charset = lowercaseChars;

	// Средний: Буквы разных регистров и цифры, длина 12
	mediumSettings.length = 12;
	mediumSettings.charset = lowercaseChars + uppercaseChars + digits;

	// Сложный: Полный набор символов, длина 16
	hardSettings.length = 16;
	hardSettings.charset = lowercaseChars + uppercaseChars + digits + specialChars;
}

std::string FPasswordGenerator::generatePassword(EDifficultyLevel inLevel)
{
	FComplexitySettings* currentSettings;

	// Выбор настроек в зависимости от уровня
	switch (inLevel)
	{
	case EDifficultyLevel::Easy:
		currentSettings = &easySettings;
		break;
	case EDifficultyLevel::Medium:
		currentSettings = &mediumSettings;
		break;
	case EDifficultyLevel::Hard:
	default:
		currentSettings = &hardSettings;
		break;
	}

	std::string generatedPassword = "";
	int32_t charsetSize = static_cast<int32_t>(currentSettings->charset.length());

	// Алгоритм формирования строки: берем случайный индекс из charset n раз
	for (int32_t i = 0; i < currentSettings->length; ++i)
	{
		int32_t randomIndex = getRandomInt(0, charsetSize - 1);
		generatedPassword += currentSettings->charset[randomIndex];
	}

	return generatedPassword;
}

int32_t FPasswordGenerator::getRandomInt(int32_t inMin, int32_t inMax)
{
	// static гарантирует, что генератор инициализируется один раз, а не при каждом вызове
	static std::random_device road;
	static std::mt19937 generator(road());
	std::uniform_int_distribution<int32_t> distribution(inMin, inMax);

	return distribution(generator);
}