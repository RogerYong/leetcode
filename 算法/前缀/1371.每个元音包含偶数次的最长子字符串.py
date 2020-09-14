# 前缀和: 用前缀和的差, 表示区间
# 状态压缩: 动态规划的进一步优化
'''
暴力做法: 
DP枚举每个子串的字母出现的个数, 
dp[i][j]表示[i,j]子字符串字母个数,
复杂度O(n2), 超时


思考: 有什么方法能不重复遍历子串的前提下, 快速求出这个区间的原因出现次数呢?

前缀和:

dp[i] 表示, 从0到i的字母个数

那么 [i,j]的字母个数 是 dp[j] - dp[i]

但是, 复杂度依然是O(n2)



因为dp[j] - dp[i] 的结果不一定是偶数的, 所以需要遍历?

怎么把遍历优化掉?

利用特性： 

偶数 = 奇数 - 奇数
偶数 = 偶数 - 偶数

那就通过hash, 把差恒等于偶数的, 放在一起. 避免冗余的遍历

5个字母, 奇偶性有, 2**5 =  32

因为只需要存储奇偶性, 不需要计数, 所以状态压缩成 [0,31]的整数, 


甚至hash还可以优化掉, 因为只需要知道相同奇偶性第一次出现和最后一次出现的index, 两个index相减就是最大长度, 

复杂度O(n)

'''


class Solution:
    def findTheLongestSubstring(self, s: str) -> int:
        '''
        优化内存
        '''
        if not s:
            return 0

        char_state = {
            'a': 0b10000,
            'e': 0b01000,
            'i': 0b00100,
            'o': 0b00010,
            'u': 0b00001
        }

        len_s = len(s)

        # 下面维护三个变量
        max_len = 0
        first_idx = [-1] * 32  # 各种奇偶性第一次出现的长度, 即idx+1
        first_idx[0] = 0  # state0 的状态很特殊, 第一次出现的长为0
        last_state = 0
        cur_state = 0

        for idx in range(len_s):
            cur_state = last_state ^ char_state.get(s[idx], 0)
            if first_idx[cur_state] != -1:
                max_len = max(max_len, idx + 1 - first_idx[cur_state])
            else:
                first_idx[cur_state] = idx + 1  # 所以这里要+1
            last_state = cur_state
        return max_len
