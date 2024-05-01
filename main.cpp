#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"
#include "utils.h"
#include "draw.h"
using namespace std;

void init(){
    tc::clean_screen();
    tc::hide_cursor();
    draw::window(1,1,9,6,"Hold");
    draw::window(1,10,12,22,"Tetriz");
    draw::window(7,1,9,16,"Status");
    draw::window(19,22,8,4,"Info");
    draw::window(1,22,8,18,"Next");
}
void loop(){
    int i=0;

    while(true){

        tc::move_to(16,4);
        tc::set_back_color(15);
        tc::set_fore_color(1);
        cout<<"Fps:"<<utils::fps();

        tc::move_to(i+++2,10);
        tc::set_back_color(15);
        cout<<"  "<<flush;
        this_thread::sleep_for(10ms);
        tc::reset_color();
        // tc::clean_screen();
        i%=4;
    }
}

void exit(){
    tc::clean_screen();
    tc::show_cursor();
    tc::reset_color();
}


int main(){
    init();
    loop();
    exit();
    return 0;
}