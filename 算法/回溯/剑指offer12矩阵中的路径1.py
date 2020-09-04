# DFS
# 上下左右 四格
from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not word:
            return False

        num_row = len(board)
        num_col = len(board[0])

        vis = [[False] * num_col for i in range(num_row)]

        def dfs(i, j, char_idx):
            if 0 <= i < num_row and 0 <= j < num_col and board[i][j] == word[
                    char_idx] and (not vis[i][j]):  # 合法性判断
                if char_idx == len(word) - 1:
                    return True
                else:
                    vis[i][j] = True
                    res = dfs(i - 1, j, char_idx + 1) or dfs(
                        i + 1, j, char_idx + 1) or dfs(
                            i, j - 1, char_idx + 1) or dfs(
                                i, j + 1, char_idx + 1)
                    vis[i][j] = False
                    return res
            else:
                return False

        for i in range(num_row):
            for j in range(num_col):
                if dfs(i, j, 0):
                    return True

        return False
