#include "DrawingPatternInterface.h"

Shape::Shape(Drawing *dr) : _drawing(dr) {}

void Shape::DrawLine(double x1, double y1, double x2, double y2) {
    _drawing->DrawLine(x1, y1, x2, y2);
}

void Shape::DrawCircle(double x, double y, double r) {
    _drawing->DrawCircle(x, y, r);
}

Rectangle::Rectangle(double a, double b, Drawing *drawing) : Shape(drawing), _length(a), _width(b) {}

void Rectangle::Draw(double x, double y) {
    std::cout << "Drawing a rectangle with length = " << _length << " and width = " << _width << ". Center " <<
              "coordinates: " << std::setprecision(2) << std::fixed << x << " " << y << std::endl;
    DrawLine(x - _length / 2, y - _width / 2, x + _length / 2, y - _width / 2);
    DrawLine(x + _length / 2, y - _width / 2, x + _length / 2, y + _width / 2);
    DrawLine(x + _length / 2, y + _width / 2, x - _length / 2, y + _width / 2);
    DrawLine(x - _length / 2, y + _width / 2, x - _length / 2, y + _width / 2);
}

Circle::Circle(double r, Drawing *drawing) : Shape(drawing), _radius(r) {}

void Circle::Draw(double x, double y) {
    std::cout << "Drawing a circle with radius = " << _radius << ". Center coordinates: " << std::setprecision(2)
              << std::fixed << x << " " << y << std::endl;
    DrawCircle(x, y, _radius);
}