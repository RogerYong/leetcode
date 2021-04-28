#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int m = num1.size(), n = num2.size();
        auto ansArr = vector<int>(m + n); // 两数相乘, 结果的位数必然是m+n+1 或 m+n
        // 先乘, 竖式乘法
        for (int i = m - 1; i >= 0; i--)
        {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--)
            {
                int y = num2.at(j) - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        // 处理每个位上的进位
        for (int i = m + n - 1; i > 0; i--)
        {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        // 判断位数是m+n还是m+n-1
        // 如果位数是m+n-1, 那么最高位必然是0
        // 如果位数是m+n,   那么最高位必然是1
        int index = ansArr[0] == 0 ? 1 : 0;
        // 结果转字符串
        string ans;
        while (index < m + n)
        {
            ans.push_back(ansArr[index] + '0');
            index++;
        }
        return ans;
    }
};