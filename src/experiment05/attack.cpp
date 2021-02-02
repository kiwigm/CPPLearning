#include<iostream>
#include<time.h>
#include<algorithm>
#include<string>

using namespace std;

class player;

void attack(player *peo[10]);

// 头盔类
class helm {
private:
    int value_of_defense; // 防御力
    int durability; // 耐久次数
    int gem; // 宝石
public:
    friend player;

    friend void attack(player *peo[10]);

    helm() {
        value_of_defense = 0;
        durability = 0;
        gem = 0;
    }

    helm(int v, int d, int g);

    void show();
};

// 护甲类
class armor {
private:
    int value_of_defense; // 防御力
    int durability; // 耐久
    int gem; // 宝石
public:
    friend player;

    friend void attack(player *peo[10]);

    armor() {
        value_of_defense = 0;
        durability = 0;
        gem = 0;
    }

    armor(int v, int d, int g);

    void show();
};


class player {
private:
    string name; // 姓名
    int ages; // 年龄
    string sex; // 性别
    int blood; // 血量
    int combat; // 格斗
    helm *my_helm; // 头盔
    armor *my_armor; // 护甲
    static int count; // 人员总数

public:
    friend void attack(player *peo[10]);

    player() {};

    player(string n, int a, string s, int co);

    void show(); // 显示成员信息
    static void show_count(); // 显示人员总数
    void equip_helm();

    void equip_armor();

};


int player::count = 0;

// 装备护甲
void player::equip_armor() {
    int value_of_defense;
    int durability;
    int gem;
    cout << "请输入护甲防御力：";
    cin >> value_of_defense;
    cout << "护甲耐久次数：";
    cin >> durability;
    cout << "护甲宝石等级：";
    cin >> gem;

    my_armor = new armor(value_of_defense, durability, gem);

}

void player::equip_helm() {
    int value_of_defense;
    int durability;
    int gem;
    cout << "请输入头盔防御力：";
    cin >> value_of_defense;
    cout << "头盔耐久次数：";
    cin >> durability;
    cout << "头盔宝石等级：";
    cin >> gem;
    my_helm = new helm(value_of_defense, durability, gem);

}

void attack(player *peo[10]) {
    int p1, p2;
    cout << "请输入格斗两人的编号：";
    cin >> p1 >> p2;
    p1--;
    p2--;
    int temp;
    while (true) {
        temp = max(0, (peo[p1]->combat - peo[p2]->my_armor->value_of_defense - peo[p2]->my_helm->value_of_defense));
        peo[2]->blood = peo[p2]->blood - temp;
        cout << peo[p1]->name << "对" << peo[p2]->name << "造成了" << temp << "点伤害" << endl;
        peo[p2]->my_armor->durability--;
        peo[p2]->my_helm->durability--;
        if (peo[p2]->my_armor->durability == 0) {
            cout << "***" << peo[p2]->name << "的护甲损坏了" << "***" << endl;
            peo[p2]->my_armor->value_of_defense = 0;
        }
        if (peo[p2]->my_helm->durability == 0) {
            cout << "***" << peo[p2]->name << "的头盔损坏了" << "***" << endl;
            peo[p2]->my_helm->value_of_defense = 0;
        }
        if (peo[p2]->blood <= 0) {
            cout << "***" << peo[p1]->name << "战胜了" << peo[p2]->name << "***" << endl;
            break;
        }

        temp = max(0, (peo[p2]->combat - peo[p1]->my_armor->value_of_defense - peo[p1]->my_helm->durability));
        peo[p2]->blood = peo[p2]->blood - temp;
        cout << peo[p2]->name << "对" << peo[p1]->name << "造成了" << temp << "点伤害" << endl;
        peo[p1]->my_armor->durability--;
        peo[p1]->my_helm->durability--;
        if (peo[p1]->my_armor->durability == 0) {
            cout << "***" << peo[p1]->name << "的护甲损坏了" << "***" << endl;
            peo[p1]->my_armor->value_of_defense = 0;
        }
        if (peo[p1]->my_helm->durability == 0) {
            cout << "***" << peo[p1]->name << "的头盔损坏了" << "***" << endl;
            peo[p1]->my_helm->value_of_defense = 0;
        }
        if (peo[p1]->blood <= 0) {
            cout << "***" << peo[p2]->name << "战胜了" << peo[p1]->name << "***" << endl;
            break;
        }

    }

}

