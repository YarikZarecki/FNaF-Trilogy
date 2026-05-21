#include "functions.hpp"
void broken_systems(){
    std::cout << "Сломанные системы: ";
    if (current_audio_uses != 0 && current_camera_time != 0 && current_ventilation_time != 0) std::cout << "отсутствуют.";
        if (current_audio_uses == 0) {
            std::cout << "аудио";
            if (current_camera_time != 0 && current_ventilation_time != 0) std::cout << ".";
            else std::cout << ", ";
        }
        if (current_camera_time == 0) {
            std::cout << "камеры";
            if (current_ventilation_time !=0) std::cout << ".";
            else std::cout << ", ";
        }

        if (current_ventilation_time == 0) {
            std::cout << "вентиляция.";
        }
        indent(1);
}


// void qte(int minimum){
//     int random = rng(minimum, 2*minimum);
//     int done_tasks = 0;
//     while (done_tasks < random){
//         std::cout << "Нажми"
//     }
// }

void system_repair(){
    if (game_running == true){
        maintenance_panel_opened = true;
    while (maintenance_panel_opened){
        broken_systems();
        for(int i = 1; i <= 4; i++) {
        std::cout << "Чтобы починить ";
        if (i == 1) std::cout << "аудиосистему";
        else if (i == 2) std::cout << "систему камер";
        else if (i == 3) std::cout << "вентиляционную систему";
        else std::cout << "всё";
        std::cout << ", введите число " << i << ".";
        indent(1);
        }

        std::cout << "Чтобы выйти, введите любое другое число." << std::endl;
        int repair_number = cin();
        if (repair_number == 1) current_audio_uses = audio_uses_per_night;
        else if (repair_number == 2) current_camera_time = camera_time_per_night;
        else if (repair_number == 3) current_ventilation_time = ventilation_time_per_night;
        else if (repair_number == 4){
            current_audio_uses = audio_uses_per_night;
            current_camera_time = camera_time_per_night;
            current_ventilation_time = ventilation_time_per_night;
        }
        else {
            maintenance_panel_opened = false;
            office_position();
        }
    }
}
}

