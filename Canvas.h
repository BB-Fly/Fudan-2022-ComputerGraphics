#ifndef GUARD_CANVAS_H
#define GUARD_CANVAS_H

#include<stdlib.h>
#include<cstring>
#include<stdio.h>

enum class Color:char {
    NoColor     = ' ',
    Black       = '*',
    White       = '#',
    Red         = '@',
    Blue        = '+',
    Yellow      = '='
};


class Canvas
{
public:
    static constexpr size_t length=30,width=30;
    Canvas(){memset(canvas,0,sizeof(canvas));}
    void SetPixel(size_t x, size_t y, Color c);
    void Draw();
    void Clear();
private:
    Color canvas[width][length];
    void draw_frame();
};

void Canvas::SetPixel(size_t x, size_t y, Color c){
    canvas[y][x] = c;
}

void Canvas::draw_frame(){
    printf("|");
    for(int j=0;j<length;++j)
    {
        printf("--");
    }
    printf("|\n");
}

void Canvas::Draw(){
    draw_frame();
    for(int i=width-1;i>=0;--i)
    {
        printf("|");
        for(int j=0;j<length;++j)
        {
            printf("%c ",canvas[i][j]);
        }
        printf("|\n");
    }
    draw_frame();
}

void Canvas::Clear(){
    memset(canvas,0,sizeof(canvas));
}

#endif // GUARD