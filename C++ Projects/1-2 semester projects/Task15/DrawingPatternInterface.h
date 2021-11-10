#ifndef TASK15_DRAWINGPATTERNINTERFACE_H
#define TASK15_DRAWINGPATTERNINTERFACE_H

#include "DrawingPatternRealisation.h"
#include <iomanip>

class Shape {
private:
    Drawing *_drawing;
protected:
    Shape(Drawing *dr);

    void DrawLine(double, double, double, double);

    void DrawCircle(double, double, double);

public:

    virtual void Draw(double x, double y) = 0;
};

class Rectangle : public Shape {
    double _length;
    double _width;
public:
    Rectangle(double a, double b, Drawing *drawing);

    void Draw(double, double) override;
};

class Circle : public Shape {
    double _radius;
public:
    Circle(double r, Drawing *drawing);

    void Draw(double x, double y) override;
};

#endif //TASK15_DRAWINGPATTERNINTERFACE_H
