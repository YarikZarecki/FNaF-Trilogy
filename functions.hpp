#pragma once
#include <iostream>
#include <atomic>
#include <chrono>
#include <thread>
#include <vector>

extern std::atomic<bool> game_running;
extern std::atomic<int> move_counter;
extern std::atomic<int> hour;

inline auto start_time = std::chrono::steady_clock::now();
inline auto current_time = std::chrono::steady_clock::now();
inline auto elapsed = std::chrono::steady_clock::now();

inline int hour_lenght;
inline int night, springtrap_ai, springtrap_position, total_turns;

inline int current_audio_uses, audio_uses_per_night;
inline int current_camera_time, camera_time_per_night;
inline int current_ventilation_time, ventilation_time_per_night;

inline int current_cam, current_vent_cam, sealed_vent_cam;
inline bool vent_cams; //переменная правдива если открыты камеры с 11 по 15

inline bool only_office, maintenance_panel_opened, cameras_open, DoorIsClosed;

inline bool repairing = false;

inline int player_change;
inline bool fast_nights, agressive, radar, no_errors;//активация читов
void radar_text();

void main_menu();
void extra_menu();
inline const std::vector<std::string> russian_animatronic_names = {
        "Спрингтрап",
        "Фантом Фредди", 
        "Фантом Чика", 
        "Фантом Фокси", 
        "Фантом ББ", 
        "Фантом Мангл", 
        "Фантом Марионетка"
};

inline bool foxy_in_office = false;
inline bool russian = true, english, polish;
void print(const char* russian, const char* english, const char* polish);

void camera_system();
//функции
int cin();
void wrong_number();
void wrong_letter();
void indent(int m);
void writing_y(bool a);
void print_cheat(bool b);
void cheat_menu();
void office_position();
void night_select();
void loading();
void ending_night();
void night_begining(int number);

void phanthom_jumpscare(const char* animatronic_name, bool phanthom_in_office);

inline bool tester_console;
void tester();

void phanthom_foxy_appear();
//геймплейные функции
void update();
void delete_text(int lines_count);
int rng(int min, int max);
void game_timer();
void audio_lure(int a);
void system_repair();
void broken_systems();
void movement();
void vent_move(int a, int b, int c);

