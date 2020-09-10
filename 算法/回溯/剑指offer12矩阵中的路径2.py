# DFS 是否存在路径
# 上下左右 四格
# 是否存在
from typing import List

coors = [(-1, 0), (1, 0), (0, 1), (0, -1)]


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not board or not word:
            return False

        # 全局变量
        num_row = len(board)
        num_col = len(board[0])
        vis = [[False] * num_col for i in range(num_row)]

        def legal(next_i, next_j, next_char_idx):
            if 0 <= next_i < num_row and 0 <= next_j < num_col and board[
                    next_i][next_j] == word[next_char_idx] and (
                        not vis[next_i][next_j]):
                return True
            else:
                return False

        def dfs(i, j, char_idx):
            '''
            i,j 在上一步已经保证合法
            '''
            if char_idx == len(word) - 1:
                return True
            # 局部变量
            next_char_idx = char_idx + 1

            vis[i][j] = True
            for a, b in coors:
                next_i = i + a
                next_j = j + b
                if legal(next_i, next_j, next_char_idx):
                    if dfs(next_i, next_j, next_char_idx):
                        return True
            vis[i][j] = False
            return False

        for i in range(num_row):
            for j in range(num_col):
                if (board[i][j] == word[0]):
                    if dfs(i, j, 0):
                        return True

        return False
