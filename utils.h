#pragma once

#include <chrono>

namespace utils
{
    int fps();
    inline int b2c(int bindex){
        return bindex*2-1;
    }
} // namespace utils
