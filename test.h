#include"Canvas.h"

void test_canvas(){
    printf("test canvas: draw a line\n");
    Canvas c;
    for(int i=0;i<Canvas::width;++i)
        c.SetPixel(i,i,Color::Black);
    c.Draw();
}