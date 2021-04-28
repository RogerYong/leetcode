// 2021/4/8 腾讯qq后台开发-存储组 一面 第2题
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
// 大数加法
string addStrings(string &num1, string &num2)
{
    int i = num1.size() - 1, j = num2.size() - 1, add = 0;
    string ans;
    while (i >= 0 || j >= 0 || add != 0) // 从个位开始
    {
        int x = i >= 0 ? num1.at(i) - '0' : 0;
        int y = j >= 0 ? num2.at(j) - '0' : 0;
        int result = x + y + add;
        ans.push_back(result % 10);
        add = result / 10;
        i--;
        j--;
    }
    reverse(ans.begin(), ans.end()); // 从个位开始，翻转
    for (auto &c : ans)
    {
        c += '0';
    }
    return ans;
}
// 大数乘法
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

int hex2int(char h)
{
    if (h >= '0' && h <= '9')
    {
        return h - '0';
    }
    else if (h >= 'a' && h <= 'f')
    {
        return h - 'a' + 10;
    }
}

int main()
{
    string s; // 16进制

    getline(cin, s);
    if (s.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    // 去前面的0
    int i = 0;
    while (i < s.size() && s[i] == '0')
    {
        i++;
    }
    if (i == s.size()) // 全是0
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        s = s.substr(i);
        // cout << s << endl;
    }

    // s转小写
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    string ans = "0";      // 十进制
    string sixteen = "16"; // 十进制

    i = 0;

    for (; i < s.size(); i++)
    {
        // ans = ans * 16 + s[i]
        string m = multiply(ans, sixteen);
        string a = to_string(hex2int(s[i])); // 十进制字符串
        ans = addStrings(m, a);
    }
    cout << ans << endl;

    return 0;
}