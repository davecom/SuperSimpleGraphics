# SuperSimpleGraphics
This is an extremely simplistic SVG generating single header file C library appropriate for "intro to programming" classes in C or C++. Using it is as simple as dropping "ssg.h" into your project and then `#include "ssg.h"` in your source file. Right now it is a hack done in a couple hours with two example programs as a proof of concept, so there's not yet a lot of error checking or features.

## Documentation
There are only five functions for now:

```C
void start_graphics(int width, int height)
```
Starts the creation of a new SVG file with a canvas of `width` and `height` dimensions.

```C
void draw_ellipse(int x, int y, int width, int height, const char *color)
```
Draws an ellipse.

```C
void draw_rectangle(int x, int y, int width, int height, const char *color)
```
Draws a rectangle.

```C
void draw_line(int x1, int y1, int x2, int y2, const char *color)
```
Draws a line.

```C
void write_graphics(const char *name)
```
Writes an svg file with the filename `name` and the `.svg` extension. Frees any used memory and closes the file.

## Examples
So far there are two simple examples included in this directory:
- `france_flag.c` draws the French flag. 

![French Flag](flag.svg)

- `sierpinski.c` draws sierpinski triangles 

![Sierpinski Triangles](sierpinski.svg)

Running them is as simple as:
```bash
gcc france_flag.c
./a.out
```
Then a `.svg` file will be generated in the same directory. They have been tested with `clang` on macOS, `gcc` on GNU/Linux, and Visual C++ on Windows.

## License
Licensed under the MIT license.
