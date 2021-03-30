// 九宫格拼音输入法
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return {};
        }
        vector<string> res;
        vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        res.push_back(""); // 初始化
        for (char digit : digits)
        {
            vector<string> tmp;
            for (string s : res) // res: 上一轮的结果
            {
                for (char c : table[digit - '0'])
                {
                    tmp.push_back(s + c);
                }
            }
            res.swap(tmp);
        }
        return res;
    }
};