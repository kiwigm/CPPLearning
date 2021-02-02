#include<iostream>
#include <time.h>
#include <algorithm>
#include<string>
using namespace std;

class player
{
public:
    player();//数值信息随机生成
    void character();//特性随机生成
    void Name();//姓名随机生成
    void Race();//门派随机生成
    void show();//成员信息显示
    static void show_count();//显示人员统计
    static void show_race();//显示门派统计
    static void show_chara();//显示特性统计

private:
    string name;//姓名
    int ages;//年龄
    string sex;//性别
    string race;//门派
    int blood;//血量
    int IQ;//智识
    int attack;//攻击
    int attract;//吸引力
    int social;//社交
    int medical;//医疗
    int plant;//种植

    string my_character;//特性名称
    string my_details;//特性描述
    string my_effect;//特性效果

    //统计
    static int count;//风暴峡谷人员总数
    static int male;//风暴峡谷男性
    static int female;//风暴峡谷女性
    static int racee[7];//风暴峡谷门派
    static int chara[10];//风暴峡谷特性
};

int player::count = 0;
int player::male = 0;
int player::female = 0;
int player::racee[7] = { 0,0,0,0,0,0,0 };
int player::chara[10]= { 0,0,0,0,0,0,0,0,0,0 };

//显示人员男女统计
void player::show_count()
{
    cout << "总数\t男\t女" << endl;
    cout << "|" << count << "\t" << "|" << male << "\t" << "|" << female << "\t" << endl;
}

