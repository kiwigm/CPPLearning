#include "demo2.h"

typedef struct {
    int first;
    int last;
    int result;
} MY_ARGS;


int arr[5000];
static int s1 = 0;
static int s2 = 0;


void *myfunc2(void *args) {
    int s = 0;
    MY_ARGS *my_args = (MY_ARGS *) args;
    for (int i = my_args->first; i < my_args->last; i++)
        s += i;
    my_args->result = s;
    return NULL;
}

void demo2Test() {
    for (int i = 0; i < 5000; ++i) {
        arr[i] = rand() % 50;
    }

    pthread_t th1, th2;

    MY_ARGS args1 = {0, 2500, 0};
    MY_ARGS args2 = {2500, 5000, 0};

    pthread_create(&th1, NULL, myfunc2, &args1);
    pthread_create(&th2, NULL, myfunc2, &args2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    s1 = args1.result;
    s2 = args2.result;

    printf("s1 = %d\n", s1);
    printf("s2 = %d\n", s2);
    printf("sum = %d\n", s1 + s2);

}