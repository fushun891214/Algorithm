#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

typedef struct Node{
    int data;
    struct Node *next;
}INode;

typedef struct Stack{
    INode *top;
}IStack;

int push(IStack *Stack,int item){
    INode *temp = (INode *)malloc(sizeof(INode));
    if(temp != NULL){
        temp->data = item;
        temp->next = Stack->top;
        Stack->top = temp;
        return 1;
    }
    else{
        printf("%s","Out of space");
        return 0;
    }
}

int main(void){
    IStack *stack = (IStack *)malloc(sizeof(stack));
    int item = 10;
    push(stack,item);
    printf("%d \n",stack->top->data);
    push(stack,++item);
    printf("%d \n",stack->top->data);
}