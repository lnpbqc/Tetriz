#include <iostream>
#include <thread>
#include "terminal.h"
using namespace std;
int main(){
    int i=0;
    tc::hide_cursor();
    while(true){
        tc::reset_color();
        tc::clean_screen();
        tc::move_to(i++,10);
        tc::set_back_color(15);
        cout<<"  "<<flush;
        this_thread::sleep_for(1s);
        if(i==10)break;
    }
    tc::show_cursor();
    return 0;
}