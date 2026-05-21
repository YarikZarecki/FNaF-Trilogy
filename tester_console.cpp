#include "functions.hpp"

void tester(){
    if (game_running) indent(2);
    if (tester_console == true){
    std::cout << "ИИ Спрингтрапа: " << springtrap_ai << std::endl;
    std::cout << "Позиция Спрингтрапа: " << springtrap_position << std::endl;
    indent(2);
    }
}
