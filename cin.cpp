#include "functions.hpp"
int cin(){
    int a;
    std::cin >> a;

    // \033[H  - возвращает курсор в левый верхний угол (1,1)
    // \033[2B - перемещает курсор на 2 строки вниз (на начало 3-й строки)
    // \033[J  - очищает всё от текущего положения курсора до конца экрана
    // std::cout << "\033[H\033[25B\033[J" << std::flush;
        // if (tester_console) std::cout << "\033[H\033[22B\033[J" << std::flush;
    if (game_running) indent(3);
    std::cout << "\033[H\033[J" << std::flush;
    indent(2);

    return a;
}