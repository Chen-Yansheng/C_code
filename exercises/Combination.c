#include <stdio.h>
#include <stdlib.h>

void process(int arr[], int tarray[], int l, int r, int k, int n){
    if(n == k){ 
        for(int i=0; i<k; i++){
            printf("%d ",tarray[i]);
        }
        printf("\n");

        return ;
    }
    for(int i=l; i<=r && r-i+1>=k-n; i++){
        tarray[n] = arr[i]; //不能是n++
        process(arr, tarray, i+1, r, k, n+1);   //是i+1，不是l+1
    }
}   

void PrintCombination(int arr[], int size, int k){
    int *tarray=(int *)malloc(sizeof(int) * k);
    if(!tarray){
        printf("Target array request failed!\n");
        return ;
    }
    int n=0;    //记录组合数组里的元素个数
    process(arr, tarray, 0, size-1, k, n);
    free(tarray);
}

int main(){
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k=2;

    PrintCombination(arr, size, k);

    return 0;
}