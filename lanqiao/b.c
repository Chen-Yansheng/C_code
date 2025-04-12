//十五届省赛python B组      B:  数字串个数
#include <stdio.h>

typedef long long ll;

#define N 10000
#define MOD ((ll)1e9 + 7)//记得加括号   如果不加: ll x = 2*MOD -> 2*1e9 + 7

ll apow(ll a, ll b){
    ll res = 1;
    for(ll i = 0; i < b; i ++){
        res = (res * a) % MOD;
    }
    return res;
}

void solve(){
    ll a1 = apow(9, N);
    ll a2 = apow(8, N) * 2 % MOD;
    ll a3 = apow(7, N);
    ll ans = ((a1 - a2 + a3) % MOD + MOD) % MOD;
    printf("%lld\n", ans);
}
int main(){
    solve();
    return 0;
}





// git pull 拉取
//git add . 暂存文件
//git commit -m  提交事件
//git push 推送到远程仓库