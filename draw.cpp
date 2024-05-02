#include "draw.h"
#include "terminal.h"
#include "utils.h"
/*
* https://en.wikipedia.org/wiki/Box-drawing_characters
 	    0	1	2	3	4	5	6	7	8	9	A	B	C	D	E	F
U+250x	─	━	│	┃	┄	┅	┆	┇	┈	┉	┊	┋	┌	┍	┎	┏
U+251x	┐	┑	┒	┓	└	┕	┖	┗	┘	┙	┚	┛	├	┝	┞	┟
U+252x	┠	┡	┢	┣	┤	┥	┦	┧	┨	┩	┪	┫	┬	┭	┮	┯
U+253x	┰	┱	┲	┳	┴	┵	┶	┷	┸	┹	┺	┻	┼	┽	┾	┿
U+254x	╀	╁	╂	╃	╄	╅	╆	╇	╈	╉	╊	╋	╌	╍	╎	╏
U+255x	═	║	╒	╓	╔	╕	╖	╗	╘	╙	╚	╛	╜	╝	╞	╟
U+256x	╠	╡	╢	╣	╤	╥	╦	╧	╨	╩	╪	╫	╬	╭	╮	╯
U+257x	╰	╱	╲	╳	╴	╵	╶	╷	╸	╹	╺	╻	╼	╽	╾	╿
*/


void draw::window(int x, int y, int width, int height, std::string title)
{
    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
            tc::move_to(x+i,utils::b2c(y+j));
            if(i==0){
                if(j==0){
                    std::cout<<" ┌";
                }else if(j==width-1){
                    std::cout<<"┐ ";
                }else{
                    std::cout<<"──";
                }
            }else if(i==height-1){
                if(j==0){
                    std::cout<<" └";
                }else if(j==width-1){
                    std::cout<<"┘ ";
                }else{
                    std::cout<<"──";
                }
            }else{
                if(j==0){
                    std::cout<<" │";
                }else if(j==width-1){
                    std::cout<<"│ ";
                }else{
                    std::cout<<"  ";
                }
            }
        }
    }
    tc::move_to(x,utils::b2c(y)+(width*2-title.length())/2);
    std::cout<<title<<std::flush;
}

void draw::tetromino(mino::Tetromino &t, int x, int y)
{
    for(int i= 0;i<t.size();i++){
        for(int j = 0;j<t.size();j++){
            tc::move_to(x+i,utils::b2c(y+j));
            if(t[i][j]==0){
                tc::reset_color();
            }else{
                tc::set_back_color((int)mino::getMinoColor(t[i][j]));
            }
            std::cout<<"  ";
        }
    }
}
