#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "demo1.h"
#include "demo2.h"
#include "demo3_lock.h"
#include "demo4.h"
#include "demo5.h"

int main() {

//     demo1Test();

//    // 两个线程计算0-5000的和，0-2500一个，2500-5000一个
//     demo2Test();

//    // 锁
//    demo3Test();

//    // 使用一个数组存储两个结果
//    demo4Test();

    demo5Test();
    return 0;
}