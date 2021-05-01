#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string strSort(string &s)
    {
        string res = "";
        map<char, int> cnt;
        for (char c : s)
        {
            cnt[c]++;
        }
        for (auto it = cnt.begin(); it != cnt.end(); it++)
        {
            res += string(it->second, it->first);
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        map<string, vector<string>> m;
        for (string &s : strs)
        {
            string ss = strSort(s);
            if (m.find(ss) == m.end())
            {
                m[ss] = vector<string>();
            }
            m[ss].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            ans.push_back(it->second);
        }
        return ans;
    }
};