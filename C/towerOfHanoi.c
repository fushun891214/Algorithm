#include<stdio.h>
#include<stdlib.h>

void towerOfHanoi(int n,char source,char destiation,char auxiliary){
    if(n == 1){
        printf("Move disk 1 from source %c to destiation %c \n",source,destiation);
        return;
    }
    towerOfHanoi(n-1,source,auxiliary,destiation);
    printf("Move dick %d from source %c to destiation %c \n",n,source,destiation);
    towerOfHanoi(n-1,auxiliary,destiation,source);
}

int main(void){
    int n = 3;
    towerOfHanoi(n,'A','B','C');
}