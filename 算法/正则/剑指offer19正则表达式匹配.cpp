#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 递归实现, 比循环好, 因为*正则,有多种可能
    bool isMatch(string s, string p)
    {
        if (s.empty() && p.empty())
        {
            return true;
        }
        else if (!s.empty() && p.empty())
        {
            return false;
        }

        if (p.size() >= 2 && p[1] == '*')
        {
            if (s.empty()) // s为空但p不为空 也可以
            {
                return isMatch(s, p.substr(2));
            }
            else
            {
                if (isMatch(s, p.substr(2))) // * 0
                {
                    return true;
                }
                else if (s[0] == p[0] || p[0] == '.') // +
                {
                    return isMatch(s.substr(1), p);
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            if (s.empty())
            {
                return false;
            }
            if (s[0] == p[0] || p[0] == '.')
            {
                return isMatch(s.substr(1), p.substr(1));
            }
            else
            {
                return false;
            }
        }
    }
};
