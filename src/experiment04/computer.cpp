#include<iostream>
#include <string.h>

using namespace std;


//CPU类
class CPU {
public:
    CPU() {};

    CPU(char b[10], char m[10], double f, int c, int p, double v);

    ~CPU();

    void begin();//运行
    void close();//关闭
    void show();//显示信息
    void upgrade(char b[10], char m[10], double f, int c, int p, double v);//CPU升级
    int benchmark();//跑分
    bool state;//CPU状态
private:
    char brand[10];//处理器品牌
    char model[10];//处理器型号
    double frequency;//主频
    int cache;//缓存
    int process;//制造工艺
    double vcore;//CPU电压
};

CPU::CPU(char b[10], char m[10], double f, int c, int p, double v) {
    strcpy(brand, b);
    strcpy(model, m);
    frequency = f;
    cache = c;
    process = p;
    vcore = v;
    state = 0;
    cout << "生产了一个新CPU" << endl;
}

CPU::~CPU() {
    cout << "该CPU被析构" << endl;
}

void CPU::begin() {
    state = 1;
    cout << "CPU开始运行" << endl;
}

void CPU::close() {
    state = 0;
    cout << "CPU已经关闭" << endl;
}

void CPU::show() {
    cout << "***        CPU信息       ***" << endl;
    cout << "     处理器品牌：" << brand << "  " << endl;
    cout << "     处理器型号：" << model << "  " << endl;
    cout << "     处理器主频：" << frequency << "GHZ  " << endl;
    cout << "     处理器缓存：" << cache << "KB  " << endl;
    cout << "     处理器工艺：" << process << "nm  " << endl;
    cout << "     处理器电压：" << vcore << "v  " << endl;
    if (state == 1) {
        cout << "***  处理器状态：" << "正在运行" << "  ***\n" << endl;
    } else {
        cout << "***  处理器状态：" << "已经关闭" << "  ***\n" << endl;
    }
}

void CPU::upgrade(char b[10], char m[10], double f, int c, int p, double v) {
    strcpy(brand, b);
    strcpy(model, m);
    frequency = f;
    cache = c;
    process = p;
    vcore = v;
    state = 0;
    cout << "CPU升级完成" << endl;
}

int CPU::benchmark() {
    double temp = frequency * vcore * cache / process;
    temp = temp / (3 * 2 * 256 / 14) * 10000.0;
    return temp;
}

//RAM类
class RAM {
public:
    RAM() {};

    RAM(char b[10], char m[10], int s, int t);

    ~RAM();

    void begin();

    void close();

    void show();

    void judge_frequency();

    void upgrade(char b[10], char m[10], int s, int t);//RAM升级
    int benchmark();

    bool state;//RAM状态
private:
    char brand[10];//品牌
    char model[10];//内存型号
    int size;//大小
    int frequency;//频率
    int time;//存取时间
};

RAM::RAM(char b[10], char m[10], int s, int t) {
    strcpy(brand, b);
    strcpy(model, m);
    size = s;
    time = t;
    judge_frequency();
    state = 0;
    cout << "生产了一个新RAM" << endl;
}

RAM::~RAM() {
    cout << "该RAM被析构" << endl;
}

void RAM::begin() {
    state = 1;
    cout << "RAM开始运行" << endl;
}

void RAM::close() {
    state = 0;
    cout << "RAM已经关闭" << endl;
}

void RAM::show() {
    cout << "***        RAM信息       ***" << endl;
    cout << "     内存品牌：" << brand << "  " << endl;
    cout << "     内存型号：" << model << "  " << endl;
    cout << "     内存频率：" << frequency << "MHZ  " << endl;
    cout << "     内存大小：" << size << "G  " << endl;
    cout << "     存取时间：" << time << "ns  " << endl;
    if (state == 1) {
        cout << "***  内存状态：" << "正在运行" << "  ***\n" << endl;
    } else {
        cout << "***  内存状态：" << "已经关闭" << "  ***\n" << endl;
    }
}

void RAM::judge_frequency() {
    if (model[0] == '1') {
        frequency = 400;
    } else if (model[0] == '2') {
        frequency = 800;
    } else if (model[0] == '3') {
        if (model[1] == 'l' || model[1] == 'L')
            frequency = 1333;
        else
            frequency = 1600;
    } else {
        if (model[1] == 'l' || model[1] == 'L')
            frequency = 2133;
        else
            frequency = 2400;
    }

}

