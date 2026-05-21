#include "functions.hpp"
/**
 * Функция удаляет указанное количество строк, начиная снизу вверх.
 * @param lines_count — сколько строк текста нужно стереть.
 */
void delete_text(int lines_count) {
    for (int i = 0; i < lines_count; ++i) {
        // 1. Поднимаем курсор на строку вверх
        // 2. Стираем строку целиком
        std::cout << "\033[A\033[2K" << std::flush;
    }
}

