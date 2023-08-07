# -*- coding:utf-8 -*-
class Solution:
    def __init__(self) -> None:
        self.ans = 0

    def Sum_Solution(self, n):
        # write code here

        n > 1 and self.Sum_Solution(n-1)

        self.ans += n

        return self.ans