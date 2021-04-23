#include <string>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {

        string s = "1";
        for (int i = 1; i < n; i++)
        {
            s = compressStr(s);
        }
        return s;
    }

    string compressStr(string s)
    {
        string ans = "";
        int i = 0;
        while (i < s.size())
        {
            if (i + 1 < s.size() && s[i] == s[i + 1])
            {
                // 找一个连续的区间
                int j = i + 1; // 找到区间的右侧
                while (j < s.size() && s[j] == s[i])
                {
                    j++;
                }
                // [i, j)
                ans += to_string(j - i);
                ans += s[i];
                i = j;
            }
            else
            {
                ans += "1";
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};