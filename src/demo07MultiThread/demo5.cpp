#include "demo5.h"
#include<semaphore.h>

#define Maxsize 100
#define QueueElemType int

typedef struct {
    QueueElemType data[Maxsize];
    int front,rear;
}SqQueue;

void InitQueue(SqQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
}

int QueueEmpty(SqQueue *Q) {
    return Q->front == Q->rear ? 1 : 0;
}

int EnQueue(SqQueue *Q, QueueElemType x) {
    if ((Q->rear + 1) % Maxsize == Q->front)
        return 0;
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % Maxsize;
    return 1;
}

QueueElemType DeQueue(SqQueue *Q) {
//    if (Q->rear == Q->front)
//        return NULL;
    QueueElemType x = Q->data[Q->front];
    Q->front = (Q->front + 1) % Maxsize;
    return x;
}


sem_t *sem;

static int s = 0;

void *producer(void *args){
    SqQueue *Q = (SqQueue*) args;
    sem_wait(sem);
    EnQueue(Q,1);


    return NULL;
}

void demo5Test(){
    pthread_t th[2];

    SqQueue *Q = (SqQueue*)malloc(sizeof(SqQueue));
    InitQueue(Q);

    pthread_create(&th[0],NULL,producer,Q);
    pthread_create(&th[1],NULL,producer,Q);

    pthread_join(th[0],NULL);
    pthread_join(th[1],NULL);

    printf("%d\n", s);




}