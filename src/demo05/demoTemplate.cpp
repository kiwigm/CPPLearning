#include "demoTemplate.h"

using namespace std;

template<typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}

void demo05TemplateTest(){
    int a = 1;
    int b = 2;
    cout << "Max is <int>:" << Max(a,b) << endl;

    char c = 'A';
    char d = 'B';
    cout << "Max is <char>:" << Max(c,d) << endl;

}

int main(){
    demo05TemplateTest();
    return 0;
}