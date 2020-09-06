from typing import List


# 时间复杂度O(10^n)
class Solution:
    def printNumbers(self, n: int) -> List[int]:
        # 直接溢出 OverflowError: Python int too large to convert to C ssize_t
        # 数值太大了
        return list(range(1, 10**n))


# 有很多重复的地方
# class Solution:
#     def printNumbers(self, n: int) -> List[int]:
#         pass


def main():
    s = Solution()
    print(s.printNumbers(3))


if __name__ == "__main__":
    main()
