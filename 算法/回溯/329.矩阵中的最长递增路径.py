'''
问题: 为什么可以拓扑排序?

'''
from typing import List

coors = [(-1, 0), (1, 0), (0, 1), (0, -1)]


class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        if not matrix:
            return 0
        n = len(matrix)
        if n < 1:
            return 0
        m = len(matrix[0])
        if m < 1:
            return 0

        dp = [[0] * m for i in range(n)]  # 默认为0 表示未计算
        self.max_len = 1

        def dfs(i, j):
            '''
            i, j 是当前坐标， 在上一步保证合法
            '''
            if dp[i][j]:
                return

            dp[i][j] = 1
            for a, b in coors:
                next_i = i + a
                next_j = j + b
                if 0 <= next_i < n and 0 <= next_j < m and matrix[i][
                        j] < matrix[next_i][next_j]:  # 递增
                    dfs(next_i, next_j)
                    dp[i][j] = max(dp[i][j], dp[next_i][next_j] + 1)
            if dp[i][j] > self.max_len:
                self.max_len = dp[i][j]

        for i in range(n):
            for j in range(m):
                dfs(i, j)
        return self.max_len


def test():
    s = Solution()
    print(s.longestIncreasingPath([[1]]))


if __name__ == "__main__":
    test()