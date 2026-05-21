#include "functions.hpp"

void wrong_number() {
    std::cout << "Неправильное число. Выбери снова.";
    std::cout << "\033[A\033[2K\r";
}

void wrong_letter() {
    std::cout << "Неправильная буква. Выбери снова.";
    std::cout << "\033[A\033[2K\r";
}