void RAM::upgrade(char b[10], char m[10], int s, int t) {
    strcpy(brand, b);
    strcpy(model, m);
    size = s;
    time = t;
    judge_frequency();
    state = 0;
    cout << "RAM升级完成" << endl;
}

int RAM::benchmark() {
    double temp = frequency * size / time;
    temp = temp / (2400 * 8 / 10) * 10000.0;
    return temp;
}


//输入设备类
class InputDevice {
public:
    InputDevice() {};

    InputDevice(char b1[10], char b2[10], int s, int t);

    ~InputDevice();

    void begin();

    void close();

    void show();

    void upgrade(char b1[10], char b2[10], int s, int t);//InputDevice升级
    bool state;//输入设备状态
private:
    char brand1[10];//键盘品牌
    int size;//键盘尺寸
    char brand2[10];//鼠标品牌
    int time;//鼠标响应时间
};

InputDevice::InputDevice(char b1[10], char b2[10], int s, int t) {
    strcpy(brand1, b1);
    strcpy(brand2, b2);
    size = s;
    time = t;
    state = 0;
    cout << "生产了一个新InputDevice" << endl;
}

InputDevice::~InputDevice() {
    cout << "该InputDevice被析构" << endl;
}

void InputDevice::begin() {
    state = 1;
    cout << "InputDevice开始运行" << endl;
}

void InputDevice::close() {
    state = 0;
    cout << "InputDevice已经关闭" << endl;
}

void InputDevice::show() {
    cout << "***      InputDevice信息     ***" << endl;
    cout << "     键盘品牌：" << brand1 << "  " << endl;
    cout << "     键盘尺寸：" << size << "键  " << endl;
    cout << "     鼠标品牌：" << brand2 << "  " << endl;
    cout << "     响应时间：" << time << "ms  " << endl;
    if (state == 1) {
        cout << "***  输入设备状态：" << "正在运行" << "  ***\n" << endl;
    } else {
        cout << "***  输入设备状态：" << "已经关闭" << "  ***\n" << endl;
    }
}

void InputDevice::upgrade(char b1[10], char b2[10], int s, int t) {
    strcpy(brand1, b1);
    strcpy(brand2, b2);
    size = s;
    time = t;
    state = 0;
    cout << "InputDevice升级完成" << endl;
}


//输出设备类
class OutputDevice {
public:
    OutputDevice() {};

    OutputDevice(char b[10], int s, int f);

    ~OutputDevice();

    void begin();

    void close();

    void show();

    void upgrade(char b[10], int s, int f);//InputDevice升级
    bool state;//输出设备状态
private:
    char brand[10];//显示屏品牌
    int size;//显示屏尺寸
    int frequency;//显示屏刷新频率
};

OutputDevice::OutputDevice(char b[10], int s, int f) {
    strcpy(brand, b);
    size = s;
    frequency = f;
    state = 0;
    cout << "生产了一个新OutputDevice" << endl;
}

OutputDevice::~OutputDevice() {
    cout << "该OutputDevice被析构" << endl;
}

void OutputDevice::begin() {
    state = 1;
    cout << "OutputDevice开始运行" << endl;
}

void OutputDevice::close() {
    state = 0;
    cout << "OutputDevice已经关闭" << endl;
}

void OutputDevice::show() {
    cout << "***     OutputDevice信息     ***" << endl;
    cout << "     屏幕品牌：" << brand << "  " << endl;
    cout << "     屏幕尺寸：" << size << "寸  " << endl;
    cout << "     屏幕刷新：" << frequency << "HZ  " << endl;

    if (state == 1) {
        cout << "***  输出设备状态：" << "正在运行" << "  ***\n" << endl;
    } else {
        cout << "***  输出设备状态：" << "已经关闭" << "  ***\n" << endl;
    }
}

void OutputDevice::upgrade(char b[10], int s, int f) {
    strcpy(brand, b);
    size = s;
    frequency = f;
    state = 0;
    cout << "OutputDevice升级完成" << endl;
}

//硬盘类
class HardDisk {
public:
    HardDisk() {};

