#include "control.h"
#include <termios.h>
#include <string>
#include <thread>
#include "tetromino.h"

bool game::_is_running;
char game::command;
int game::_row;
int game::_col;
mino::Tetromino game::cur;

std::map<char,std::function<void()>> game::common_func{
    {'q',game::command_quit},
    {'w',game::command_rotate},
    {'s',game::command_down},
    {'a',game::command_left},
    {'d',game::command_right}
};


void game::init()
{
    _is_running = true;
    command = ' ';
    _row = 2;
    _col = 15;
    cur = mino::L;
}

// 无回显,不缓冲
char game::getch()
{
    char c;
    termios old,cur;
    tcgetattr(0,&cur);// 获取终端属性
    old = cur;
    cfmakeraw(&cur);// 设置成raw.没有缓冲,没有回显
    tcsetattr(0,0,&cur);// 设置终端属性
    c = getchar();
    tcsetattr(0,0,&old);// 恢复终端属性
    return c;
}

int game::row()
{
    return _row;
}

int game::col()
{
    return _col;
}

void game::key_event()
{
    while (is_running())
    {
        command = getch();
        if(common_func.find(command)==common_func.end())continue;
        common_func[command]();
    }
}

bool game::is_running()
{
    return _is_running;
}

void game::start_key_listener()
{
    std::thread th(&game::key_event);
    th.detach();
}

void game::command_quit()
{
    game::_is_running = false;
}

void game::command_rotate()
{
    // _row--;
    cur = mino::rotate(cur);
}

void game::command_left()
{
   _col--;
}

void game::command_right()
{
    _col++;
}

void game::command_down()
{
    _row++;
}
