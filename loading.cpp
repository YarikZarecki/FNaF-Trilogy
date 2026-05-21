#include <thread>
#include "functions.hpp"

void loading(){
    std::cout << "Загрузка...";
    //устанавливаем ИИ Спрингтрапа и его позицию на камерах
    if (night > 1 && night < 6) springtrap_ai = night;
    else if (night == 6) springtrap_ai = 7;
    if (springtrap_ai != 0) springtrap_position = rng(6, 10);

    //устанавливаем ограничения в использовании аудио, камер и вентиляции
    if (night > 1 && night < 6) {
        audio_uses_per_night = 7 - night;
        camera_time_per_night = 84 - 12 * night;
        ventilation_time_per_night = 130 - 10 * night;
    }
    else if (night == 6) {
        audio_uses_per_night = 2;
        camera_time_per_night = 17;
        ventilation_time_per_night = 60;
    }
    if (no_errors){
        audio_uses_per_night = -1;
        camera_time_per_night = -1;
        ventilation_time_per_night = -1;
    }
    current_audio_uses = audio_uses_per_night;
    current_camera_time = camera_time_per_night;
    current_ventilation_time = ventilation_time_per_night;

    //устанавливаем время и длину часа (в секундах)
    hour = 0;
    if (night == 1) hour_lenght = 40;
    else hour_lenght = 60;
    if (fast_nights) hour_lenght /= 2;

    //устанавливаем камеру, положение игрока в офисе время, длину часа
    current_cam = 2;
    current_vent_cam = 11;
    sealed_vent_cam = 0;
    vent_cams = false;
    cameras_open = false;
    maintenance_panel_opened = false;
    DoorIsClosed = false;

    std::cout << "\033[2J\033[H" << std::flush;
    std::cout << night << " ночь." << std::endl;
    game_running = true;

    std::cout << "\033[H";
    indent(2);

    if (tester_console) indent(22);

    office_position();
}