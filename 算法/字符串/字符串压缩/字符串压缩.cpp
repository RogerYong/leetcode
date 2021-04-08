// aaabbb => a3b3
// 如果压缩后的长度 >= 原字符串长度, 返回原字符串

// 如果把 abc 变成 a1b1c1, 会导致变长
// 把aabbcc 变成 a2b2c2, 保持不变

// https://leetcode-cn.com/problems/compress-string-lcci/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s;

    getline(cin, s);
    if (s.size() == 0)
    {
        cout << s << endl;
        return 0;
    }
    // 新建一个字符串, 保存结果
    string ans = "";
    int i = 0;
    while (i < s.size())
    {
        if (i + 1 < s.size() && s[i] == s[i + 1]) // 找到重复区间
        {
            int j = i + 1;
            while (j < s.size() && s[j] == s[i]) // 找到重复字符串的区间
            {
                j++;
            }
            // [i, j)
            string l = to_string(j - i);
            ans.push_back(s[i]);
            ans += l;

            i = j;
        }
        else
        {
            ans.push_back(s[i]);
            ans += "1";
            i++;
        }
    }

    if (ans.size() >= s.size())
    {
        cout << s << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}