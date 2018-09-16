// ssg.h
// A super simple SVG generating single-header-file graphics library
// appropriate for use in an "intro to programming" course in C or C++
//
// Copyright 2018 David Kopec
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef ssg_include
#define ssg_include

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *contents = NULL;

static void contents_add(const char *format, ...) {
    char buffer[1000]; // temporary holder until we put into contents
    
    va_list args;
    va_start(args, format); // get arguments
    vsprintf(buffer, format, args); // print into buffer
    va_end(args);
    int length = strlen(buffer);
    if (contents != NULL) {
        contents = (char *) realloc(contents, strlen(contents) + length + 1); // extra 1 for terminating character
        strcat(contents, buffer);
    } else {
        contents = malloc(length + 1); // extra 1 for terminating character
        sprintf(contents, "%s", buffer);
    }
}

void start_graphics(int width, int height) {
    contents_add("<?xml version=\"1.0\" encoding=\"utf-8\"?>\n");
    contents_add("<svg version=\"1.1\" baseProfile=\"full\" width=\"%d\" height=\"%d\" xmlns=\"http://www.w3.org/2000/svg\">\n", width, height);
}

void draw_ellipse(int x, int y, int width, int height, const char *color) {
    contents_add("<ellipse cx=\"%d\" cy=\"%d\" rx=\"%d\" ry=\"%d\" fill=\"%s\" />\n", x, y, width / 2, height / 2, color);
}

void draw_rectangle(int x, int y, int width, int height, const char *color) {
    contents_add("<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"%s\" />\n", x, y, width, height, color);
}

void draw_line(int x1, int y1, int x2, int y2, const char *color) {
    contents_add("<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke=\"%s\" />\n", x1, y1, x2, y2, color);
}

void clear_graphics() {
    free(contents);
    contents = NULL;
}

void write_graphics(const char *name) {
    contents_add("</svg>\n");
    
    char title[256];
    sprintf(title, "%s.svg", name);
    FILE *svg_file;
    svg_file = fopen(title, "w");
    fprintf(svg_file, "%s", contents);
    fclose(svg_file);
    // cleanup
    clear_graphics();
}

#endif /* ssg_include */
