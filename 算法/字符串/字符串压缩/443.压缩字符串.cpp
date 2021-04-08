#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int len = 0;
        int i = 0;
        int j;
        while (i < chars.size())
        {
            if (i + 1 < chars.size() && chars[i] == chars[i + 1]) // 找到重复区间
            {
                j = i + 1;
                while (j < chars.size() && chars[j] == chars[i]) // 找到重复字符串的区间
                {
                    j++;
                }
                // [i, j)
                string tmp_len = to_string(j - i);
                chars[len++] = chars[i];
                for (auto &c : tmp_len)
                {
                    chars[len++] = c;
                }

                i = j;
            }
            else
            {
                chars[len++] = chars[i++];
            }
        }
        return len;
    }
};