#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char d[100];
    int a[200] = {0};
    int size = 0;
    scanf("%d %s", &n, d);
    // 将d存入a
    for (int i = 0; i < strlen(d); i++)
    {
        // 遇到小数点，存为-1
        if (d[i] == '.')
            a[size++] = -1;
        else
            a[size++] = d[i] - '0';
    }
    // 乘n次2
    while (n--)
    {
        // 进位
        int c = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            if (a[i] != -1)
            {
                a[i] = a[i] * 2 + c;
                c = a[i] / 10;
                a[i] %= 10;
            }
        }
        // 首位进位
        if (c)
            for (int j = size; j >= 0; j--)
                a[j + 1] = a[j];
            a[0] = c;
            size++;
    }
    // 四舍五入并输出
    for (int i = 0; i < size; i++)
    {
        // 遇到小数点结束
        if (a[i] == -1)
            break;
        // 小数点前一位四舍五入
        if (a[i + 1] == -1 && a[i + 2] > 4)
            a[i]++;
        printf("%d", a[i]);
    }
    return 0;
}

----------------------------------------------------------------------------------------------------------

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