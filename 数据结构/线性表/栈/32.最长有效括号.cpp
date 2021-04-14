#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.size() <= 1)
        {
            return 0;
        }

        // 当前是')' 时,才能计算长度,考虑下面2种情况
        //  (()
        //  )()
        // 从长远来说
        // ( ... (),
        // ) ... ()
        // 中间的如果匹配了, 其实已经消去了
        // 所以
        // 栈内是'(' 或上一个不匹配的')'的下标, 那么遇到s[i] == ')'时, 先弹栈, 然后 i-stk.top() 就是

        // 栈内是上一个不匹配的')'的下标
        stack<int> stk;
        stk.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                if (stk.empty())
                {
                    stk.push(i);
                }
                else
                {
                    stk.pop();
                    if (stk.empty())
                    {
                        stk.push(i);
                    }
                    else
                    {
                        maxLen = max(maxLen, i - stk.top());
                    }
                }
            }
        }
        return maxLen;
    };
};
int main()
{
    Solution s;
    string ss = "()(())";
    s.longestValidParentheses(ss);
    return 0;
}