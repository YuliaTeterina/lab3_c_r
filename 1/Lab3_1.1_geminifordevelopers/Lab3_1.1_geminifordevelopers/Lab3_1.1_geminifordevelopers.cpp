#include <iostream>
#include <limits>
#include "PasswordGenerator.h"

/**
 * Очистка буфера ввода для предотвращения бесконечных циклов при ошибках.
 */
void clearInputBuffer()
{
	std::cin.clear();
	std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}

int main()
{
	// Установка кодировки для Windows консоли
	setlocale(LC_ALL, "Russian");

	FPasswordGenerator passwordGenerator;
	bool bShouldExit = false;

	std::cout << "=== Генератор Безопасных Паролей ===" << std::endl;

	while (!bShouldExit)
	{
		std::cout << "\nВыберите уровень сложности пароля:" << std::endl;
		std::cout << "1 - Легкий (8 симв., только строчные буквы)" << std::endl;
		std::cout << "2 - Средний (12 симв., буквы и цифры)" << std::endl;
		std::cout << "3 - Сложный (16 симв., буквы, цифры и спецсимволы)" << std::endl;
		std::cout << "0 - Завершить программу" << std::endl;
		std::cout << "Ваш выбор: ";

		int32_t userChoice;
		std::cin >> userChoice;

		// Проверка на корректность ввода типа данных
		if (std::cin.fail())
		{
			std::cout << "Ошибка: Необходимо ввести число." << std::endl;
			clearInputBuffer();
			continue;
		}

		if (userChoice == 0)
		{
			bShouldExit = true;
			continue;
		}

		// Валидация диапазона
		if (userChoice < 1 || userChoice > 3)
		{
			std::cout << "Ошибка: Выберите пункт меню от 1 до 3." << std::endl;
			continue;
		}

		// Приведение типа и генерация
		EDifficultyLevel selectedLevel = static_cast<EDifficultyLevel>(userChoice);
		std::string newPassword = passwordGenerator.generatePassword(selectedLevel);

		std::cout << "\n----------------------------------------" << std::endl;
		std::cout << "Сгенерированный пароль: " << newPassword << std::endl;
		std::cout << "----------------------------------------" << std::endl;
	}

	std::cout << "Программа завершена." << std::endl;

	return 0;
}