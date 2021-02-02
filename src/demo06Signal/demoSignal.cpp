#include "demoSignal.h"

using namespace std;

void signalHandler(int signum) {
    cout << "Interrupt signal (" << signum << ") received.\n";

    // 清理并关闭
    // 终止程序

    exit(signum);

}

void demo06SignalTest() {
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    while (1) {
        cout << "Going to sleep...." << endl;
        sleep(1);
    }
}

void demo06RaiseTest (){
    int i = 0;
    // 注册信号 SIGINT 和信号处理程序
    signal(SIGINT, signalHandler);

    while(++i){
        cout << "Going to sleep...." << endl;
        if( i == 3 ){
            raise( SIGINT);
        }
        sleep(1);
    }
}

int main(){
    demo06SignalTest();
    demo06RaiseTest();

    return 0;
}