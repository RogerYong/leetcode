'''
https://www.cnblogs.com/imwtr/p/4069543.html



思路:

斐波那契

假如dp[i] 是长为i的不含11的01串个数

dp[i] = dp[i-1] + dp[i-2]

dp[i-1] 表示 最高位是0的个数
dp[i-2] 表示 最高位是1的个数

'''