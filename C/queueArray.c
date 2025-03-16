#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct Queue{
    int front;
    int real;
    int *array;
}IQueue;

int AddQueue(IQueue *Queue,int item){
    Queue->real = (Queue->real + 1) % MAX_SIZE;
    if(Queue->front == Queue->real){
        Queue->real = (Queue->real - 1) % MAX_SIZE;
        printf("Queue is full");
        return 0;
    }
    Queue->array[Queue->real] = item;
    return 1;
}

int DeleteQueue(IQueue *Queue){
    if(Queue->real == Queue->front){
        printf("Queue is empty");
        return 0;
    }
    int item = Queue->array[Queue->front];
    Queue->front = (Queue->front + 1) % MAX_SIZE;
    return 1;
}

int main(void){
    IQueue *Queue = (IQueue *)malloc(sizeof(IQueue));
    Queue->array = (int *)malloc(sizeof(int) * MAX_SIZE);
    int item = 10;
    AddQueue(Queue,item);
    printf("%d \n",Queue->array[Queue->real]);
    AddQueue(Queue,item += 5);
    printf("%d \n",Queue->array[Queue->real]);
    DeleteQueue(Queue);
    printf("%d \n",Queue->array[Queue->front]);
    DeleteQueue(Queue);
    printf("%d \n",Queue->array[Queue->front]);
    free(Queue);
}