//显示风暴峡谷门派统计
void player::show_race()
{
    string Kinds[7] = {
            "苍江派","摩尼教","药王谷","藏墨派","飞白派","八法门","剑锋派"
    };

    for (int i = 0; i < 7; i++)
    {
        cout << Kinds[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << "|" << racee[i] << "\t";
    }
    cout << endl;
}

//显示风暴峡谷特性统计
void player::show_chara()
{
    string Character[10];
    Character[0] = "冷枪手";
    Character[1] = "农学家";
    Character[2] = "仿生学";
    Character[3] = "乐天派";
    Character[4] = "悲观者";
    Character[5] = "倾国城";
    Character[6] = "丑陋";
    Character[7] = "聪明秃";
    Character[8] = "园艺精";
    Character[9] = "格斗者";

    for (int i = 0; i < 10; i++)
    {
        cout << Character[i] << "\t";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "|" << chara[i] << "\t";
    }
    cout << endl;
}

//初始化
player::player()
{

    Name();
    ages = rand() % 100;
    if (rand() % 2)
    {
        sex = "男";
        male++;
    }
    else
    {
        sex = "女";
        female++;
    }
    Race();
    blood = 100;
    IQ = rand() % 100;
    attack = rand() % 100;
    attract = rand() % 100;
    social = rand() % 100;
    medical = rand() % 100;
    plant = rand() % 100;
    character();
    count++;
}
//初始化名字
void player::Name()
{
    string NName[36] = {
            "百里","北堂","北野","淳于","尉迟","成公",
            "叱干","尉迟","尉迟","上官","陈林","淳于",
            "成公","太史","叱利","常夏","陈梁","陈林",
            "公冶","公羊","完颜","公西","公孟","哥舒",
            "谷梁","谷利","高堂","郭罗","诸葛","呼延",
            "宗政","主父","张包","张简","钟任","仲夏"
    };
    name = NName[rand() % 36];
    return;
}
//初始化门派
void player::Race()
{
    string Kinds[7] = {
            "苍江派","摩尼教","药王谷","藏墨派","飞白派","八法门","剑锋派"
    };
    int flag = rand() % 7;
    race = Kinds[flag];
    racee[flag]++;
    return;
}

//特性随机生成
void player::character()
{
    string Character[10];
    string details[10];
    string effect[10];
    Character[0] = "冷枪手";
    Character[1] = "农学家";
    Character[2] = "仿生学";
    Character[3] = "乐天派";
    Character[4] = "悲观者";
    Character[5] = "倾国城";
    Character[6] = "丑陋";
    Character[7] = "聪明秃";
    Character[8] = "园艺精";
    Character[9] = "格斗者";
    details[0] = "的枪法还不错，但ta总是需要比别人花更久来瞄准目标";
    details[1] = "得益于父亲的熏陶，对于种植的事情他简直是无所不知";
    details[2] = "感觉作为一个人类能做的太有限了，做梦都在研究先进的仿生学部件";
    details[3] = "总是对他的情况有种积极的感觉，无论什么时候，无论什么情况";
    details[4] = "喜欢看生命中糟糕的一面";
    details[5] = "有着貌美的面庞，人们往往在ta张嘴说话之前就已经被倾倒";
    details[6] = "外貌太丑陋，那张脸生得好像就是一副现代抽象画";
    details[7] = "实在是机灵过人，ta学起东西来比谁都快";
    details[8] = "对园艺有一种特殊的爱好。ta对每种一株植物都会觉得很高兴";
    details[9] = "格斗技术非常不错，但ta用起远程武器来就会很不开心";
    effect[0] = "攻击+10";
    effect[1] = "种植+20";
    effect[2] = "医疗+8";
    effect[3] = "社交+10";
    effect[4] = "社交-10";
    effect[5] = "吸引力+15";
    effect[6] = "吸引力-15";
    effect[7] = "智识+12";
    effect[8] = "种植+8";
    effect[9] = "攻击+10";

    int flag = rand() % 10;
    my_character = Character[flag];
    my_details = name + details[flag];
    my_effect = effect[flag];
    if (flag == 0)
    {
        attack = min(100, attack + 10);
    }
    else if (flag == 1)
    {
        plant = min(100, plant + 20);
    }
    else if (flag == 2)
    {
        medical = min(100, medical + 8);
    }
    else if (flag == 3)
    {
        social = min(100, social + 10);
    }
    else if (flag == 4)
    {
        social = max(0, social - 10);
    }
    else if (flag == 5)
    {
        attract = min(100, attract + 15);
    }
    else if (flag == 6)
    {
        attract = max(0, attract - 15);
    }
    else if (flag == 7)
    {
        IQ = min(100, IQ + 12);
    }
    else if (flag == 8)
    {
        plant = min(100, plant + 8);
    }
    else if (flag == 9)
    {
        attack = min(100, attack + 10);
    }
    chara[flag]++;
}
//显示成员信息
void player::show()
{
    cout << "*************************" << endl;
    cout << "姓名：" << name << endl;
    cout << "性别：" << sex << endl;
    cout << "年龄：" << ages << endl;
    cout << "门派：" << race << endl;
    cout << "血量槽：" << blood << endl;
    cout << "智识力：" << IQ << endl;
    cout << "攻击力：" << attack << endl;
    cout << "吸引力：" << attract << endl;
    cout << "社交力：" << social << endl;
    cout << "医疗力：" << medical << endl;
    cout << "种植力：" << plant << endl;
    cout << "特性名称：" << my_character << endl;
    cout << "特性描述：" << my_details << endl;
    cout << "特性效果：" << my_effect << endl;
}
int main()
{
    cout << "**********************************" << endl;
    cout << "***      欢迎来到风暴峡谷      ***" << endl;
    cout << "*** 1.显示风暴峡谷成员信息     ***" << endl;
    cout << "*** 2.显示男女人数             ***" << endl;
    cout << "*** 3.显示每种特性的人数       ***" << endl;
    cout << "*** 4.显示每个门派的人数       ***" << endl;
    cout << "*** 5.退出风暴峡谷             ***" << endl;
    cout << "**********************************\n" << endl;
    srand((unsigned)time(NULL));
    player *peo[200];
    int ans;
    cout << "请输入风暴峡谷的人员总数：";
    cin >> ans;
    cout << "\n***  随机生成玩家信息完毕  ***" << endl;
    //输入信息
    for (int i = 0; i < ans; i++)
    {
        peo[i] = new player();
    }
    int flag;
    while (true)
    {
        cout << "\n请选择功能：";
        cin >> flag;
        if (flag == 1)
        {
            //显示风暴峡谷成员信息
            for (int i = 0; i < ans; i++)
            {
                peo[i]->show();
            }
            cout << endl;
        }
        else if (flag == 2)
        {
            //显示男女人数
            player::show_count();
        }
        else if (flag == 3)
        {
            //显示每种特性的人数
            player::show_chara();
        }
        else if (flag == 4)
        {
            //显示每个门派的人数
            player::show_race();
        }
        else if (flag == 5)
        {
            //退出
            cout << "成功退出！" << endl;
            break;
        }
    }
    return 0;
}