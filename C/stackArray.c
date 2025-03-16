#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct stack{
    int top;
    int *array;
}IStack;

int push(IStack *stack,int item){
    if(stack->top >= (MAX_SIZE - 1)){
        printf("Stack is full \n");
        return 0;
    }
    stack->top++;
    stack->array[stack->top] = item;
    return 1;
}

int pop(IStack *stack){
    if(stack->top < 0){
        printf("Stack is empty \n");
        return -1;
    }
    int item = stack->array[stack->top];
    stack->top--;
    return item;
}

int main(void){
    IStack *stack = (IStack *)malloc(sizeof(IStack));
    stack->top = -1;
    stack->array = (int *)malloc(sizeof(int) * MAX_SIZE);
    int item = 10;

    for(int i = 0;i < MAX_SIZE;i++){
        push(stack,item++);
    }

    for(int i = 0;i <= stack->top;i++){
        printf("%d \n",stack->array[i]);
    }

    printf("\n");

    for(int i = 0;i < MAX_SIZE;i++){
        printf("%d \n",pop(stack));
    }
}