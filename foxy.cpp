#include "functions.hpp"

void phanthom_foxy_appear(){
    int random_number;
    if (night == 2) random_number = 1000;
    else if (night == 3) random_number = 50;
    else if (night == 4) random_number = 25;
    else if (night > 4) random_number = 10;
    random_number = rng(1,random_number);
    if (random_number == 1) foxy_in_office = true;
}