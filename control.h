#pragma once


#include <map>
#include <functional>
#include "tetromino.h"

namespace game
{
    extern bool _is_running;
    extern char command;
    extern std::map<char,std::function<void()>> common_func;
    extern mino::Tetromino cur;// 当前操作的方块

    extern int _row,_col;

    int row();
    int col();

    char getch();
    void key_event();
    bool is_running();
    void start_key_listener();
    void init();

    void command_quit();
    void command_rotate();
    void command_left();
    void command_right();
    void command_down();
} // namespace game
