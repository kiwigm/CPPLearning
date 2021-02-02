#ifndef DEMO2_ANIMAL_H
#define DEMO2_ANIMAL_H

#include <iostream>
using namespace std;

class Animal{
public:
    void eat(){
        cout << "Animal eat..." << endl;
    }
    void sleep(){
        cout << "Animal sleep..." << endl;
    }
};

class Dog : public Animal{
public:
    // 重写
    void eat(){
        cout << "Dog eat..." << endl;
    }

    // 重载
    void eat(int a){
        cout << "Dog eat " << a << endl;
    }

    void bark(){
        cout << "Dog bark..." << endl;
    }
};

void demo02AnimalTest();

#endif //DEMO2_ANIMAL_H
