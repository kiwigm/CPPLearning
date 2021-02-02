#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>

using namespace std;

class player {
public:
    player() {};

    player(string n, int a, string s, int I, int sh, int co, int at, int so, int an, int me, int bu, int pl);

    void character();//特性生成
    void show();//成员信息显示
    static void show_count();//显示人员总数
    static void show_y_count();//显示樱花庄情感信息
    static void express(player *peo[10]);//表白
    static void separate(player *peo[10]);//分手

private:
    string name;//姓名
    int ages;//年龄
    string sex;//性别
    int blood;//血量
    int IQ;//智识
    int shooting;//射击
    int combat;//格斗
    int attract;//吸引力
    int social;//社交
    int animal;//驯兽
    int medical;//医疗
    int build;//建造
    int plant;//种植

    string my_character;//特性名称
    string my_details;//特性描述
    string my_effect;//特性效果
    string mate;//配偶

    static int count;//樱花庄人员总数
    static int y_count;//樱花庄有对象人员总数
};

int player::count = 0;
int player::y_count = 0;

//显示人员总数
void player::show_count() {
    cout << "当前樱花庄成员总数：" << count << endl;
}

//显示樱花庄情感信息
void player::show_y_count() {
    cout << "当前樱花庄有对象成员总数：" << y_count << endl;
    cout << "当前樱花庄单身狗总数：" << count - y_count << endl;
}

//初始化
player::player(string n, int a, string s, int I, int sh, int co, int at, int so, int an, int me, int bu, int pl) {
    name = n;
    ages = a;;
    sex = s;
    blood = 100;
    IQ = I;
    shooting = sh;
    combat = co;
    attract = at;
    social = so;
    animal = an;
    medical = me;
    build = bu;
    plant = pl;
    mate = "无";
    cout << "冥冥之中自有天意...特性随机生成中" << endl;
    character();
    cout << "新的樱花庄成员诞生了！" << endl;
    count++;
}


void player::character() {
    string Character[10];
    string details[10];
    string effect[10];
    Character[0] = "冷枪手";
    Character[1] = "建筑工程师";
    Character[2] = "仿生学神学家";
    Character[3] = "乐天派";
    Character[4] = "悲观主义者";
    Character[5] = "倾国倾城";
    Character[6] = "丑陋";
    Character[7] = "聪明过头";
    Character[8] = "园艺专家";
    Character[9] = "格斗者";
    details[0] = "的枪法还不错，但他总是需要比别人花更久来瞄准目标";
    details[1] = "得益于父亲的熏陶，对于建筑的事情他简直是无所不知";
    details[2] = "感觉作为一个人类能做的事实在太有限了，做梦都在研究先进的仿生学部件";
    details[3] = "总是对他的情况有种积极的感觉，无论什么时候，无论什么情况";
    details[4] = "喜欢看生命中糟糕的一面";
    details[5] = "长得非常漂亮，有着貌美的面庞，人们往往在他张嘴说话之前就已经被倾倒";
    details[6] = "外貌太丑陋，那张脸生得好像就是一副现代抽象画，仅仅是看着他说话都需要鼓起很大的勇气";
    details[7] = "实在是机灵过人，他学起东西来比谁都快，但是偏向性比较严重";
    details[8] = "对园艺有一种特殊的爱好。他对每种一株植物都会觉得很高兴";
    details[9] = "喜欢近距离战斗，格斗技术非常不错，但他用起远程武器来就会很不开心";
    effect[0] = "射击+10";
    effect[1] = "建造+20";
    effect[2] = "医疗+8";
    effect[3] = "社交+10";
    effect[4] = "社交-10";
    effect[5] = "吸引力+15";
    effect[6] = "吸引力-15";
    effect[7] = "智识+12";
    effect[8] = "种植+8";
    effect[9] = "格斗+10";

    srand((unsigned) time(NULL));
    int flag = rand() % 10;
    my_character = Character[flag];
    my_details = name + details[flag];
    my_effect = effect[flag];

    if (flag == 0) {
        shooting = min(100, shooting + 10);
    } else if (flag == 1) {
        build = min(100, build + 20);
    } else if (flag == 2) {
        medical = min(100, medical + 8);
    } else if (flag == 3) {
        social = min(100, social + 10);
    } else if (flag == 4) {
        social = max(0, social - 10);
    } else if (flag == 5) {
        attract = min(100, attract + 15);
    } else if (flag == 6) {
        attract = max(0, attract - 15);
    } else if (flag == 7) {
        IQ = min(100, IQ + 12);
    } else if (flag == 8) {
        plant = min(100, plant + 8);
    } else if (flag == 9) {
        combat = min(100, combat + 10);
    }
}

//显示成员信息
void player::show() {
    cout << "*************************" << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    cout << "年龄：" << ages << endl;
    cout << "血量槽：" << blood << endl;
    cout << "智识力：" << IQ << endl;
    cout << "射击力：" << shooting << endl;
    cout << "格斗力：" << combat << endl;
    cout << "吸引力：" << attract << endl;
    cout << "社交力：" << social << endl;
    cout << "驯兽力：" << animal << endl;
    cout << "医疗力：" << medical << endl;
    cout << "建造力：" << build << endl;
    cout << "种植力：" << plant << endl;
    cout << "特性名称：" << my_character << endl;
    cout << "特性描述：" << my_details << endl;
    cout << "特性效果：" << my_effect << endl;
    cout << "配偶：" << mate << endl;

}

