//十五届省赛C/C++ B组   D: R格式
#include <stdio.h>
#include <string.h>

#define N 2000

int n;
char d[N];
int num[N];

void solve(){
	scanf("%d %s",&n ,&d);
	
	//反转字符串为整型并存储
	int len = strlen(d);
	int j = 0;	//num的下标 
	for(int i = len - 1; i >= 0; i--){
		if(d[i] == '.'){
			num[j++] = -1;
			continue;
		}
		num[j++] = d[i] - '0';
	}
	 
	for(int i = 0; i < n; i++){
		int jin = 0;
		int j = 0;
		for(j = 0; j < len; j++){
			if(num[j] == -1){
				continue;
			}
			num[j] = num[j] * 2 + jin;
			jin = num[j] / 10;
			num[j] %= 10;
		}
		if(jin > 0){
			len++;
			num[j] = jin;
		}
	}
	
	//四舍五入
	for(int i = 0; i < len; i++){
		if(num[i] == -1 && num[i-1] > 4){
			num[i+1]++;
		}	
		if(num[i] == 10){
			if(i == len - 1){
				len++;
			}
			num[i] = 0;
			num[i+1]++;
		}	
	} 
	
	//逆向输出 
	for(int i = len - 1; i >= 0 && num[i] != -1; i--){
		printf("%d",num[i]);
	}
}

int main(){
	solve();
	return 0;
}
