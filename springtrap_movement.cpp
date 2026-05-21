#include "functions.hpp"
//позиция Спрингтрапа вдалеке офиса - камеры от 2 до 15.
//позиция 0 - сон, позиция 1 - за окном, позиция 16 - бег, позиция 17 - за углом,
//позиция 18 - камера 01, позиция 19 - у двери, позиция 20 - с правой стороны офиса, позиция 21 - скример.

void move(int a){
    if (cameras_open && current_camera_time != 0)
        if (((current_cam == springtrap_position || current_cam == a) && !vent_cams) || ((current_vent_cam == springtrap_position || current_vent_cam == a) && vent_cams))
        std::cout << "Перемещение." << std::endl;
    springtrap_position = a;
    radar_text();
}

void opportunities(int current_pos, int opt1, int opt2, int opt3){
    if (springtrap_position == current_pos){
        int a = rng(1,4);
        if (a == 1) total_turns++;
        else if (a == 2) move(opt1);
        else if (a == 3) move(opt2);
        else if (a == 4){
            if (opt3 != 0) move(opt3);
            else {
                int b = rng(0, 1);
                if (current_pos == 5){
                    if (b == 0) move(4);
                    else move(13);
                }
                else if (current_pos == 2){
                    if (!DoorIsClosed) move(20);
                    else {
                    if (b == 0) move(1);
                    else move(15);
                    }
                }
            }
        }
    }

}

void vent_move(int a, int b, int c){
    if (springtrap_position == a){
        if (a == sealed_vent_cam) move(b);
        else move(c);
    }
}

void movement(){
    if (springtrap_ai != 0){
        if (move_counter > 10 - springtrap_ai + rng(0,14) - total_turns){
            opportunities(10, 9, 9, 14);
            opportunities(9, 10, 8, 11);
            opportunities(8, 9, 7, 5);
            opportunities(7, 8, 6, 12);
            opportunities(6, 7, 5, 5);
            opportunities(5, 6, 2, 0);
            opportunities(4, 2, 3, 3);
            opportunities(3, 4, 1, 1);
            opportunities(2, 5, 4, 0);
            opportunities(16, 16, 17, 17);
            opportunities(17, 18, 19, 19);
            opportunities(18, 17, 19, 19);
            vent_move(11, 9, 17);
            vent_move(12, 7, 17);
            vent_move(13, 5, 1);
            vent_move(14, 10, 20);
            vent_move(15, 2, 20);
            if (cameras_open) opportunities(19, 20, 20, 20);
            else opportunities(19, 21, 21, 21);
            //прописать переходы на позициях 1, 2, 5, 20
            if (springtrap_position == 1){
                int a = rng(1,2);
                if (a == 2){
                    std::cout << "Спрингтрап перебегает около окна" << std::endl;
                    move(0);
                }
            }
            move_counter = 0;
            total_turns = 0;
        }
    }
}

void lure_move(int a, int pos_near, int c, int d, int e){
    if (springtrap_position == pos_near && (a == c || a == d || a == e)) move(a);
}

void audio_lure(int a){
    int sound = rng(1,7);
    if (current_audio_uses > 0 && sound != 1){
        sound = rng(1,3);
        if (sound == 1) std::cout << "Hello!" << std::endl;
        else if (sound == 2) std::cout << "Hi!" << std::endl;
        else if (sound == 3) std::cout << "Ha-ha-ha!" << std::endl;
        lure_move(a, 1, 2, 2, 2);
        lure_move(a, 2, 3, 4, 5);
        lure_move(a, 3, 2, 4, 4);
        lure_move(a, 4, 2, 3, 3);
        lure_move(a, 5, 2, 6, 8);
        lure_move(a, 6, 5, 7, 7);
        lure_move(a, 7, 6, 8, 8);
        lure_move(a, 8, 5, 7, 9);
        lure_move(a, 9, 8, 10, 10);
        lure_move(a, 10, 9, 9, 9);
        lure_move(a, 19, 18, 18, 18);
    }
    if (current_audio_uses > 0) current_audio_uses--;
}

void force_move(int level, int position){
    if (level == 2 && springtrap_position > 5 && springtrap_position < 11){
        if (sealed_vent_cam != 14){
            int temp_pos = rng(4,6);
            if (temp_pos == 6) move(10);
            else move(temp_pos);
        }
        else springtrap_position = rng(4,5);
    }
    else if (springtrap_position == 5) move(2);
    else if (springtrap_position == 2) move(1);
}