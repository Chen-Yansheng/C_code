/*大部分使用排序的题解都有点欠缺：排序之后差值最小的两个子数组一定是相邻的，但是忽略了子数组相交的情况 
例如1，3，6：代码跑出来可能是1，实际应该是{1，3}，{6}，差值为2。这就是忽略了子数组相交的可能*/
#include <stdio.h>

#define N 1000
typedef long long ll;

//想不到其他防止重叠的方法，只能写个结构体了 
typedef struct{
    ll sum;
    int l;
    int r;
} sa;    //subarray

int n;
ll a[N];

ll abs_(ll a){
    return a > 0 ? a : -a;
}

ll min(ll a, ll b) {
    return a < b ? a : b;
}

int cmp(const void *a, const void *b){
    ll x = ((sa *)a) -> sum;    //不能是(sa *)a。不能是*(const ll *)a，因为这是针对long long类型数据的 
    ll y = ((sa *)b) -> sum;
    return (x > y) - (x < y);     //升序 
}    

void solve(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    //存储子数组的和，边界 
    sa sub[N*N];    
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        ll temp = 0;
        for(int j = i; j < n; j++){
            temp += a[j];
            sub[cnt].sum = temp;
            sub[cnt].l = i;
            sub[cnt].r = j;
            cnt++;
        }
    }
    
    //快排 
    qsort(sub, cnt, sizeof(sa), cmp);
    
    ll ans = (ll)1e18;
    for(int i = 0; i < cnt; i++){
        for(int j = i + 1; j < cnt; j++){
            if((sub[j].sum - sub[i].sum) >= ans) break;    //因为数组有序，如果>=，那后面只会越差越大 
            
            if(sub[i].l > sub[j].r || sub[i].r < sub[j].l){
                ans = min(ans, abs_(sub[i].sum - sub[j].sum));
                if(ans == 0) break;
            }
        }
        if(ans == 0) break;
    }
    printf("%lld", ans);
} 


int main() {
    solve();
    return 0;
}