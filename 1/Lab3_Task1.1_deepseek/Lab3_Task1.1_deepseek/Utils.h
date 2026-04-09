// Utils.h
#pragma once

//FIX_ME: идентификатор EPasswordComplexity не определён в этом файле, нужно подключить PasswordGenerator.h
#include "PasswordGenerator.h"

/**
 * @brief Запрашивает у пользователя уровень сложности пароля.
 * @return Выбранный уровень сложности.
 */
EPasswordComplexity getComplexityFromUser();

/**
 * @brief Очищает входной буфер и игнорирует оставшиеся символы до новой строки.
 */
void clearInputStream();