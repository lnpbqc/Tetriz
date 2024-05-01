#pragma once

#include <chrono>

namespace utils
{
    int fps();
    // 每块由两列组成,如第十块位于19列
    inline int b2c(int bindex){
        return bindex*2-1;
    }
} // namespace utils
