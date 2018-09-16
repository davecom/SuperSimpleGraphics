#include "ssg.h"

int main (int argc, char const *argv[])
{
    start_graphics(300, 200);
    draw_rectangle(0, 0, 100, 200, "blue");
    draw_rectangle(100, 0, 100, 200, "white");
    draw_rectangle(200, 0, 100, 200, "red");
    write_graphics("flag");
    return 0;
}