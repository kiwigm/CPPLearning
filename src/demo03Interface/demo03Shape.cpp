#include "demo03Shape.h"

void demo03InterfaceTest(){
    demo03Rectangle r;
    r.setHeight(1);
    r.setWidth(2);
    cout << "Total Rectangle area: " << r.getArea() << endl;

    demo03Triangle t;
    t.setWidth(5);
    t.setHeight(7);
    cout << "Total Rectangle area: " << t.getArea() << endl;

}

int main(){
    demo03InterfaceTest();
    return 0;
}