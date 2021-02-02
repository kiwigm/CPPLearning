#include "demo1.h"

void *myfunc1(void *args) {
    printf("Hello Thread\n");
    char *name = (char *) args;
    for (int i = 1; i <= 500; i++)
        printf("<%s>%d\n", name, i);
    return NULL;
}
void demo1Test(){
    printf("Hello World!\n");

    pthread_t th1, th2;

    char s1[] = "th1";
    char s2[] = "th2";
    pthread_create(&th1, NULL, myfunc1, s1);
    pthread_create(&th2, NULL, myfunc1, s2);

    // 等待进程结束
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

}