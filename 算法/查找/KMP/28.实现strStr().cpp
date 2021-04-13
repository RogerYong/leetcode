#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void get_next(const string &pat, vector<int> &next)
    {
        int len_pat = pat.size();

        next.assign(len_pat + 1, 0); // 默认都转移到0

        next[0] = -1; // 0转移到-1, 表示 i++, j++
        int k = -1;   // 前缀指针
        int j = 0;    // 后缀指针

        while (j < len_pat - 1)
        {
            if (k == -1 || pat[j] == pat[k])
            {
                ++k;
                ++j;
                if (pat[j] != pat[k])
                {
                    next[j] = k;
                }
                else
                {
                    next[j] = next[k]; // 前缀与后缀的公共子序列
                }
            }
            else
            {
                k = next[k];
            }
        }
    }
    int strStr(string haystack, string needle)
    {
        vector<int> next;
        get_next(needle, next);

        int len_str = haystack.size();
        int len_pat = needle.size();

        int i = 0, j = 0;
        while (i < len_str && j < len_pat)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }

        if (j == len_pat)
        {
            return i - len_pat;
        }
        else
        {
            return -1;
        }
    }
};