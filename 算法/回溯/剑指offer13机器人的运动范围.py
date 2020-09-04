def decimal_digit_sum(x):
    digits = []
    while x > 0:
        yushu = x % 10
        shang = x // 10

        digits.append(yushu)
        x = shang
    sum = 0
    for i in digits:
        sum += i

    return sum


def legal(i, j, k):
    return decimal_digit_sum(i) + decimal_digit_sum(j) <= k


class Solution:
    def movingCount(self, m: int, n: int, k: int) -> int:
        vis = [[False] * n for i in range(m)]

        def dfs(i, j):
            if 0 <= i < m and 0 <= j < n and legal(i, j,
                                                   k) and (not vis[i][j]):

                vis[i][j] = True
                res = 1 + dfs(i - 1, j) + dfs(i + 1, j) + dfs(i, j - 1) + dfs(
                    i, j + 1)
                # vis[i][j] = False # 找所有能到达的地方, 有点像并查集, 而不是求最长路径, 因此不需要 回溯False
                return res
            else:
                return 0

        res = dfs(0, 0)
        return res
