#ifndef DEMO3_SHAPE_H
#define DEMO3_SHAPE_H


#include <iostream>

using namespace std;

class demo03Shape {
protected:
    int width;
    int height;

public:
    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    // 接口
    virtual int getArea() = 0;

};



class demo03Rectangle : public demo03Shape {
public:

    int getArea() {
        return width * height;
    }
};

class demo03Triangle : public demo03Shape {
public:

    int getArea() {
        return (width * height / 2);
    }
};

void demo03InterfaceTest();


#endif //DEMO3_SHAPE_H
