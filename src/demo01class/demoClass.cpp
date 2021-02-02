#include "demoClass.h"
#include <iostream>

using namespace std;

class Box {
private:
    double length;   // 盒子的长度
    double breadth;  // 盒子的宽度


public:
    static int objectCount;
    double height;   // 盒子的高度
    int *ptr = nullptr;

    Box() {
        objectCount++;
    }

    // 构造函数
    Box(double length, double breadth, double height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
        objectCount++;
    }

    // 析构函数，对象删除时执行，用于释放内存等操作
    ~Box() {
        cout << "Delete..." << endl;
    }

    // 拷贝构造函数
    Box(const Box &obj) {
        // 从同类其他对象中的 ptr 给本实例赋值
        cout << "copy ptr" << endl;
        ptr = new int;
        *ptr = *obj.ptr;
        objectCount++;
    }

    // 友元函数和拷贝构造函数共存，使用引用传参，避免出现创建副本的情况
    friend void showInfo(Box &box);

    double getVolume();

    // 静态成员函数
    static int getCount() {
        return objectCount;
    }

    void set(double length, double breadth, double height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;

    }

    double getLength() const {
        return length;
    }

    void setLength(double length) {
        this->length = length;
    }

    double getBreadth() const {
        return breadth;
    }

    void setBreadth(double breadth) {
        this->breadth = breadth;
    }

    double getHeight() const {
        return height;
    }

    void setHeight(double height) {
        this->height = height;
    }
};

// 成员函数在外定义
double Box::getVolume() {
    return length * breadth * height;
}

// 友元函数
void showInfo(Box &box) {
    cout << box.height << endl;
}

// 初始化类 Box 的静态成员
int Box::objectCount = 0;

void demo01ClassTest() {
    cout << "Hello C++ 中文" << endl;

    Box box1{1, 2, 3};
    // 输出总数
    cout << "Total objects: " << Box::objectCount << endl;

    Box box2;
    cout << "Total objects: " << Box::objectCount << endl;

    Box *box3 = new Box(3, 3, 3);
    cout << "Total objects: " << Box::objectCount << endl;

    int a = 10;
    box3->ptr = &a;
    Box box4 = Box(*box3);
    cout << "Total objects: " << Box::objectCount << endl;

    box1.set(1, 1, 1);
    box2.set(2, 2, 2);

    cout << "box1 length:" << box1.getLength() << "\t";
    cout << "V:" << box1.getVolume() << endl;

    cout << "box2 length:" << box2.getLength() << "\t";
    cout << "V:" << box2.getVolume() << endl;

    cout << "box3 length:" << box3->getLength() << "\t";
    cout << "V:" << box3->getVolume() << endl;

    cout << "box4 ptr:" << *box4.ptr << "\t";
    cout << "V:" << box4.getVolume() << endl;

    // 友元函数可以访问类内成员
    showInfo(box1);
    cout << "Total objects: " << Box::getCount() << endl;

}

int main(){
    demo01ClassTest();
    return 0;
}