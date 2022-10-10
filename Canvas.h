#ifndef GUARD_CANVAS_H
#define GUARD_CANVAS_H

#include<stdlib.h>
#include<cstring>
#include<stdio.h>
#include<initializer_list>
#include<algorithm>

enum class Color:char {
    NoColor     = ' ',
    Black       = '*',
    White       = '#',
    Red         = '@',
    Blue        = '+',
    Yellow      = '='
};

struct  Point
{
    int x,y;
    Point():x(0),y(0){}
    Point(int _x,int _y):x(_x),y(_y){}
    Point(std::initializer_list<int> l)
    {
        auto it = l.begin();
        x = *it++;
        y = *it++;
    }

};


class Canvas
{
public:
    static constexpr size_t length=30,width=30;
    Canvas(){memset(canvas,0,sizeof(canvas));}
    void SetPixel(int x, int y, Color c);
    void SetPixel(Point p, Color c);
    void Draw();
    void Clear();
    void DDALine(Point p1, Point p2, Color c);
    void DDALine(int x1, int y1, int x2, int y2, Color c);
    void MPLine(Point p1, Point p2, Color c);
    void MPLine(int x1, int y1, int x2, int y2, Color c);
    void BLine(Point p1, Point p2, Color c);
    void BLine(int x1, int y1, int x2, int y2, Color c);
private:
    Color canvas[width][length];
    void draw_frame();
};

void Canvas::SetPixel(int x, int y, Color c){
    canvas[y][x] = c;
}

void Canvas::SetPixel(Point p, Color c){
    canvas[p.y][p.x] = c;
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

void Canvas::DDALine(Point p1, Point p2, Color c){
    DDALine(p1.x, p1.y, p2.x, p2.y, c);
}

void Canvas::DDALine(int x1, int y1, int x2, int y2, Color c){
    double dx,dy,x,y,e;
    dx = x2-x1;
    dy = y2-y1;
    e = std::max(abs(dx),abs(dy));
    dx/=e;
    dy/=e;
    x = x1;
    y = y1;
    for(int i=1; i<=e; ++i){
        SetPixel(x+0.5, y+0.5, c);
        x+=dx;
        y+=dy;
    }
}

void Canvas::MPLine(Point p1, Point p2, Color c){
    MPLine(p1.x, p1.y, p2.x, p2.y, c);
}

void Canvas::MPLine(int x1, int y1, int x2, int y2, Color c){
    int a,b,delta1,delta2,d,x,y;
    a = y1-y2;
    b = x2-x1;
    d = 2*a+b;
    delta1 = 2*a;
    delta2 = 2*(a+b);
    x = x1;
    y = y1;
    SetPixel(x,y,c);
    while(x<x2){
        if(d<0){
            x++;
            y++;
            d += delta2;
        }else{
            x++;
            d += delta1;
        }
        SetPixel(x,y,c);
    }
}

void Canvas::BLine(Point p1, Point p2, Color c){
    BLine(p1.x, p1.y, p2.x, p2.y, c);
}

void Canvas::BLine(int x1, int y1, int x2, int y2, Color c){
    int x,y,dx,dy,p;
    x = x1;
    y = y1;
    dx = x2-x1;
    dy = y2-y1;
    p = 2*dy-dx;
    for(;x<=x2;++x){
        SetPixel(x,y,c);
        if(p>=0){
            y++;
            p+=2*(dy-dx);
        }else{
            p+=2*dy;
        }
    }
}



#endif // GUARD