#include <bits/stdc++.h>

using namespace std;

// 下面是KMP算法

// 获得next数组的函数

void get_next(const string &pat, vector<int> &next)
{
    int len_pat = pat.size();

    next.assign(len_pat + 1, 0); // 默认都转移到0

    next[0] = -1;
    int k = -1;
    int j = 0;

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
                next[j] = next[k];
            }
        }
        else
        {
            k = next[k];
        }
    }
}

// 存在返回下标
// 不存在返回-1
int kmp_search(const string &s, const string &pat)
{
    vector<int> next;
    get_next(pat, next);

    int len_str = s.size();
    int len_pat = pat.size();

    int i = 0, j = 0;
    while (i < len_str && j < len_pat)
    {
        if (j == -1 || s[i] == pat[j])
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