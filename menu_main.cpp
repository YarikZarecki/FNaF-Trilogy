#include "functions.hpp"

//сделать экран "Внимание, скримеры" в начале игры, вероятно, через мейн
//написать текст для начальной газеты
//идея для оптимизации: булевое значение loading, что правдиво во время текста 12 AM Night X.
//Когда оно правдиво, фоновый поток загружает всё, что описано в loading.cpp

void night_begining(int number){
//выводим ночь, время
    std::cout << "\033[2J\033[H" << std::flush;
    std::cout << number << " ночь" << std::endl;
    std::cout << "12 AM" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
    loading();
}

void night_select(){
    while (night < 1 || night > 6) {
        std::cout << "Выбери ночь от 1 до 6: ";
        night = cin();
        if (night < 1 || night > 6) wrong_number();
        else break;
    }
    night_begining(night);
}

void main_menu(){
    game_running = false;
    //удаляем прошлые строчки
    std::cout << "\033[2J\033[H" << std::flush;
    std::cout << "Чтобы начать новую игру, введи 1." << std::endl;
    std::cout << "Чтобы продолжить игру, введи 2." << std::endl;
    std::cout << "Чтобы начать кошмар, введи 3." << std::endl;
    std::cout << "Чтобы открыть меню Extra, введи 4." << std::endl;
    int number = cin();
    std::cout << "\033[2J\033[H" << std::flush;
    if (number == 1){
        std::cout << "Текст газеты.";//написать текст позже
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::cout << "\033[A\033[2K\r";//Команда, удаляющая строку
        night_begining(1);
    }
    else if (number == 2) night_select();
    else if (number == 3) night_begining(6);
    else if (number == 4) extra_menu();
    else wrong_number();
}
