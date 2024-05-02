#pragma once
#include <string>
#include "tetromino.h"
#include "utils.h"
namespace draw
{
    void window(int x,int y,int width,int height,std::string title);
    void tetromino(mino::Tetromino& t,int x,int y);
} // namespace draw
