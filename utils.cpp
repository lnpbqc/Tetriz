#include "utils.h"
using namespace std;
int utils::fps()
{
    static auto start_record_frame = std::chrono::steady_clock::now();
    static int frame_count = 0;
    static int fps = 0;

    auto end_record_frame = std::chrono::steady_clock::now();
    frame_count++;
    if(end_record_frame-start_record_frame>=1s){
        fps = frame_count;
        frame_count=0;
        start_record_frame = end_record_frame;
    }
    return fps;
}