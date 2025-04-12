//暴力

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


void solve() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}	

	//前缀和 
	ll sum[N] = { 0 };
	sum[0] = a[0];
	for (int i = 1; i < n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}

	ll ans = (ll)1e18;
	for (int l1 = 0; l1 < n;  l1++) {
		for (int r1 = l1; r1 < n; r1++) {
			ll sum1 = sum[r1] - (l1 > 0 ? sum[l1-1] : 0);
			for (int l2 = r1 + 1; l2 < n; l2++) {
				for (int r2 = l2; r2 < n; r2++) {
					ll sum2 = sum[r2] - (l2 > 0 ? sum[l2-1] : 0);
					ans = min(ans, abs_(sum1 - sum2));
				}
			}
		}
	}
	printf("%lld\n", ans);
}


/*优化思路：1.减少枚举的维度（如用双指针或数学性质优化）。
			2.预处理更多信息（如所有可能的子数组和，再比较）。
			3.剪枝：在内层循环中，如果当前差值已经大于 ans，可以提前跳出循环。 */
