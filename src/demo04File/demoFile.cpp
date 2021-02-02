#include "demoFile.h"
#include <exception>

using namespace std;

void demo04FileTest() {
    char data[100];

    fstream f;
    f.open("./test.txt", ios::out);

    // 向文件写数据
    cout << "Writing to the file..." << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);
    // 向文件写入用户输入的数据
    f << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();
    // 再次向文件写入用户输入的数据
    f << data << endl;
    // 关闭打开的文件
    f.close();


    f.open("./test.txt");

    cout << "Reading from the file" << endl;
    f >> data;
    // 在屏幕上写入数据
    cout << data << endl;

    // 再次从文件读取数据，并显示它
    f >> data;
    cout << data << endl;
    f.close();

}

int main(){
    demo04FileTest();
    return 0;
}