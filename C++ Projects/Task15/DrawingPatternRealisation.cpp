#include "DrawingPatternRealisation.h"

Point::Point(double x, double y) : _x(x), _y(y) {}

void GS1::draw_line(double x1, double y1, double x2, double y2) {
    std::cout << "Drawing a line using GS1..." << std::endl;
}

void GS1::draw_circle(double x1, double y1, double r) {
    std::cout << "Drawing a circle using GS1..." << std::endl;
}

void GS2::draw_line(Point p1, Point p2) {
    std::cout << "Drawing a line using GS2..." << std::endl;
}

void GS2::draw_circle(Point p1, double r) {
    std::cout << "Drawing a circle using GS2..." << std::endl;
}

void GS1Drawing::DrawLine(double x1, double y1, double x2, double y2) {
    GS1::draw_line(x1, y1, x2, y2);
}

void GS1Drawing::DrawCircle(double x1, double y1, double r) {
    GS1::draw_circle(x1, y1, r);
}

void GS2Drawing::DrawLine(double x1, double y1, double x2, double y2) {
    GS2::draw_line(Point(x1, y1), Point(x2, y2));
}

void GS2Drawing::DrawCircle(double x1, double y1, double r) {
    GS2::draw_circle(Point(x1, y1), r);
}