// 显示人员总数
void player::show_count() {
    cout << "当前格斗场人员总数：" << count << endl;
}

//初始化
player::player(string n, int a, string s, int co) {
    name = n;
    ages = a;;
    sex = s;
    blood = 200;
    combat = co;
    my_helm = new helm();
    my_armor = new armor();
    cout << "新的格斗者诞生了！" << endl;
    count++;
}

//显示成员信息
void player::show() {
    cout << "*************************" << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    cout << "年龄：" << ages << endl;
    cout << "血量槽：" << blood << endl;
    cout << "格斗力：" << combat << endl;
    if (my_helm != NULL) {
        my_helm->show();
    }
    if (my_armor != NULL) {
        my_armor->show();
    }
}

helm::helm(int v, int d, int g) {
    value_of_defense = v;
    durability = d;
    gem = g;
    cout << "宝石嵌入中..." << endl;
    cout << "头盔防御力+" << g * 10 << endl;
    value_of_defense = value_of_defense + g * 10;
    cout << "嵌入完成" << endl;
}

void helm::show() {
    cout << "头盔防御力：" << value_of_defense << endl;
    cout << "头盔耐久次数：" << durability << endl;
    cout << "头盔宝石等级：" << gem << endl;
}

armor::armor(int v, int d, int g) {
    value_of_defense = v;
    durability = d;
    gem = g;
    cout << "宝石嵌入中..." << endl;
    cout << "护甲防御力+" << g * 10 << endl;
    value_of_defense = value_of_defense + g * 10;
    cout << "嵌入完成" << endl;
}

void armor::show() {
    cout << "护甲防御力：" << value_of_defense << endl;
    cout << "护甲耐久次数：" << durability << endl;
    cout << "护甲宝石等级：" << gem << endl;
}

int main() {
    cout << "********************************" << endl;
    cout << "***      欢迎来到格斗场      ***" << endl;
    cout << "*** 1.显示格斗场成员信息     ***" << endl;
    cout << "*** 2.装备头盔               ***" << endl;
    cout << "*** 3.装备护甲               ***" << endl;
    cout << "*** 4.决斗                   ***" << endl;
    cout << "*** 5.退出格斗场             ***" << endl;
    cout << "********************************\n" << endl;

    player *peo[10];
    int ans;
    cout << "请输入待进驻格斗场的人员数：";
    cin >> ans;
    string name;//姓名
    int ages;//年龄
    string sex;//性别
    int combat;//格斗

    //输入信息
    for (int i = 0; i < ans; i++) {
        cout << "***    输入玩家信息    ***" << endl;
        cout << "请输入姓名：";
        cin >> name;
        cout << "请输入性别：";
        cin >> sex;
        cout << "请输入年龄：";
        cin >> ages;
        cout << "请输入格斗力：";
        cin >> combat;

        peo[i] = new player(name, ages, sex, combat);
        cout << endl;
    }
    int flag;
    while (true) {
        cout << "\n请选择功能：";
        cin >> flag;
        if (flag == 1) {
            //显示格斗场成员信息
            player::show_count();
            for (int i = 0; i < ans; i++) {
                peo[i]->show();
            }
            cout << endl;
        } else if (flag == 2) {
            int i;
            cout << "要为第几个人装备头盔：";
            cin >> i;
            peo[i - 1]->equip_helm();
        } else if (flag == 3) {
            int i;
            cout << "要为第几个人装备护甲：";
            cin >> i;
            peo[i - 1]->equip_armor();
        } else if (flag == 4) {
            attack(peo);
        } else if (flag == 5) {
            //退出
            cout << "成功退出！" << endl;
            break;
        }
    }
    return 0;
}
