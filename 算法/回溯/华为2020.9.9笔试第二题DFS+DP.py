coors = [(-1, 0), (1, 0), (0, 1), (0, -1)]


def solve(grid, n, m):
    '''
    grid 岛
    n 行
    m 列
    '''
    # dp[i][j] 表示从[i][j]开始的最长路径
    dp = [[0] * m for i in range(n)]  # 默认为0 表示未计算

    def dfs(i, j):
        '''
        i, j 是当前坐标， 在上一步保证合法
        '''
        if dp[i][j]:
            return
        dp[i][j] = 1
        global max_len
        for a, b in coors:
            next_i = i + a
            next_j = j + b
            if 0 <= next_i < n and 0 <= next_j < m and grid[i][j] > grid[
                    next_i][next_j]:
                dfs(next_i, next_j)
                dp[i][j] = max(dp[i][j], dp[next_i][next_j] + 1)
        if dp[i][j] > max_len:
            max_len = dp[i][j]

    for i in range(n):
        for j in range(m):
            dfs(i, j)


# 会超时, 使用DP优化

# 输入
# n 行 m 列
n, m = [int(_) for _ in input().strip().split()]
grid = []
for i in range(n):
    row = [int(_) for _ in input().strip().split()]
    grid.append(row)
max_len = 1
solve(grid, n, m)
print(max_len)
'''
测试样例
输入
2 3
6 3 1
5 4 2

输出
5
'''