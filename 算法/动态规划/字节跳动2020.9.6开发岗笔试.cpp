/*
一个人跳楼梯，可以跳一格，可以跳两格，但不能连续两次都跳两格，问跳到n层有多少种方式。（0 <= n<= 100）

https://www.nowcoder.com/discuss/500713?type=2


解法:动态规划

dp[i][0/1] 表示跳带第i层, 的跳动是1/2格

dp[i][0]=dp[i−1][1]+dp[i−1][0]

dp[i][1]=dp[i−2][0]


结果:

dp[n][0] + dp[n][1]


初始化/边界条件

dp[0][0] = 1
dp[0][1] = 0

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  vector<vector<int64_t>> dp(105, vector<int64_t>(2, 0));
  dp[0][0] = 1;
  for (int i = 1; i < 105; i++)
  {
    dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
    if (i >= 2)
    {
      dp[i][1] = dp[i - 2][0];
    }
  }
  int n;
  cin >> n;
  if (n == 0)
  {
    cout << 0 << '\n';
    return 0;
  }
  cout << (dp[n][0] + dp[n][1]) << '\n';
}