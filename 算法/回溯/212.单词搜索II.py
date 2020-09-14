'''
填字游戏

DFS + Trie  O(N2)


暴力法: O(M * N2)
'''

from typing import List


class Trie:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lookup = {}

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        tree = self.lookup
        for char in word:
            if char not in tree:
                tree[char] = {}
            tree = tree[char]
        tree['#'] = None

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        tree = self.lookup
        for char in word:
            if char not in tree:
                return False
            tree = tree[char]

        if '#' in tree:
            return True
        else:
            return False

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie
        that starts with the given prefix.
        """
        tree = self.lookup
        for char in prefix:
            if char not in tree:
                return False
            tree = tree[char]
        return True


coors = [(-1, 0), (1, 0), (0, 1), (0, -1)]


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        if not board or not board[0] or not words:
            return []
        # 字典树
        words = list(set(words))
        trie = Trie()
        for word in words:
            trie.insert(word)

        num_row = len(board)
        num_col = len(board[0])
        num_wrods = len(words)

        self.flag_find_all_words = False

        result_words = set()

        def legal(next_i, next_j, trie_node):
            return 0 <= next_i < num_row and 0 <= next_j < num_col and (
                board[next_i][next_j] in trie_node)

        # dfs
        def dfs(i, j, trie_node):
            '''
            i,j 在上一步已经保证合法
            '''
            if self.flag_find_all_words:
                return {}
            cur_res = set()
            if '#' in trie_node[board[i][j]]:
                cur_res.add(board[i][j])

            # 局部变量
            next_trie_node = trie_node[board[i][j]]
            origin_char = board[i][j]

            board[i][j] = '\0'  # 标记为已经访问过了
            for a, b in coors:
                next_i = i + a
                next_j = j + b

                if legal(next_i, next_j, next_trie_node):
                    tmp_res = dfs(next_i, next_j, next_trie_node)
                    tmp_res = {origin_char + _ for _ in tmp_res}
                    cur_res.update(tmp_res)

            board[i][j] = origin_char  # 回溯

            if len(cur_res) == num_wrods:
                self.flag_find_all_words = True
            return cur_res

        for i in range(num_row):
            for j in range(num_col):
                if board[i][j] in trie.lookup.keys():
                    s = dfs(i, j, trie.lookup)
                    result_words.update(s)
        res_list = list(result_words)
        res_list.sort()
        return res_list


def main():
    s = Solution()
    words = ["oath", "pea", "eat", "rain"]
    board = [['o', 'a', 'a', 'n'], ['e', 't', 'a', 'e'], ['i', 'h', 'k', 'r'],
             ['i', 'f', 'l', 'v']]
    res = s.findWords(board, words)
    print(res)


if __name__ == "__main__":
    main()
