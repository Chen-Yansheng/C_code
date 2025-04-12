#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l ,int  r, int mid){
    int *des=(int *)malloc(sizeof(int) * (r-l+1));
    if(!des){
        printf("HelpArray request failed\n");
        return ;
    }
    int p1=l, p2=mid+1;
    int i=0;    //des的下标
    while(p1<=mid && p2<=r){
        des[i++]= arr[p1]<arr[p2]?arr[p1++]:arr[p2++];
    }
    while(p1<=mid){
        des[i++]= arr[p1++];
    }
    while(p2<=r){
        des[i++]= arr[p2++];
    }
    for(int i=0; i <= r-l; i++){
        arr[l+i]= des[i];
    }
    free(des);
}

void mergeSort(int arr[],int l, int r){
    if(l == r){
        return ;
    }
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,r,mid);
}

int main(){
    int arr[]={3,5,6,35,24,56,23};
    int size=sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,size-1);

    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}