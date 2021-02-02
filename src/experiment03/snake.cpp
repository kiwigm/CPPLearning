#include <iostream>
#include <string>
#include <time.h>

using namespace std;

//蛇类
class snake {
public:
    //蛇类构造函数
    snake(string this_name, int this_ages, string this_color, double this_weight);

    //修改小蛇的基本信息
    void alter(string this_name, int this_ages, string this_color, double this_weight);

    //小蛇移动
    void move();

    //小蛇究极进化
    void jinhua();

    //小蛇吃苹果
    int eat(int apple_position_x, int apple_position_y);

    //显示小蛇的基本信息
    void show();

    //显示小蛇位置
    void show_position();

private:
    string name;//名字
    int ages;//年龄
    string color;//花纹
    double weight;//体重
    int position_x;//水平位置
    int position_y;//竖直位置
    int apple_ans;//吃苹果总数
};


//蛇吃的苹果类
class apple {
public:
    //苹果构造函数
    apple();

    //显示苹果位置
    void show_apple_position();

    int position_x;//水平位置
    int position_y;//竖直位置
    bool exist;//苹果是否还存在
};

//苹果构造函数
apple::apple() {
    srand(unsigned(time(0)));
    position_x = rand() % 11;
    position_y = rand() % 11;
    exist = 1;
}

//显示苹果位置
void apple::show_apple_position() {
    cout << "当前苹果位置：" << position_x << " " << position_y << endl;
}

//修改小蛇的基本信息
void snake::alter(string this_name, int this_ages, string this_color, double this_weight) {
    name = this_name;
    ages = this_ages;
    color = this_color;
    weight = this_weight;
    show();
}


//蛇类构造函数
snake::snake(string this_name, int this_ages, string this_color, double this_weight) {
    name = this_name;
    ages = this_ages;
    color = this_color;
    weight = this_weight;
    position_x = 0;
    position_y = 0;
    apple_ans = 0;
}

//显示小蛇的基本信息
void snake::show() {
    cout << "*********************************" << endl;
    cout << "*   神奇小蛇的名字：" << name << " \t*" << endl;
    cout << "*   神奇小蛇的年龄：" << ages << "  \t*" << endl;
    cout << "*   神奇小蛇的花纹：" << color << " \t*" << endl;
    cout << "*   神奇小蛇的体重：" << weight << "  \t*" << endl;
    cout << "*   神奇小蛇的位置：" << position_x << " " << position_y << "  \t*" << endl;
    cout << "*********************************" << endl;
}

//显示小蛇位置
void snake::show_position() {
    cout << "当前神奇小蛇的位置：" << position_x << " " << position_y << endl;
}

//小蛇移动
void snake::move() {
    int a, b;
    cout << "请输入小蛇水平移动步数（正数代表向右）：";
    cin >> a;
    cout << "请输入小蛇垂直移动步数（正数代表向上）：";
    cin >> b;
    position_x = position_x + a;
    position_y = position_y + b;
    show_position();
}


//小蛇吃苹果
int snake::eat(int apple_position_x, int apple_position_y) {
    if (apple_position_x == position_x && apple_position_y == position_y) {
        apple_ans++;
        weight++;
        cout << "小蛇吃了一个苹果" << endl;
        cout << "小蛇一共吃了" << apple_ans << "个苹果" << endl;
        cout << "小蛇体重+1" << endl;
        return 1;
    } else {
        cout << "这里没苹果，你吃啥？" << endl;
        return -1;
    }
}


//小蛇究极进化
void snake::jinhua() {
    if (apple_ans >= 2) {
        cout << "小蛇顺利进化！" << endl;
        name = "五爪金龙";
        ages = 99;
        color = "金色鳞片";
        weight = 99;
        show();
    } else {
        cout << "小蛇还没吃苹果呢！" << endl;
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);
    cout << "****************************" << endl;
    cout << "***欢迎来到贪吃的神奇小蛇***" << endl;
    cout << "***1.显示小蛇的基本信息  ***" << endl;
    cout << "***2.修改小蛇的基本信息  ***" << endl;
    cout << "***3.小蛇移动            ***" << endl;
    cout << "***4.小蛇吃苹果          ***" << endl;
    cout << "***5.小蛇究极进化        ***" << endl;
    cout << "***6.退出神奇的小蛇      ***" << endl;
    cout << "****************************\n" << endl;
    string name;
    int ages;
    string color;
    double weight;
    cout << "请输入神奇小蛇的名字：" << endl;
    cin >> name;
    cout << "请输入神奇小蛇的年龄：" << endl;
    cin >> ages;
    cout << "请输入神奇小蛇的花纹：" << endl;
    cin >> color;
    cout << "请输入神奇小蛇的体重：" << endl;
    cin >> weight;
    snake new_snake(name, ages, color, weight);
    cout << "\n***新的神奇小蛇诞生了***" << endl;
    new_snake.show();
    apple *new_apple = new apple();
    int flag;
    while (true)
    {
        if (new_apple->exist == 0)
        {
            delete new_apple;
            new_apple = new apple();
        }
        cout << "\n请选择功能：";
        cin >> flag;
        if (flag == 1)
        {
            //显示小蛇的基本信息
            new_snake.show();
        }
        else if (flag == 2)
        {
            //修改小蛇的基本信息
            cout << "请输入神奇小蛇的名字：" << endl;
            cin >> name;
            cout << "请输入神奇小蛇的年龄：" << endl;
            cin >> ages;
            cout << "请输入神奇小蛇的花纹：" << endl;
            cin >> color;
            cout << "请输入神奇小蛇的体重：" << endl;
            cin >> weight;
            new_snake.alter(name, ages, color, weight);
        }
        else if (flag == 3)
        {
            //小蛇移动
            new_apple->show_apple_position();
            new_snake.move();
        }
        else if (flag == 4)
        {
            //小蛇吃苹果
            int judge = new_snake.eat(new_apple->position_x, new_apple->position_y);
            if (judge == 1)
            {
                //若苹果被吃了
                new_apple->exist = 0;
            }
        }
        else if (flag == 5)
        {
            //小蛇究极进化
            new_snake.jinhua();
        }
        else if (flag == 6)
        {
            //退出
            break;
        }
    }
    return 0;
}