#ifndef TASK15_DRAWINGPATTERNREALISATION_H
#define TASK15_DRAWINGPATTERNREALISATION_H

#include <iostream>

class Point {
private:
    double _x;
    double _y;
public:
    Point(double x, double y);
};

class GS1 {
public:
    static void draw_line(double x1, double y1, double x2, double y2);

    static void draw_circle(double x1, double y1, double r);
};

class GS2 {
public:
    static void draw_line(Point p1, Point p2);

    static void draw_circle(Point p1, double r);
};


class Drawing {
public:
    virtual void DrawLine(double x1, double y1, double x2, double y2) = 0;

    virtual void DrawCircle(double x1, double y1, double r) = 0;
};

class GS1Drawing : public Drawing {
public:
    void DrawLine(double x1, double y1, double x2, double y2) override;

    void DrawCircle(double x1, double y1, double r) override;
};

class GS2Drawing : public Drawing {
public:
    void DrawLine(double x1, double y1, double x2, double y2) override;

    void DrawCircle(double x1, double y1, double r) override;
};


#endif //TASK15_DRAWINGPATTERNREALISATION_H
