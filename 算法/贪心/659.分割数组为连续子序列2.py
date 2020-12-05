'''
解法2: 贪心法, 分解法


'''
from typing import List


class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        if not nums or len(nums) < 3:
            return False

        num_to_cnt = dict()
        endwith = dict()  # 以key结尾的合法的子序列(长>=3)

        for num in nums:
            cnt = num_to_cnt.get(num, 0)
            cnt += 1
            num_to_cnt[num] = cnt

        for num in nums:
            if num_to_cnt[num] > 0:
                m1 = num - 1
                p1, p2 = num + 1, num + 2

                if endwith.get(m1, 0) > 0:
                    endwith_m1 = endwith.get(m1)
                    endwith_m1 -= 1
                    endwith[m1] = endwith_m1

                    endwith_num = endwith.get(num, 0)
                    endwith_num += 1
                    endwith[num] = endwith_num

                    num_to_cnt[num] -= 1
                else:
                    if num_to_cnt.get(p1, 0) > 0 and num_to_cnt.get(p2, 0) > 0:
                        endwith_p2 = endwith.get(p2, 0)
                        endwith_p2 += 1
                        endwith[p2] = endwith_p2

                        num_to_cnt[num] -= 1
                        num_to_cnt[p1] -= 1
                        num_to_cnt[p2] -= 1
                    else:
                        return False
        return True


if __name__ == "__main__":
    s = Solution()

    cases = [([1, 2, 3, 3, 4, 5], True), ([1, 2, 3, 3, 4, 4, 5, 5], True),
             ([1, 2, 3, 4, 4, 5], False)]

    for c, re in cases:
        res = s.isPossible(c)
        print('{}{}{}'.format(re, '==' if re == res else '!=', res))
