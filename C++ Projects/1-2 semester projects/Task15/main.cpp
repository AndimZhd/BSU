#include "DrawingPatternInterface.h"

void client(Shape* shape, double x, double y){
    shape->Draw(x, y);
}

int main() {
    GS1Drawing gs1;
    GS2Drawing gs2;
    Rectangle rectangle(2, 2, &gs1);
    Circle circle(3, &gs2);
    client(&rectangle, 100.32, 100.43);
    client(&circle, 100, 100);
    return 0;
}
