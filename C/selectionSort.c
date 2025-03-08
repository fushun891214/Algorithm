#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr,int n){
    int i,j,min;
    for(i = 0;i < n-1;i++){
        min = i;
        for(j = i+1;j < n;j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(i != min){
            swap(&arr[i],&arr[min]);
        }
    }
}

int main(void){
    int n = 5;
    int arr[5] = {4,5,3,2,1};
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    selectionSort(arr,n);
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }
}