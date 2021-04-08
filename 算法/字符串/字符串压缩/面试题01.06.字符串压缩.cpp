#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string compressString(string S)
    {
        if (S.size() == 0)
        {
            return S;
        }

        string ans = "";
        char last_char = S[0];
        int cnt = 1;
        for (int i = 1; i < S.size(); i++)
        {
            if (S[i] == last_char)
            {
                cnt++;
            }
            else
            {
                ans += last_char + to_string(cnt);
                last_char = S[i];
                cnt = 1;
            }
        }
        ans += last_char + to_string(cnt);

        return ans.length() >= S.length() ? S : ans;
    }
};