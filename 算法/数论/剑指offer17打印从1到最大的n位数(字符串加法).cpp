#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    string nine;
    bool increament(string &s)
    {
        int s_len = s.size();
        // 判断是否边界

        if (s == nine)
        {
            return false;
        }

        int add_idx = s_len - 1;

        int ans;

        while (add_idx >= 0)
        {
            ans = s[add_idx] + 1;
            if (ans > '9')
            {
                s[add_idx] = ans - 10;
                add_idx--;
            }
            else
            {
                s[add_idx] = ans;
                return true;
            }
        }
        return true;
    }
    vector<int> printNumbers(int n)
    {
        nine = string(n, '9');
        vector<int> v;
        if (n <= 0)
        {
            return v;
        }

        string buffer(n, '0');

        while (increament(buffer))
        {
            v.push_back(stoi(buffer));
        }
        return v;
    }
};
int main()
{
    Solution s;
    vector<int> v = s.printNumbers(3);
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
}