//表白
void player::express(player *peo[10]) {
    string name1, name2;
    cout << "请输入表白者姓名：";
    cin >> name1;
    cout << "请输入被表白者姓名：";
    cin >> name2;

    // 找两个人的下标
    int flag1, flag2;
    for (int i = 0; i < count; i++) {
        if (name1 == peo[i]->name) {
            flag1 = i;
        } else if (name2 == peo[i]->name) {
            flag2 = i;
        }
    }

    if (peo[flag1]->mate == "无") {
        if (peo[flag2]->mate == "无") {
            if (peo[flag1]->attract >= peo[flag2]->social) {
                cout << "表白成功！" << endl;
                peo[flag1]->mate = peo[flag2]->name;
                peo[flag2]->mate = peo[flag1]->name;
                y_count = y_count + 2;
            } else {
                cout << peo[flag1]->name << "的吸引力<" << peo[flag2]->name << "的社交力" << endl;
                cout << "表白失败！" << endl;
            }
        } else {
            cout << peo[flag2]->name << "已经有对象" << peo[flag2]->mate << endl;
        }
    } else {
        cout << peo[flag1]->name << "已经有对象" << peo[flag1]->mate << endl;
    }

}

//分手
void player::separate(player *peo[10]) {
    string name1, name2;
    cout << "请输入分手者姓名：";
    cin >> name1;
    cout << "请输入被分手者姓名：";
    cin >> name2;

    int flag1, flag2;
    for (int i = 0; i < count; i++) {
        if (name1 == peo[i]->name) {
            flag1 = i;
        } else if (name2 == peo[i]->name) {
            flag2 = i;
        }
    }


    if (peo[flag1]->mate != "无") {
        if (peo[flag2]->mate != "无") {
            if (peo[flag1]->mate == peo[flag2]->name && peo[flag2]->mate == peo[flag1]->name) {
                cout << peo[flag1]->name << "和" << peo[flag2]->name << "分手了！" << endl;
                y_count = y_count - 2;
                peo[flag1]->mate = "无";
                peo[flag2]->mate = "无";
            } else {
                cout << "他两不是一对！" << endl;
            }
        } else {
            cout << peo[flag2]->name << "还没对象呢！" << endl;
        }
    } else {
        cout << peo[flag1]->name << "还没对象呢！" << endl;
    }
}

int main() {
    cout << "**********************************" << endl;
    cout << "***       欢迎来到樱花庄       ***" << endl;
    cout << "*** 1.显示樱花庄成员信息       ***" << endl;
    cout << "*** 2.表白                     ***" << endl;
    cout << "*** 3.分手                     ***" << endl;
    cout << "*** 4.显示樱花庄感情情况       ***" << endl;
    cout << "*** 5.退出樱花庄               ***" << endl;
    cout << "**********************************\n" << endl;

    player *peo[10];
    int ans;
    cout << "请输入待进驻樱花庄的人员数：";
    cin >> ans;
    string name;//姓名
    int ages;//年龄
    string sex;//性别
    int IQ;//智识
    int shooting;//射击
    int combat;//格斗
    int attract;//吸引力
    int social;//社交
    int animal;//驯兽
    int medical;//医疗
    int build;//建造
    int plant;//种植

    //输入信息
    for (int i = 0; i < ans; i++) {
        cout << "***    输入玩家信息    ***" << endl;
        cout << "请输入姓名：";
        cin >> name;
        cout << "请输入性别：";
        cin >> sex;
        cout << "请输入年龄：";
        cin >> ages;
        cout << "请输入智识力：";
        cin >> IQ;
        cout << "请输入射击力：";
        cin >> shooting;
        cout << "请输入格斗力：";
        cin >> combat;
        cout << "请输入吸引力：";
        cin >> attract;
        cout << "请输入社交力：";
        cin >> social;
        cout << "请输入驯兽力：";
        cin >> animal;
        cout << "请输入医疗力：";
        cin >> medical;
        cout << "请输入建造力：";
        cin >> build;
        cout << "请输入种植力：";
        cin >> plant;
        peo[i] = new player(name, ages, sex, IQ, shooting, combat, attract, social, animal, medical, build, plant);
        cout << endl;
    }
    int flag;
    while (true) {
        cout << "\n请选择功能：";
        cin >> flag;
        if (flag == 1) {
            //显示樱花庄成员信息
            player::show_count();
            for (int i = 0; i < ans; i++) {
                peo[i]->show();
            }
            cout << endl;
        } else if (flag == 2) {
            //表白
            player::express(peo);
        } else if (flag == 3) {
            //分手
            player::separate(peo);
        } else if (flag == 4) {
            //显示樱花庄感情情况
            player::show_count();
            player::show_y_count();
        } else if (flag == 5) {
            //退出
            cout << "成功退出！" << endl;
            break;
        }
    }

    return 0;
}