#include <stdio.h>
#include <stdlib.h>

int exponentiate(int x,int n){
    int m = n;
    int power = 1;
    int z = x;
    while(m > 0){
        while(m % 2 == 0){
            m /= 2;
            z *= z;
        }
        m -= 1;
        power *= z;
    }
    return power;
}

int main(void){
    printf("%d",exponentiate(2,5));
}