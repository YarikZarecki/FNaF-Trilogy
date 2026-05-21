#include "functions.hpp"

void phanthom_jumpscare(const char* animatronic_name, bool phanthom_in_office){
    std::cout << "PHANTHOM " << animatronic_name << " JUMPSCARE!!! (страшно)" << std::endl;
    current_ventilation_time = 0;
    phanthom_in_office = false;
}