#include <vector>
using namespace std;
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        vector<int> digits;
        int mod = 0;
        while (x > 0)
        {
            mod = x % 10;
            x /= 10;

            digits.push_back(mod);
        }
        if (digits.size() > 0)
        {
            for (int i = 0; i <= digits.size() / 2; i++)
            {
                if (digits[i] != digits[digits.size() - 1 - i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};