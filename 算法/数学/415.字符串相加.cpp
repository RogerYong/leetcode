#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        if (num1 == "0")
        {
            return num2;
        }
        if (num2 == "0")
        {
            return num1;
        }
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1; // 双指针
        string ans = "";
        while (i >= 0 || j >= 0 || carry > 0)
        {
            int a = (i >= 0 ? num1[i] - '0' : 0);
            int b = (j >= 0 ? num2[j] - '0' : 0);
            int sum = a + b + carry;
            carry = sum / 10;
            ans.push_back(sum % 10 + '0'); // 逆序的
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};