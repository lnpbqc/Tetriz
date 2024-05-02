#pragma once
#include <vector>
#include <map>


namespace mino
{
    // I[5][5] JLOSTZ[3][3]
    using Tetromino = std::vector<std::vector<int>>;

    enum class Color{
        Cyan = 14,
        Red = 9,
        Orange = 214,
        Yellow = 11,
        Green = 2,
        Blue = 12,
        Purple = 5
    };

    extern Tetromino I,J,L,O,S,T,Z;

    extern std::map<int,Color> minoColor;

    Tetromino rotate(Tetromino& t);
    Color getMinoColor(int t);

} // namespace mino
