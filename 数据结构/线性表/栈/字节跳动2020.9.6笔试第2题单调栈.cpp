/*
对于一个有N个元素的数组，包含a1，a2，a3……an，定义如下两个函数：

从1开始

L(i) = j
max j < i, a[j]  > a[i]. a[i]左边第一个大于它的数的下标(从1开始). (多个j,取离i最近的那个)

R(i) = j
min j > i, a[j]  > a[i]. a[i]右边第一个大于它的数的下标(从1开始). (多个j,取离i最近的那个)


求最大 L(i) * R(j)
*/

#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int64_t ans = 0;
    vector<int> a(n), l(n);
    stack<int> stk;
    // 单调栈求L[i]
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        while (!stk.empty() && a[stk.top()] <= a[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            l[i] = stk.top() + 1;
        }
        stk.push(i);
    }
    while (!stk.empty())
    {
        stk.pop();
    }
    //另一个单调栈求R[i]
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && a[stk.top()] <= a[i])
        {
            stk.pop();
        }
        if (!stk.empty())
        {
            ans = max(ans, (int64_t)(1ll * l[i] * (stk.top() + 1)));
        }
        stk.push(i);
    }
    cout << ans << endl;
}
