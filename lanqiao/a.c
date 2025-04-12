//十五届省赛C/C++  B组   E：宝石组合
#include <stdio.h>
#include <string.h>

#define N (int)(1e5 + 10)

int n;
int h[N];   //宝石亮度
int c[N];   //某亮度的宝石的数量
int ans[3]; //答案

void solve(){
	scanf("%d",&n);
	int maxh = -1;
	for(int i = 0; i < n; i++){
		scanf("%d",&h[i]);
		maxh = maxh > h[i] ? maxh : h[i];
		c[h[i]]++;
	}
	
	for(int i = maxh; i >= 0; i--){
		int k = 0;
		for(int j = i; j <= maxh; j += i){
			if(c[j]){
				for(int i = 0; i < c[j] && k < 3; i++){
					ans[k++] = j;
				} 
			}
			if(k == 3){
				break;
			}
		}
		if(k == 3){
			for(int i = 0; i < 3; i++){
				printf("%d ",ans[i]);
			}
			break;
		}
	}
}

int main(){
	solve();
	return 0;
} 
/*可以把 if(k==3) 的逻辑放在内层循环里，但通常不如原始写法清晰。
推荐保持原始写法（break 在内层循环，结果处理在外层循环），因为它分离了统计逻辑和输出逻辑，更易读和易维护。*/

int main(){
    solve();

    return 0;
}


------------------------------------------------------------------------------

宝石问题
#include <stdio.h>
#include <stdlib.h>

int n;
int dv[100010][100010];
int sizes[100010];

int main() {
    scanf("%d", &n);
    for (int i = 1, tmp; i <= n; i++) {
        scanf("%d", &tmp);
        for (int j = 1; j <= tmp / j; j++)
            if (tmp % j == 0) {
                dv[j][sizes[j]++] = tmp;
                if (j != tmp / j) dv[tmp / j][sizes[tmp / j]++] = tmp;
            }
    }

    for (int i = 100000; i >= 1; i--)
        if (sizes[i] >= 3) {
            qsort(dv[i], sizes[i], sizeof(int), (int (*)(const void *, const void *))strcmp);
            printf("%d %d %d", dv[i][0], dv[i][1], dv[i][2]);
            return 0;
        }

    return 0;
}

----------------------------------------------------------------------------------------------------------
宝石问题
#include <stdio.h>
#define MAX_SIZE 100001  
int main() {
    int n;
    scanf("%d", &n);
    int mp[MAX_SIZE] = {0};  
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        if (t < MAX_SIZE)   mp[t]++;
    }
    for (int i = MAX_SIZE - 1; i >= 1; i--) {
        int ans = 0;  
        int now = 0;  
        int num[3];  
        for (int j = i; j < MAX_SIZE; j += i) {
            ans += mp[j]; 
            for (int k = 0; k < mp[j] && now < 3; k++)    num[now++] = j;
            if (ans >= 3) { 
                for (int k = 0; k < 3; k++)   printf("%d ", num[k]);     
                printf("\n");
                return 0;  
            }
        }
    }
    return 0;
}