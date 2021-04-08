#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int expand(const string &s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }

    string longestPalindrome(string s)
    {
        // 填充其他符号, 把长度为奇数/偶数的字符串统一
        int start = 0, end = -1; // 最长子串的左右idx
        string t = "#";
        for (char c : s)
        {
            t += c;
            t += '#';
        }
        t += '#';
        s = t;

        vector<int> arm_len; // 所有位置上的半径
        int right = -1;      // 最右回文子串的右边idx
        int j = -1;          // 最右回文子串的中点idx
        for (int i = 0; i < s.size(); ++i)
        {
            int cur_arm_len;
            if (right >= i) // 当前字符,在最右回文子串的右边
            {
                int i_sym = j * 2 - i;                            // 对称点的下标
                int min_arm_len = min(arm_len[i_sym], right - i); // 可以省略的计算
                cur_arm_len = expand(s, i - min_arm_len, i + min_arm_len);
            }
            else
            {
                cur_arm_len = expand(s, i, i);
            }
            arm_len.push_back(cur_arm_len); // 保存arm
            if (i + cur_arm_len > right)    // 维护right 和 j
            {
                j = i;
                right = i + cur_arm_len;
            }
            if (cur_arm_len * 2 + 1 > end - start) // 维护最长子串
            {
                start = i - cur_arm_len;
                end = i + cur_arm_len;
            }
        }
        // 构造结果
        string ans;
        for (int i = start; i <= end; ++i)
        {
            if (s[i] != '#')
            {
                ans += s[i];
            }
        }
        return ans;
    }
};