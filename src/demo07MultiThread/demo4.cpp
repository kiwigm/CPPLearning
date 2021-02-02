#include "demo4.h"
#define MAXSIZE 50000000


typedef struct {
    int first;
    int last;
    int id;
} MY_ARGS;


int *arr1;
int result[2];



void *myfunc4(void *args) {

    MY_ARGS *my_args = (MY_ARGS *) args;

    int first = my_args->first;
    int last = my_args->last;
    int id = my_args->id;

    for (int i = first; i < last; i++)
        result[id] += arr1[i];

    return NULL;
}

void demo4Test() {
    arr1 = (int *)malloc(sizeof(int) * MAXSIZE);
    for (int i = 0; i < MAXSIZE; ++i) {
        arr1[i] = rand() % 5;
    }

    result[0] = 0;
    result[1] = 0;

    pthread_t th1, th2;

    int mid = MAXSIZE / 2;

    MY_ARGS args1 = {0, mid, 0};
    MY_ARGS args2 = {mid, MAXSIZE, 1};

    pthread_create(&th1, NULL, myfunc4, &args1);
    pthread_create(&th2, NULL, myfunc4, &args2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    printf("s1 = %d\n", result[0]);
    printf("s2 = %d\n", result[1]);
    printf("sum = %d\n", result[0] + result[1]);

}