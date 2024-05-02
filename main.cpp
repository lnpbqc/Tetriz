#include <iostream>
#include <thread>
#include <chrono>

#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
using namespace std;

void init(){
    tc::clean_screen();
    tc::hide_cursor();
    game::start_key_listener();
}
void loop(){
    game::init();

    while(game::is_running()){
        // 绘制窗口
        draw::window(1,1,9,6,"Hold");
        draw::window(1,10,12,22,"Tetriz");
        draw::window(7,1,9,16,"Status");
        draw::window(19,22,8,4,"Info");
        draw::window(1,22,8,18,"Next");

        // 绘制FPS
        tc::move_to(16,4);
        tc::set_fore_color(1);
        cout<<"Fps:"<<utils::fps();

        draw::tetromino(game::cur,game::row(),game::col());
        cout<<flush;
        this_thread::sleep_for(10ms);
        tc::reset_color();
        tc::clean_screen();
    }
}

void exit(){
    tc::clean_screen();
    tc::show_cursor();
    tc::reset_color();
    tc::move_to(0,0);
    cout<<"Bye!"<<endl;
}


int main(){
    init();
    loop();
    exit();
    return 0;
}