    HardDisk(char b[10], int si, int sp);

    ~HardDisk();

    void begin();

    void close();

    void show();

    void upgrade(char b[10], int si, int sp);//InputDevice升级
    int benchmark();

    bool state;//输出设备状态
private:
    char brand[10];//硬盘品牌
    int size;//硬盘大小
    int speed;//硬盘转速
};

HardDisk::HardDisk(char b[10], int si, int sp) {
    strcpy(brand, b);
    size = si;
    speed = sp;
    state = 0;
    cout << "生产了一个新HardDisk" << endl;
}

HardDisk::~HardDisk() {
    cout << "该HardDisk被析构" << endl;
}

void HardDisk::begin() {
    state = 1;
    cout << "HardDisk开始运行" << endl;
}

void HardDisk::close() {
    state = 0;
    cout << "HardDisk已经关闭" << endl;
}

void HardDisk::show() {
    cout << "***     HardDisk信息     ***" << endl;
    cout << "     硬盘品牌：" << brand << "     " << endl;
    cout << "     硬盘大小：" << size << "G     " << endl;
    cout << "     硬盘转速：" << speed << "RPM     " << endl;

    if (state == 1) {
        cout << "***  硬盘状态：" << "正在运行" << "  ***\n" << endl;
    } else {
        cout << "***  硬盘状态：" << "已经关闭" << "  ***\n" << endl;
    }
}

void HardDisk::upgrade(char b[10], int si, int sp) {
    strcpy(brand, b);
    size = si;
    speed = sp;
    state = 0;
    cout << "HardDisk升级完成" << endl;
}

int HardDisk::benchmark() {
    double temp = size * speed;
    temp = temp / (1024 * 7200) * 10000.0;
    return temp;
}

// 计算机类
class Computer {
public:
    Computer() {};

    Computer(CPU My_C, RAM My_R, InputDevice My_I, OutputDevice My_O, HardDisk My_H);

    ~Computer();

    void begin();//开机
    void close();//关机
    void show();//显示计算机所有设备信息
    void upgrade();//Computer升级

    void add();//计算机加法
    void benchmark();//跑分
    void judge();//游戏运行测试

    CPU My_CPU;
    RAM My_RAM;
    InputDevice My_InputDevice;
    OutputDevice My_OutputDevice;
    HardDisk My_HardDisk;

};

Computer::Computer(CPU My_C, RAM My_R, InputDevice My_I, OutputDevice My_O, HardDisk My_H) : My_CPU(My_C), My_RAM(My_R),
                                                                                             My_InputDevice(My_I),
                                                                                             My_OutputDevice(My_O),
                                                                                             My_HardDisk(My_H) {
    cout << "生产了一个新Computer" << endl;
}

Computer::~Computer() {
    cout << "该Computer被析构" << endl;
}

void Computer::begin() {
    My_CPU.begin();
    My_RAM.begin();
    My_InputDevice.begin();
    My_OutputDevice.begin();
    My_HardDisk.begin();
    cout << "Computer成功开机！" << endl;
}

void Computer::close() {
    My_CPU.close();
    My_RAM.close();
    My_InputDevice.close();
    My_OutputDevice.close();
    My_HardDisk.close();
    cout << "Computer已经关闭！" << endl;
}

void Computer::show() {
    My_CPU.show();
    My_RAM.show();
    My_InputDevice.show();
    My_OutputDevice.show();
    My_HardDisk.show();
    cout << endl;
}

void Computer::upgrade() {
    cout << "重新组装中..." << endl;
    cout << "Computer升级完成" << endl;
}

void Computer::add() {
    if (My_CPU.state && My_RAM.state && My_InputDevice.state && My_OutputDevice.state && My_HardDisk.state) {
        int a, b;
        cout << "请输入要计算的两个数：" << endl;
        cin >> a >> b;
        cout << "加法结果：" << a + b << endl;
    } else {
        cout << "计算机还没开机呢！" << endl;
    }
}

