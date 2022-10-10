#include"Canvas.h"

void test_canvas(){
    printf("test canvas: draw a line\n");
    Canvas c;
    for(int i=0;i<Canvas::width;++i)
        c.SetPixel(i,i,Color::Black);
    c.Draw();
}

void test_Line(){
    printf("test Line: draw a line\n");
    Canvas c;
    c.DDALine({1,3},{27,19},Color::Black);
    c.MPLine({1,6},{27,22},Color::Yellow);
    c.BLine({1,9},{27,25},Color::Blue);
    c.Draw();
}