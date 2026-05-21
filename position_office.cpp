#include "functions.hpp"

void office_position(){
    if (game_running == true){
    
    only_office = true;
    if (springtrap_position == 1) std::cout << "Спрингтрап за окном." << std::endl;
    if (foxy_in_office == true) std::cout << "Фантом Фокси в офисе." << std::endl;
    while(only_office == true){
        if (current_ventilation_time == 0) std::cout << "Вентиляция сломана." << std::endl;
        std::cout << "Чтобы починить систему, введи 1. Чтобы открыть камеры, введи 2. Чтобы открыть/закрыть правую дверь, введи 3." << std::endl;
        int pressed_number;
        pressed_number = cin();
        if (pressed_number == 1 && foxy_in_office) phanthom_jumpscare("FOXY", foxy_in_office);
        else if (pressed_number == 1 && !foxy_in_office){
            only_office = false;
            system_repair();
        }
        else if (pressed_number == 2){
            only_office = false;
            camera_system();
        }
        else if (pressed_number == 3){
            DoorIsClosed = !DoorIsClosed;
            if (DoorIsClosed) std::cout << "Дверь закрыта." << std::endl;
            else std::cout << "Дверь открыта." << std::endl;
        }
        else wrong_number();
    }
} 

    // if (phantom_freddy == true) std::cout << "Фантом Фредди за окном." << std::endl;
    // if (phantom_mangle == true) std::cout << "Фантом Мангл за окном." << std::endl;
    // if (phantom_chica == true) std::cout << "Фантом Чика за окном." << std::endl;
}
