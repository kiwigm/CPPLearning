#include "Shape.h"

void demo02ShapeTest() {
    Rectangle r;
    r.setHeight(1);
    r.setWidth(2);
    int cost = r.getCost(r.getArea());
    cout << "Rectangle cost:" << cost << endl;


}

void demo02ShapeTest1() {
    // 多态
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri = Triangle(10, 5);

    shape = &rec;
    shape->getArea();

    shape = &tri;
    shape->getArea();
}