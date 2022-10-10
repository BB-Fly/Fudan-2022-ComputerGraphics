# Fudan-2022-ComputerGraphics
笔者本科阶段计算机图形学代码实践

目前有如下内容：

## 画布 Canvas
项目基础，所有算法将基于此展开。
``` C++
Canvas();                                           // 创建空白画布
void SetPixel(Point p, Color c);                    // 将某坐标处的颜色设为c
void Draw();                                        // 打印画布内容
void Clear();                                       // 清空画布
void DDALine(Point p1, Point p2, Color c)           // 数值微分分析法画直线
void MPLine(Point p1, Point p2, Color c)            // 中点画线法画直线
void BLine(Point p1, Point p2, Color c)             // Bresenham法画直线


```



持续更新中……