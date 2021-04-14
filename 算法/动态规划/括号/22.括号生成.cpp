#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> table(n + 1, vector<string>());
        table[0].push_back("");
        table[1].push_back("()");
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (string s1 : table[j])
                {
                    for (string s2 : table[i - j - 1])
                    {
                        table[i].push_back("(" + s1 + ")" + s2);
                    }
                }
            }
        }
        return table[n];
    }
};
int main()
{
    Solution s;
    for (int i = 0; i <= 8; i++)
    {
    }
}