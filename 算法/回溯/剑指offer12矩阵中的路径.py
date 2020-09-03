# DFS
# 上下左右 四格
from typing import List

coor = [[-1, 0], [1, 0], [0, -1], [0, 1]]


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:

        if not board or not word:
            return False

        start_coors = []
        num_row = len(board)
        num_col = len(board[0])

        vis = [[False] * num_col for i in range(num_row)]

        for i in range(num_row):
            for j in range(num_col):
                if board[i][j] == word[0]:
                    start_coors.append((i, j))

        for i, j in start_coors:
            vis[i][j] = True
            result = self.dfs(board, word, vis, i, j)
            vis[i][j] = False
            if result:
                return True

        return False

    def dfs(self, board, word, vis, i, j):
        if not word:
            return False
        num_row = len(board)
        num_col = len(board[0])

        if board[i][j] == word[0]:
            if len(word) == 1:
                return True
            next_word = word[1:]

            for c in coor:
                next_i = i + c[0]
                next_j = j + c[1]
                if next_i >= 0 and next_i < num_row and next_j >= 0 and next_j < num_col and (
                        not vis[next_i][next_j]
                ) and board[next_i][next_j] == next_word[0]:

                    vis[next_i][next_j] = True
                    res = self.dfs(board, next_word, vis, next_i, next_j)
                    vis[next_i][next_j] = False
                    if res:
                        return res
            return False
        else:
            return False
