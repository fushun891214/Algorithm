#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}INode;

typedef struct Stack{
    INode *top;
}IStack;

int push(IStack *stack,int item){
    INode *temp = (INode *)malloc(sizeof(INode));
    if(temp != NULL){
        temp->data = item;
        temp->next = stack->top;
        stack->top = temp;
        return 1;
    }
    printf("%s","Out of space");
    return 0;
}

int main(void){
    IStack *stack = (IStack *)malloc(sizeof(IStack));
    int item = 10;
    push(stack,item);
    printf("%d \n",stack->top->data);
    push(stack,item += 5);
    printf("%d \n",stack->top->data);
    free(stack);
}