#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    enum State
    {
        STATE_START,
        STATE_SIGN,
        STATE_NUMBER,
        STATE_END,
    };

    enum CharType
    {
        CHAR_SPACE,
        CHAR_SIGN,
        CHAR_NUMBER,
        CHAR_OTHER,
    };
    CharType toCharType(char ch)
    {
        if (ch == ' ')
        {
            return CHAR_SPACE;
        }
        else if (ch == '+' || ch == '-')
        {
            return CHAR_SIGN;
        }
        else if (ch >= '0' && ch <= '9')
        {
            return CHAR_NUMBER;
        }

        else
        {
            return CHAR_OTHER;
        }
    }
    int myAtoi(string s)
    {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_START,
             {
                 {CHAR_SPACE, STATE_START},
                 {CHAR_SIGN, STATE_SIGN},
                 {CHAR_NUMBER, STATE_NUMBER},
                 {CHAR_OTHER, STATE_END},

             }},
            {STATE_SIGN,
             {
                 {CHAR_SPACE, STATE_END},
                 {CHAR_SIGN, STATE_END},
                 {CHAR_NUMBER, STATE_NUMBER},
                 {CHAR_OTHER, STATE_END},
             }},
            {STATE_NUMBER,
             {
                 {CHAR_SPACE, STATE_END},
                 {CHAR_SIGN, STATE_END},
                 {CHAR_NUMBER, STATE_NUMBER},
                 {CHAR_OTHER, STATE_END},
             }},
            {STATE_END,
             {
                 {CHAR_SPACE, STATE_END},
                 {CHAR_SIGN, STATE_END},
                 {CHAR_NUMBER, STATE_END},
                 {CHAR_OTHER, STATE_END},
             }}};

        int res = 0;
        int sign = 1; // 符号默认为+
        State state = STATE_START;

        for (int i = 0; i < s.size(); i++)
        {
            CharType ct = toCharType(s[i]);

            state = transfer[state][ct];

            if (state == STATE_SIGN)
            {
                sign = (s[i] == '+' ? 1 : -1);
            }
            else if (state == STATE_NUMBER)
            {
                int tmp_num = sign * (s[i] - '0');

                if (res > 214748364 || (res == 214748364 && tmp_num >= 7))
                {
                    return 2147483647;
                }
                if (res < -214748364 || (res == -214748364 && tmp_num <= -8))
                {
                    return -2147483648;
                }
                res = res * 10 + tmp_num;
            }
            else if (state == STATE_END)
            {
                break;
            }
        }
        return res;
    }
};
int main()
{
    vector<string> cases = {"   -42", "-91283472332"};
    Solution so = Solution();
    for (auto s : cases)
    {
        cout << so.myAtoi(s) << endl;
    }
    return 0;
}