#include "draw.h"
#include "terminal.h"

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

// 每块由两列组成,如第十块位于19列
inline int block2col(int bindex){
    return bindex*2-1;
}

void draw::window(int x, int y, int width, int height, std::string title)
{
    for(int i = 0;i<height;i++){
        for(int j = 0;j<width;j++){
            tc::move_to(x+i,block2col(y+j));
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
    tc::move_to(x,block2col(y)+(width*2-title.length())/2);
    std::cout<<title<<std::flush;
}