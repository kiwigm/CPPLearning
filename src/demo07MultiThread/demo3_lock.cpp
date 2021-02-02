#include "demo3_lock.h"

pthread_mutex_t lock;

static int s = 0;

void *myfunc3(void *args){
//    pthread_mutex_lock(&lock);
    for (int i = 0; i < 100000; ++i) {
        // 申请资源，阻塞 P
        pthread_mutex_lock(&lock);
        s++;
        // 释放资源 V
        pthread_mutex_unlock(&lock);
    }
//    pthread_mutex_unlock(&lock);
    return NULL;
}

void demo3Test(){
    pthread_t th1,th2;

    // 创建锁
    pthread_mutex_init(&lock,NULL);
    pthread_create(&th1,NULL,myfunc3,NULL);
    pthread_create(&th2,NULL,myfunc3,NULL);

    pthread_join(th1,NULL);
    pthread_join(th2,NULL);

    printf("%d\n",s);

    // 删除锁
    pthread_mutex_destroy(&lock);


}