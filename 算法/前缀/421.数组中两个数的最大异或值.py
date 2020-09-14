'''

暴力解法O(n2)


优化: hash前缀树 O(n)

a ^ b = max

max 就是 前缀的1越多越好

那么我们可以根据前缀把数据划分成树

对每一个数, 在前缀树中找前缀互补的另一个数
'''
from typing import List


class Trie:
    '''
    01前缀树
    '''
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lookup = {}

    def insert(self, word) -> None:
        """
        Inserts a word into the trie.
        """
        tree = self.lookup
        for a in word:
            if a not in tree:
                tree[a] = {}
            tree = tree[a]
        # 单词结束标志
        # tree["#"] = "#"
        # 固定L层, 所以就不用#了

    def get_max_xor(self, word):
        tree = self.lookup
        curr_xor = 0  # 最大异或值
        for bit in word:
            opp_bit = 1 - bit
            if opp_bit in tree:
                # 找到互补的bit, 异或的1, 在结果后添加1, 即左移1位再或1
                curr_xor = (curr_xor << 1) | 1
                tree = tree[opp_bit]
            else:
                # 两位相同, 异或得0, 在结果后添加0, 即左移1位
                curr_xor = curr_xor << 1
                tree = tree[bit]
        return curr_xor


class Solution:
    def findMaximumXOR(self, nums: List[int]) -> int:
        if not nums:
            return 0
        L = len(bin(max(nums))) - 2  # 最大值的二进制位数

        # 把nums转成长为L的bin, 左边补0
        nums_bin = [[(num >> i) & 1 for i in range(L - 1, -1, -1)]
                    for num in nums]

        # 构建前缀树, 深度L
        trie = Trie()
        for num in nums_bin:
            trie.insert(num)

        # 遍历每个数, 在前缀树中找最大异或值
        max_xor = 0
        for num in nums_bin:
            tmp_max = trie.get_max_xor(num)
            max_xor = max(max_xor, tmp_max)

        return max_xor