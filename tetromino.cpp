#include "tetromino.h"

namespace mino
{
    Tetromino I ({
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,1,1,1,1},
        {0,0,0,0,0},
        {0,0,0,0,0}
    });
    Tetromino J ({
        {2,0,0,},
        {2,2,2,},
        {0,0,0,},
    });
    Tetromino L ({
        {0,0,3,},
        {3,3,3,},
        {0,0,0,},
    });
    Tetromino O ({
        {0,4,4,},
        {0,4,4,},
        {0,0,0,},
    });
    Tetromino S ({
        {0,5,5,},
        {5,5,0,},
        {0,0,0,},
    });
    Tetromino T ({
        {0,6,0,},
        {6,6,6,},
        {0,0,0,},
    });
    Tetromino Z ({
        {7,7,0,},
        {0,7,7,},
        {0,0,0,},
    });

    // 为什么不直接用Tetromino作为key呢,因为每次旋转之后,它的值不一样了,会导致颜色不对,因此用填充具体的颜色的id来表示
    std::map<int,Color> minoColor{
        {1,Color::Cyan},
        {2,Color::Red},
        {3,Color::Orange},
        {4,Color::Yellow},
        {5,Color::Green},
        {6,Color::Blue},
        {7,Color::Purple}
    };

    Tetromino rotate(Tetromino &t)
    {
        Tetromino result(t.size(),std::vector<int>(t.size(),0));

        for(int i = 0;i<t.size();i++){
            for(int j = 0;j<t[0].size();j++){
                if(t[i][j]==0)continue;
                result[j][t.size()-i-1] = t[i][j];
            }
        }

        return std::move(result);
    }
    Color getMinoColor(int t)
    {
        return minoColor.find(t)->second;
    }
} // namespace mino
