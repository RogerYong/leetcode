# python中没有无符号整数的概念


class Solution:
    def hammingWeight(self, n: int) -> int:
        flag = 1  # 用flag左移
        cnt = 0
        max_flag = 1 << 32
        # python中的整数可以超出32位的

        while flag < max_flag:
            if n & flag:
                cnt += 1
            flag = flag << 1

        return cnt


def main():
    a = 0b00000000000000000000000000001011
    s = Solution()
    res = s.hammingWeight(a)
    print(res)


if __name__ == "__main__":
    main()
