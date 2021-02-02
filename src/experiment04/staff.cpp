#include <iostream>
#include <string>

using namespace std;

class datetime {
public:
    datetime() {};

    datetime(int y = 1900, int m = 1, int d = 1) {
        years = y;
        month = m;
        day = d;
    }

    ~datetime();

    datetime(const datetime &bir);

    void show();

private:
    int years;
    int month;
    int day;
};

//析构
datetime::~datetime() {
    cout << "datetime被析构" << endl;
}

//复制构造函数
datetime::datetime(const datetime &bir) {
    years = bir.years;
    month = bir.month;
    day = bir.day;
    cout << "datetime被复制" << endl;
}

void datetime::show() {
    cout << "出生日期：" << years << "年" << month << "月" << day << "日" << endl;
}

class staff{
public:
    staff(int num = 0, string n = "未知", string s = "未知", datetime bir = datetime(1900, 1, 1), string ID = "00000"):birthday(bir)
    {
        number = num;
        name = n;
        sex = s;
        IDCard = ID;
    }
    void show();
private:
    int number;
    string name;
    string sex;
    datetime birthday;
    string IDCard;

};


void staff::show() {
    cout << "*************************" << endl;
    cout << "编号：" << number << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    birthday.show();
    cout << "身份证号：" << IDCard << endl;
}

int main() {

    cout << "****************************************" << endl;
    cout << "***       欢迎来到人员录入系统       ***" << endl;
    cout << "***1.显示所有录入人员信息            ***" << endl;
    cout << "***2.修改某人员信息                  ***" << endl;
    cout << "***3.退出程序                        ***" << endl;
    cout << "****************************************\n" << endl;

    staff *sta[10];
    int ans;
    cout << "请输入待录入人员数：";
    cin>>ans;
    int number;
    string name;
    string sex;
    int years;
    int month;
    int day;
    string IDCard;
    for (int i = 0; i < ans; i++)
    {
        cout << "***   录入人员信息   ***" << endl;
        cout << "请输入人员编号：";
        cin >> number;
        cout << "请输入人员姓名：";
        cin >> name;
        cout << "请输入人员性别：";
        cin >> sex;
        cout << "请输入人员出生日期：";
        cin >> years >> month >> day;
        datetime MY_datetime(years, month, day);
        cout << "请输入人员身份证号：";
        cin >> IDCard;
        sta[i] = new staff(number, name, sex, MY_datetime, IDCard);
    }
    int flag;
    while (true)
    {
        cout << "\n请选择功能：";
        cin >> flag;
        if (flag == 1)
        {
            for (int i = 0; i < ans; i++)
            {
                sta[i]->show();
            }
            cout << endl;
        }
        else if (flag == 2)
        {
            int i;
            cout << "请输入你要修改第几个人的信息：" << endl;
            cin >> i;
            i--;
            cout << "***   修改人员信息   ***" << endl;
            cout << "请输入人员编号：";
            cin >> number;
            cout << "请输入人员姓名：";
            cin >> name;
            cout << "请输入人员性别：";
            cin >> sex;
            cout << "请输入人员出生日期：";
            cin >> years >> month >> day;
            datetime MY_datetime(years, month, day);
            cout << "请输入人员身份证号：";
            cin >> IDCard;
            sta[i] = new staff(number, name, sex, MY_datetime, IDCard);
        }
        else if (flag == 3)
        {
            //退出
            cout << "成功退出！" << endl;
            break;
        }
    }

    return 0;
}