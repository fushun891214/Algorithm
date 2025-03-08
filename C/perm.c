#include <stdio.h>
#include <stdlib.h>

void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void perm(char *list,int i,int n){
    int j;
    if(i == n){
        for(j = 0;j <= n;j++){
            printf("%c",list[j]);
        }
        printf("\n");
        return;
    }
    for(j = i;j <= n;j++){
        swap(&list[i],&list[j]);
        perm(list,i + 1,n);
        swap(&list[i],&list[j]);
    }
}

int main(void){
    char list[3] = {'a','b','c'};
    perm(list,0,2);
}