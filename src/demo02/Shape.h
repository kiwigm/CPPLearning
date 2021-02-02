#ifndef DEMO2_SHAPE_H
#define DEMO2_SHAPE_H


#include <iostream>

using namespace std;

class Shape {
protected:
    int width;
    int height;

public:
    Shape(int width = 0, int height = 0) {
        this->width = width;
        this->height = height;
    }

    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    // 编译时，动态链接
    virtual int getArea()
    {
        cout << "Parent class area :" <<endl;
        return width * height;
    }

};

class PaintCost {
public:
    int getCost(int area) {
        return 70 * area;
    }
};

class Rectangle : public Shape, public PaintCost {
public:
    Rectangle(int width = 0, int height = 0) : Shape(width, height) {}

    int getArea() {
        cout << "Rectangle class area :" << endl;
        return width * height;
    }
};

class Triangle : public Shape, public PaintCost {
public:
    Triangle(int width = 0, int height = 0) : Shape(width, height) {}

    int getArea() {
        cout << "Triangle class area :" << endl;
        return (width * height / 2);
    }
};

void demo02ShapeTest();
void demo02ShapeTest1();

#endif //DEMO2_SHAPE_H
