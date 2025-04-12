#include <stdio.h>

#define N 1000
typedef long long ll;

int n;
ll a[N];

ll abs_(ll a){
	return a > 0 ? a : -a;
}

ll min(ll a, ll b) {
	return a < b ? a : b;
}

void solve(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	
	//区间和 
	ll sum[N*N];
	ll start = 0;
	for(int i = 0; i < n; i++){
		ll temp = 0;
		for(int j = i; j < n; j++){
			temp += a[j];
			sum[start++] = temp;
		}
	}
	
    //后面就是错误的了：
	//求差值
	ll ans = (ll)1e18;
	for(int i = 1; i < start; i++){
		ans = min(ans, abs_(sum[i] - sum[i-1]));
	}
	printf("%lld", ans);
} 


int main() {
	solve();
	return 0;
}