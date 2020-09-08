/*
输入
T组测试用例

一元n次函数
n+1 个系数


n范围 [1,5]
系数 范围[0,10]
解范围[-20, 20]


方法: 牛顿法

x1 < x2,f(x1) * f(x2) < 0,则x1 x2直接有解

那么对-20 到 20之间 直接遍历每个区间即可

保留两位小数? 

*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n, ans = 0;
double a[10];

// 这里最多5次, 没必要秦九韶
double f(double x)
{
    double now = 1, num = 0;
    for (int j = 0; j <= n; j++)
    {
        num += now * a[j];
        now *= x;
    }
    return num;
}
int main()
{
    scanf("%d", &n);
    for (int i = n; i >= 0; i--)
    {
        scanf("%lf", &a[i]);
    }
    for (double i = -20.000; i <= 20.000; i += 0.001)
    {
        // 问题: 驻点怎么办?
        if (f(i) * f(i + 0.001) < 0 || f(i) == 0)
        {
            ans = 1;
            printf("%.2lf ", i);
        }
    }
    if (!ans)
    {
        printf("No");
    }
    return 0;
}
