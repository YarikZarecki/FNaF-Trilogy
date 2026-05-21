#include "functions.hpp"

std::atomic<bool> game_running(false);
std::atomic<int> move_counter(0);
std::atomic<int> hour(0);

// void timer_function() {
//     while(!game_running){
//         std::cout << "\033[s" << "\033[H";
//         tester();
//         std::cout << "\033[u" << std::flush;;
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }
//     auto start_time = std::chrono::steady_clock::now();
//     while (game_running) {
//         auto current_time = std::chrono::steady_clock::now();
//         auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();

//         // ANSI escape codes: 
//         // \033[s - сохранить позицию курсора
//         // \033[H - переместить курсор в начало (0,0)
//         // \033[K - очистить строку
//         // \033[u - вернуть курсор обратно
//         std::cout << "\033[s" << "\033[H" << std::endl;
//         std::cout << "\033[K";
//         std::cout << elapsed << " секунда, " << hour << " минута." << std::flush;
//         if (elapsed >= hour_lenght){
//             start_time = std::chrono::steady_clock::now();
//             hour++;
//         }
        
//         movement();
//         tester();
//         std::cout << "\033[u" << std::flush;
//         std::this_thread::sleep_for(std::chrono::seconds(1));
//     }
// }

int main(){
    std::cout << "\033[2J\033[H" << std::flush;
    //std::thread timer_function_thread(timer_function);
    main_menu();

    // if (timer_function_thread.joinable()) {
    //      timer_function_thread.join();
    // }

    return 0;
}