void Computer::benchmark() {
    if (My_CPU.state && My_RAM.state && My_InputDevice.state && My_OutputDevice.state && My_HardDisk.state) {
        cout << "跑分中..." << endl;
        int num[5];
        num[0] = My_CPU.benchmark();
        num[1] = My_RAM.benchmark();
        num[2] = My_HardDisk.benchmark();
        cout << "你的计算机的CPU跑分为：" << num[0] << endl;
        cout << "你的计算机的RAM跑分为：" << num[1] << endl;
        cout << "你的计算机的HardDisk跑分为：" << num[2] << endl;
        cout << "你的计算机的综合跑分为：" << num[0] + num[1] + num[2] << endl;
    } else {
        cout << "计算机还没开机呢！" << endl;
    }
}

void Computer::judge() {
    if (My_CPU.state && My_RAM.state && My_InputDevice.state && My_OutputDevice.state && My_HardDisk.state) {
        cout << "游戏运行测试..." << endl;
        int num[5];
        num[0] = My_CPU.benchmark();
        num[1] = My_RAM.benchmark();
        num[2] = My_HardDisk.benchmark();
        cout << "你的计算机的跑分为：" << endl;
        cout << "CPU\tRAM\tHardDisk\t综合" << endl;
        cout << num[0] << "\t" << num[1] << "\t" << num[2] << "\t\t" << num[0] + num[1] + num[2] << endl;

        cout << "游戏：英雄联盟" << endl;
        cout << "CPU\tRAM\tHardDisk\t是否可以运行" << endl;
        if (num[0] >= 4000 && num[1] >= 4000 && num[2] >= 4000)
            cout << "4000\t" << "4000\t" << "4000\t\t" << "是" << endl;
        else
            cout << "4000\t" << "4000\t" << "4000\t\t" << "否" << endl;

        cout << "游戏：绝地求生" << endl;
        cout << "CPU\tRAM\tHardDisk\t是否可以运行" << endl;
        if (num[0] >= 8000 && num[1] >= 8000 && num[2] >= 8000)
            cout << "8000\t" << "8000\t" << "8000\t\t" << "是" << endl;
        else
            cout << "8000\t" << "8000\t" << "8000\t\t" << "否" << endl;
    } else {
        cout << "计算机还没开机呢！" << endl;
    }

}

