/*2020 年春节期间，有一个特殊的日期引起了大家的注意：2020 年 2 月 2 日。因为如果将这个日期按 “yyyymmdd” 的格式写成一个 8 位数是 20200202，恰好是一个回文数。我们称这样的日期是回文日期。

有人表示 20200202 是 “千年一遇” 的特殊日子。对此小明很不认同，因为不到 2 年之后就是下一个回文日期：20211202 即 2021 年 12 月 2 日。

也有人表示 20200202 并不仅仅是一个回文日期，还是一个 ABABBABA 型的回文日期。对此小明也不认同，因为大约 100 年后就能遇到下一个 ABABBABA 型的回文日期：21211212 即 2121 年 12 月 12 日。算不上 “千年一遇”，顶多算 “千年两遇”。

给定一个 8 位数的日期，请你计算该日期之后下一个回文日期和下一个 ABABBABA 型的回文日期各是哪一天。*/

#include <stdio.h>
#include <stdbool.h>

int days[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool IsLeap(int year){
    return (year%4 == 0 && year%100 != 0) || year%400 == 0;
}

int main(){
    long long data;
    scanf("%lld",&data);

    long long ans1=0, ans2=0;   
    int year=data/10000, month=data%10000/100, day=data%100;

    for(; year <= 9999; year++){
        int tmonth = year%10*10 + year%100/10;
        int tday = year%1000/100*10 + year/1000;

        if(tmonth < 1 || tmonth > 12)
            continue;
        days[2] = IsLeap(year)?29:28;
        if(tday < 1 || tday > days[tmonth])
            continue;
        ans1 = year*10000 + tmonth*100 + tday;
        if(ans1 <= data)
            continue;
        else    break;
    }

    int a = year/100, b = year%100;
    for(; year <= 9999; year+=a>b?1:100){
        a = year/100, b = year%100;
        int tyear = a>b? b*100+b: a*100+a;
        int tmonth = tyear%10*10 + tyear%100/10;
        int tday = tyear%1000/100*10 + tyear/1000;

        if(tmonth < 1 || tmonth > 12)
            continue;
        days[2] = IsLeap(year)?29:28;
        if(tday < 1 || tday > days[tmonth])
            continue;
        ans2 = tyear*10000 + tmonth*100 + tday;
        if(ans2 <= data)
            continue;
        else    break;
    }

    printf("%lld\n%lld\n",ans1, ans2);
    return 0;
}

/*
#include <iostream>
using namespace std;
bool isleap(int y) {//判断闰年
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);//闰年可以被4整除但不能被100整除，或能被400整除。
}
bool check(int year, int mouth, int day) {//判断日期是否合法
    if (mouth > 12 || mouth == 0)return false;
    if (day > 31)return false;
    if (mouth == 2) {
        if (isleap(year) && day > 29)
            return false;
        if (!isleap(year) && day > 28)
            return false;
    }
    if (mouth == 4 || mouth == 6 || mouth == 9 || mouth == 11)
        if (day > 30)return false;
    return true;
}
int main()
{
    int n, i;
    cin >> n;
    int a, b, c, d, e, f, g, h;
    int year, mouth, day;
    bool flag = false;
    for (i = n + 1;i <= 99999999;++i) {
        year = i / 10000;
        mouth = i % 10000 / 100;
        day = i % 100;
        a = i % 10;//得到个位
        b = i / 10 % 10;//十位
        c = i / 100 % 10;//百位
        d = i / 1000 % 10;//千位
        e = i / 10000 % 10;//万位
        f = i / 100000 % 10;//十万位
        g = i / 1000000 % 10;//百万位
        h = i / 10000000 % 10;//千万位
        if (a == h && c == f && b == g && e == d && flag == false) {//该部分目的是输出第一个回文日期，flag作为标记。
        //当找到第一个回文日期之后，将flag变为ture。这样下一次碰到普通回文日期时就不会输出。
            if (check(year, mouth, day)) {
                cout << i << endl;
                flag = true;
            }
        }
        if (a == h && c == f && b == g && e == d && a == c && b == e) {//输出ABABBABA型的回文日期
            if (check(year, mouth, day)) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
*/