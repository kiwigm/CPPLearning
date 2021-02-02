
#include<iostream>
#include<string>

using namespace std;

class beast {
public:
    beast(string n, string s, int a, double h, double we, string ha = "");

    void bellow();//吼叫
    void show();//显示信息
    void eat();//吃
    ~beast();

protected:
    string name;//姓名
    string sex;//性别
    int age;//年龄
    double high;//身高
    double weight;//体重
    string habit;//习性
};

beast::beast(string n, string s, int a, double h, double we, string ha) {
    name = n;
    sex = s;
    age = a;
    habit = ha;
    high = h;
    weight = we;
    cout << "新的野兽诞生了！" << endl;
}

beast::~beast() {
    cout << "这只野兽被析构了..." << endl;
}

void beast::bellow() {
    cout << "野兽发出了叫声" << endl;
}

void beast::eat() {
    cout << "这只野兽进食了" << endl;
}

void beast::show() {
    cout << "******** 野兽信息 ********" << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << "性" << endl;
    cout << "年龄：" << age << endl;
    cout << "身高：" << high << " cm" << endl;
    cout << "体重：" << weight << " kg" << endl;
    cout << "习性：" << habit << endl;
    cout << "**************************" << endl;
}

//狼类
class wolf : public beast {
public:
    wolf(string n, string s, int a, double h, double we, string ha, string co);

    void bellow();//吼叫
    void show();//显示信息
    void tour();//巡视
    void eat();//吃
    ~wolf();

private:
    string grade;//保护等级
    string hair;//毛发
    string color;//颜色
};

wolf::wolf(string n, string s, int a, double h, double we, string ha, string co) : beast(n, s, a, h, we) {
    grade = "国家二级保护动物";
    hair = ha;
    color = co;
    habit = "群居动物";
    cout << "新的狼诞生了！" << endl;
}

wolf::~wolf() {
    cout << "这条狼被析构了..." << endl;
}

void wolf::bellow() {
    cout << "狼'" << name << "'在月圆之夜于悬崖尽头发出了吼叫：┗|｀O′|┛ 嗷~~" << endl;
}

void wolf::tour() {
    cout << "狼'" << name << "'威风凛凛地巡视了自己的领地" << endl;
}

void wolf::eat() {
    cout << "狼'" << name << "'迅捷地扑倒了一只小白兔，饱饱地美餐了一顿" << endl;
    cout << "狼'" << name << "'体重+5kg" << endl;
    weight = weight + 5;
    hair = hair + "，毛发上染了血色";
}

//显示功能表1
void show1() {
    cout << "\n.........................." << endl;
    cout << "...     野兽模拟器     ..." << endl;
    cout << "... 1.显示野兽信息     ..." << endl;
    cout << "... 2.进食             ..." << endl;
    cout << "... 3.吼叫             ..." << endl;
    cout << "... 4.退出             ..." << endl;
    cout << ".........................." << endl;
}

//显示功能表2
void show2() {
    cout << "\n.........................." << endl;
    cout << "...     狼类模拟器     ..." << endl;
    cout << "... 1.显示狼类信息     ..." << endl;
    cout << "... 2.进食             ..." << endl;
    cout << "... 3.吼叫             ..." << endl;
    cout << "... 4.巡视领地         ..." << endl;
    cout << "... 5.退出             ..." << endl;
    cout << ".........................." << endl;
}

void wolf::show() {
    cout << "\n******** 狼类信息 ********" << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << "性" << endl;
    cout << "年龄：" << age << endl;
    cout << "身高：" << high << " cm" << endl;
    cout << "体重：" << weight << " kg" << endl;
    cout << "习性：" << habit << endl;
    cout << "等级：" << grade << endl;
    cout << "毛发：" << hair << endl;
    cout << "颜色：" << color << endl;
    cout << "**************************" << endl;
}

//显示主功能表
void show() {
    cout << "**************************" << endl;
    cout << "***     动物模拟器     ***" << endl;
    cout << "*** 1.进入野兽模拟器   ***" << endl;
    cout << "*** 2.进入狼类模拟器   ***" << endl;
    cout << "*** 3.退出动物模拟器   ***" << endl;
    cout << "**************************" << endl;
}

int main() {
    string name;//姓名
    string sex;//性别
    int age;//年龄
    double high;//身高
    double weight;//体重
    string habit;//习性
    string grade;//保护等级
    string hair;//毛发
    string color;//颜色

    int flag;
    while (true) {
        show();
        cout << "\n请选择功能：";
        cin >> flag;
        if (flag == 1) {
            //进入野兽模拟器
            cout << "***    输入野兽信息    ***" << endl;
            cout << "请输入姓名：";
            cin >> name;
            cout << "请输入性别：";
            cin >> sex;
            cout << "请输入年龄：";
            cin >> age;
            cout << "请输入身高：";
            cin >> high;
            cout << "请输入体重：";
            cin >> weight;
            cout << "请输入习性：";
            cin >> habit;
            beast new_beast(name, sex, age, high, weight, habit);

            int flag1;
            show1();
            while (true) {
                cout << "\n请选择具体功能：";
                cin >> flag1;
                if (flag1 == 1) {
                    new_beast.show();
                } else if (flag1 == 2) {
                    new_beast.eat();
                } else if (flag1 == 3) {
                    new_beast.bellow();
                } else if (flag1 == 4) {
                    //退出
                    cout << "已退出" << endl;
                    break;
                }
            }
        } else if (flag == 2) {
            //进入狼类模拟器
            cout << "***    输入狼类信息    ***" << endl;
            cout << "请输入姓名：";
            cin >> name;
            cout << "请输入性别：";
            cin >> sex;
            cout << "请输入年龄：";
            cin >> age;
            cout << "请输入身高：";
            cin >> high;
            cout << "请输入体重：";
            cin >> weight;
            cout << "请输入毛发：";
            cin >> hair;
            cout << "请输入颜色：";
            cin >> color;
            wolf new_wolf(name, sex, age, high, weight, hair, color);

            int flag1;
            show2();
            while (true) {
                cout << "\n请选择具体功能：";
                cin >> flag1;
                if (flag1 == 1) {
                    new_wolf.show();
                } else if (flag1 == 2) {
                    new_wolf.eat();
                } else if (flag1 == 3) {
                    new_wolf.bellow();
                } else if (flag1 == 4) {
                    new_wolf.tour();
                } else if (flag1 == 5) {
                    //退出
                    cout << "已退出" << endl;
                    break;
                }
            }
        } else if (flag == 3) {
            //退出
            cout << "成功退出模拟器！" << endl;
            break;
        }
    }
    return 0;
}