int main() {
    //freopen("in.txt", "r", stdin);
    cout << "************************************" << endl;
    cout << "***     欢迎来到计算机组装厂     ***" << endl;
    cout << "*** 1.计算机信息显示             ***" << endl;
    cout << "*** 2.CPU升级                    ***" << endl;
    cout << "*** 3.RAM升级                    ***" << endl;
    cout << "*** 4.InputDevice升级            ***" << endl;
    cout << "*** 5.OutputDevice升级           ***" << endl;
    cout << "*** 6.HardDisk升级               ***" << endl;
    cout << "*** 7.计算机开机                 ***" << endl;
    cout << "*** 8.计算机关机                 ***" << endl;
    cout << "*** 9.计算机加法                 ***" << endl;
    cout << "*** 10.跑分                      ***" << endl;
    cout << "*** 11.游戏运行测试              ***" << endl;
    cout << "*** 12.退出组装厂                ***" << endl;
    cout << "************************************\n" << endl;

    cout << "着手开始设计你的第一台计算机吧！" << endl;
    char brand[10];//品牌
    char model[10];//型号
    double frequency;//主频
    int cache;//缓存
    int process;//制造工艺
    double vcore;//CPU电压
    cout << "***           创造CPU            ***" << endl;
    cout << "处理器品牌：";
    cin >> brand;
    cout << "处理器型号：";
    cin >> model;
    cout << "处理器主频(GHZ)：";
    cin >> frequency;
    cout << "处理器缓存(KB)：";
    cin >> cache;
    cout << "处理器工艺(NM)：";
    cin >> process;
    cout << "处理器电压(V)：";
    cin >> vcore;
    CPU MY_CPU(brand, model, frequency, cache, process, vcore);

    //输入
    int size;//大小
    int time;//存取时间
    cout << "***           创造RAM            ***" << endl;
    cout << "内存品牌：";
    cin >> brand;
    cout << "内存型号：DDR";
    cin >> model;
    cout << "内存频率自动判断中..." << endl;
    cout << "内存大小(G)：";
    cin >> size;
    cout << "存取时间(NM)：";
    cin >> time;
    RAM MY_RAM(brand, model, size, time);


    char brand1[10];//品牌
    char brand2[10];//品牌
    cout << "***        创造InputDevice       ***" << endl;
    cout << "键盘品牌：";
    cin >> brand1;
    cout << "键盘尺寸(键)：";
    cin >> size;
    cout << "鼠标品牌：";
    cin >> brand2;
    cout << "响应时间(MS)：";
    cin >> time;
    InputDevice MY_InputDevice(brand1, brand2, size, time);


    cout << "***        创造OutputDevice       ***" << endl;
    cout << "屏幕品牌：";
    cin >> brand;
    cout << "屏幕尺寸(寸)：";
    cin >> size;
    cout << "屏幕刷新(HZ)：";
    cin >> frequency;
    OutputDevice MY_OutputDevice(brand, size, frequency);

    int speed;//转速
    cout << "***          创造HardDisk         ***" << endl;
    cout << "硬盘品牌：";
    cin >> brand;
    cout << "硬盘大小(G)：";
    cin >> size;
    cout << "硬盘转速(RPM)：";
    cin >> speed;
    HardDisk MY_HardDisk(brand, size, speed);

    cout << "***         计算机初始化中        ***" << endl;
    Computer MY_Computer(MY_CPU, MY_RAM, MY_InputDevice, MY_OutputDevice, MY_HardDisk);

    int flag;
    while (true) {
        cout << "\n请选择功能：";
        cin >> flag;
        if (flag == 1) {
            //计算机信息显示
            MY_Computer.show();
        } else if (flag == 2) {
            //升级CPU
            cout << "***           升级CPU            ***" << endl;
            cout << "处理器品牌：";
            cin >> brand;
            cout << "处理器型号：";
            cin >> model;
            cout << "处理器主频(GHZ)：";
            cin >> frequency;
            cout << "处理器缓存(KB)：";
            cin >> cache;
            cout << "处理器工艺(NM)：";
            cin >> process;
            cout << "处理器电压(V)：";
            cin >> vcore;
            MY_Computer.My_CPU.upgrade(brand, model, frequency, cache, process, vcore);
        } else if (flag == 3) {
            //升级RAM
            cout << "***           升级RAM            ***" << endl;
            cout << "内存品牌：";
            cin >> brand;
            cout << "内存型号：";
            cin >> model;
            cout << "内存频率自动判断中..." << endl;
            cout << "内存大小(G)：";
            cin >> size;
            cout << "存取时间(NM)：";
            cin >> time;
            MY_Computer.My_RAM.upgrade(brand, model, size, time);
        } else if (flag == 4) {
            //升级InputDevice
            cout << "***        升级InputDevice       ***" << endl;
            cout << "键盘品牌：";
            cin >> brand1;
            cout << "键盘尺寸(键)：";
            cin >> size;
            cout << "鼠标品牌：";
            cin >> brand2;
            cout << "响应时间(MS)：";
            cin >> time;
            MY_Computer.My_InputDevice.upgrade(brand1, brand2, size, time);
        } else if (flag == 5) {
            //升级OutputDevice
            cout << "***        升级OutputDevice       ***" << endl;
            cout << "屏幕品牌：";
            cin >> brand;
            cout << "屏幕尺寸(寸)：";
            cin >> size;
            cout << "屏幕刷新(HZ)：";
            cin >> frequency;
            MY_Computer.My_OutputDevice.upgrade(brand, size, frequency);
        } else if (flag == 6) {
            //升级HardDisk
            cout << "***          升级HardDisk         ***" << endl;
            cout << "硬盘品牌：";
            cin >> brand;
            cout << "硬盘大小(G)：";
            cin >> size;
            cout << "硬盘转速(RPM)：";
            cin >> speed;
            MY_Computer.My_HardDisk.upgrade(brand, size, speed);
        } else if (flag == 7) {
            //开机
            MY_Computer.begin();
        } else if (flag == 8) {
            //关机
            MY_Computer.close();
        } else if (flag == 9) {
            //计算机加法
            MY_Computer.add();
        } else if (flag == 10) {
            //跑分
            MY_Computer.benchmark();
        } else if (flag == 11) {
            //游戏运行测试
            MY_Computer.judge();
        } else if (flag == 12) {
            //退出
            cout << "成功退出！" << endl;
            break;
        }
    }
    return 0;
}
