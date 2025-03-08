#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n,char source,char destination,char auxiliary){
    if(n == 1){
        printf("Move disk 1 from source %c to destination %c \n",source,destination);
        return;
    }
    towerOfHanoi(n-1,source,auxiliary,destination);
    printf("Move disk %d from source %c to destination %c \n",n,source,destination);
    towerOfHanoi(n-1,auxiliary,destination,source);
}

int main(void){
    int n = 3;
    char a = 'A',b = 'B',c = 'C';
    towerOfHanoi(n,a,b,c);
}