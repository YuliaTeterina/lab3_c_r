// main.cpp
#include "PasswordGenerator.h"
#include "Utils.h"
#include <iostream>

//FIX_ME: отсутствует подключение библиотеки для использования русского языка
#include <clocale>

/**
 * @brief Точка входа в программу.
 */
int main()
{
    //FIX_ME: отсутствует подключение библиотеки для использования русского языка
    setlocale(LC_CTYPE, "rus");
    std::cout << "Добро пожаловать в генератор паролей!\n\n";

    //FIX_ME: имена переменных не длжны совпадать со служебными
    //char continue = 'y';

    char continueFlag = 'y';
    while (continueFlag == 'y' || continueFlag == 'Y')
    {
        // Запрашиваем уровень сложности
        //EPasswordComplexity Complexity = GetComplexityFromUser();
        EPasswordComplexity complexity = getComplexityFromUser();

        // Создаём генератор
        FPasswordGenerator generator(complexity);

        try
        {
            // Генерируем пароль
            std::string password = generator.generatePassword();

            // Выводим результат
            std::cout << "\nСгенерированный пароль: " << password << "\n\n";
        }
        catch (const std::exception& ex)
        {
            std::cerr << "Ошибка при генерации пароля: " << ex.what() << "\n";
            return 1;
        }

        // Спрашиваем, нужно ли сгенерировать ещё
        std::cout << "Сгенерировать ещё один пароль? (y/n или любой другой символ для выхода): ";
        std::cin >> continueFlag;
        clearInputStream();

        std::cout << "\n";
    }

    std::cout << "До свидания!\n";
    return 0;
}