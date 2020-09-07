#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    enum State
    {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END,
    };

    enum CharType
    {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL,
    };

    CharType toCharType(char ch)
    {
        if (ch >= '0' && ch <= '9')
        {
            return CHAR_NUMBER;
        }
        else if (ch == 'e' || ch == 'E')
        {
            return CHAR_EXP;
        }
        else if (ch == '.')
        {
            return CHAR_POINT;
        }
        else if (ch == '+' || ch == '-')
        {
            return CHAR_SIGN;
        }
        else if (ch == ' ')
        {
            return CHAR_SPACE;
        }
        else
        {
            return CHAR_ILLEGAL;
        }
    }

    bool
    isNumber(string s)
    {
        // 接受状态
        // 注意!!! 接受状态有多个!!!!
        vector<State> accepted_state{STATE_INTEGER, STATE_POINT, STATE_FRACTION, STATE_EXP_NUMBER, STATE_END};

        // 用一个dict表示状态机
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_INITIAL,
             {
                 {CHAR_SPACE, STATE_INITIAL},
                 {CHAR_SIGN, STATE_INT_SIGN},
                 {CHAR_NUMBER, STATE_INTEGER},
                 {CHAR_POINT, STATE_POINT_WITHOUT_INT},

             }},
            {STATE_INT_SIGN,
             {
                 {CHAR_NUMBER, STATE_INTEGER},
                 {CHAR_POINT, STATE_POINT_WITHOUT_INT},
             }},
            {STATE_INTEGER,
             {
                 {CHAR_NUMBER, STATE_INTEGER},
                 {CHAR_POINT, STATE_POINT},
                 {CHAR_EXP, STATE_EXP},
                 {CHAR_SPACE, STATE_END},
             }},
            {STATE_POINT,
             {
                 {CHAR_NUMBER, STATE_FRACTION},
                 {CHAR_EXP, STATE_EXP},
                 {CHAR_SPACE, STATE_END},
             }},
            {STATE_POINT_WITHOUT_INT,
             {
                 {CHAR_NUMBER, STATE_FRACTION},
             }},
            {STATE_FRACTION,
             {
                 {CHAR_NUMBER, STATE_FRACTION},
                 {CHAR_EXP, STATE_EXP},
                 {CHAR_SPACE, STATE_END},
             }},
            {STATE_EXP,
             {
                 {CHAR_NUMBER, STATE_EXP_NUMBER},
                 {CHAR_SIGN, STATE_EXP_SIGN},
             }},
            {STATE_EXP_SIGN,
             {
                 {CHAR_NUMBER, STATE_EXP_NUMBER},
             }},
            {STATE_EXP_NUMBER,
             {
                 {CHAR_NUMBER, STATE_EXP_NUMBER},
                 {CHAR_SPACE, STATE_END},
             }},
            {STATE_END,
             {
                 {CHAR_SPACE, STATE_END},
             }}

        };
        int len = s.length();
        State state = STATE_INITIAL;
        for (int i = 0; i < len; ++i)
        {
            CharType typ = toCharType(s[i]);
            if (transfer[state].find(typ) == transfer[state].end())
            {
                // 找不到下一步的状态
                return false;
            }
            else
            {
                state = transfer[state][typ];
            }
        }

        return find(accepted_state.begin(), accepted_state.end(), state) != accepted_state.end();
    }
};