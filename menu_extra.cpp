#include "functions.hpp"

void writing_y(bool a) {
    if (a) std::cout << "ы";
}

void print_cheat(bool b) {
    std::cout << "Для в";
    writing_y(b);
    std::cout << "ключения ";
}

void cheat_activated(char inp, char number, bool cheat, const char* first_half_of_text, const char* second_half_of_text){
    if (inp == number) {
                cheat = !cheat;
                std::cout << first_half_of_text;
                writing_y(!cheat);
                std::cout << second_half_of_text;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
}

void extra_menu(){
    bool animatronic_names = true;
    int current_index = 0;
    char input;
    while (true){
        if (animatronic_names){
            std::cout << "Аниматроник: " << russian_animatronic_names[current_index] << "." << std::endl;
            std::cout << "Чтобы выбрать читы, введи S." << std::endl;
            std::cout << "Чтобы посмотреть имя предыдущего аниматроника, введи A." << std::endl;
            std::cout << "Чтобы посмотреть имя следующего аниматроника, введи D." << std::endl;
            std::cout << "Чтобы выйти из меню Extra, введи Q." << std::endl;

            std::cin >> input;
            input = toupper(input);

            if (input == 'S') animatronic_names = false;
            else if (input == 'A'){
                if (current_index > 0) current_index--;
            }
            else if (input == 'D'){
                if (current_index < 6) current_index++;
            }
            else if (input == 'Q') break;
            else wrong_letter();
        }
        else if (!animatronic_names){
            std::cout << "Чтобы посмотреть имена аниматроников, введи W." << std::endl;
            print_cheat(fast_nights);
            std::cout << "быстрых ночей, введи 1." << std::endl;
            print_cheat(agressive);  
            std::cout << "агрессии, введи 2." << std::endl;
            print_cheat(radar);
            std::cout << "радара, введи 3." << std::endl;
            print_cheat(no_errors);   
            std::cout << "отсутствия ошибок, введи 4." << std::endl;
            std::cout << "Для включения режима тестера, введи 5." << std::endl;
            std::cout << "Чтобы выйти из меню Extra, введи Q." << std::endl;

            indent(1);
            std::cin >> input;
            input = toupper(input);

            if (input == 'W') animatronic_names = true;
            else if (input == 'Q') break;
            else if (input != '1' && input != '2' && input != '3' && input != '4' && input != '5') wrong_letter();

            cheat_activated(input, '1', fast_nights, "Быстрые ночи в", "ключены.");
            cheat_activated(input, '2', agressive, "Режим агрессии в", "ключен.");
            cheat_activated(input, '3', agressive, "Радар в", "ключен.");
            cheat_activated(input, '4', agressive, "Отсутствие ошибок в", "ключено.");
            cheat_activated(input, '5', agressive, "Режим тестера в", "ключен.");
        }
        //удаляем прошлые строчки
        std::cout << "\033[2J\033[H" << std::flush;
    }
    main_menu();
}