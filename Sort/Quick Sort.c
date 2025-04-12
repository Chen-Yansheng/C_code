#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int n;
int arr[N];

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void patition(int arr[], int l, int r, int *ll, int *rr){
    *ll = l;
    *rr = r;
    int pivot = arr[rand() % (r-l+1) + l];
    for(int i = l; i <= *rr;){  //不是i<=r
        if(arr[i] < pivot)
            swap(arr, (*ll)++, i++);
        else if(arr[i] > pivot)
            swap(arr, (*rr)--, i);
        else
            i++;
    }
}

void quicksort(int arr[], int l, int r){
    if(l >= r)  return;

    int ll, rr;
    patition(arr, l, r, &ll, &rr);
    quicksort(arr, l, ll-1);
    quicksort(arr, rr+1, r);
}

void solve(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    srand(time(NULL));  //在main函数里设置一次随机种子就行了
    solve();
    return 0;
}