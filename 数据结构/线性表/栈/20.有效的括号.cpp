#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValid(string s)
    {
        string left = "([{";
        unordered_map<char, char> m = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
        };
        stack<char> stk;

        for (auto c : s)
        {
            if (left.find(c) != left.npos)
            {
                stk.push(c);
            }
            else
            {
                if (!stk.empty() && m[stk.top()] == c)
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};

int main()
{
    vector<string> vs = {
        "()",
        "()[]{}",
        "(]",
        "([)]",
        "{[]}",
    };
    Solution sl;
    for (auto s : vs)
    {
        cout << sl.isValid(s) << endl;
    }
}