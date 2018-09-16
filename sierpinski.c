#include "ssg.h"

// A basic point type
typedef struct {
    int x;
    int y;
} Point;

// Draw a triangle by drawing three lines in black
void draw_triangle(Point p1, Point p2, Point p3) {
    draw_line(p1.x, p1.y, p2.x, p2.y, "black");
    draw_line(p2.x, p2.y, p3.x, p3.y, "black");
    draw_line(p3.x, p3.y, p1.x, p1.y, "black");
}

// Mid point of two points
Point mid_point(Point p1, Point p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;
    return mid;
}

void sierpinski(Point p1, Point p2, Point p3, int level) {
    if (level <= 0) { return; }
    draw_triangle(p1, p2, p3);
    sierpinski(p1, mid_point(p1, p2), mid_point(p1, p3), level - 1);
    sierpinski(p2, mid_point(p1, p2), mid_point(p2, p3), level - 1);
    sierpinski(p3, mid_point(p1, p3), mid_point(p2, p3), level - 1);
}

int main (int argc, char const *argv[])
{
    start_graphics(300, 300);
    Point p1 = { .x = 0, .y = 300 };
    Point p2 = { .x = 150, .y = 0 };
    Point p3 = { .x = 300, .y = 300 };
    sierpinski(p1, p2, p3, 5);
    write_graphics("sierpinski");
    return 0;
}