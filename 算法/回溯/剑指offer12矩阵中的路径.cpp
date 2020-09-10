#include <bits/stdc++.h>
using namespace std;

int coors[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty() || word.empty())
        {
            return false;
        }
        int num_row = board.size();
        int num_col = board[0].size();

        for (int i = 0; i < num_row; ++i)
        {
            for (int j = 0; j < num_col; ++j)
            {
                if (board[i][j] == word[0])
                {
                    if (dfs(board, word, i, j, 0))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>> &board, string &word, int i, int j, int word_idx)
    {
        if (word_idx == (word.size() - 1))
        {
            return true;
        }

        int next_word_idx = word_idx + 1;
        char origin_char = board[i][j];

        int next_i, next_j;

        board[i][j] = '/';
        for (int idx = 0; idx < 4; ++idx)
        {
            next_i = i + coors[idx][0];
            next_j = j + coors[idx][1];

            if (next_i >= 0 && next_i < board.size() && next_j >= 0 && next_j < board[0].size() && board[next_i][next_j] == word[next_word_idx])
            {
                if (dfs(board, word, next_i, next_j, next_word_idx))
                {
                    return true;
                }
            }
        }
        board[i][j] = origin_char;
        return false;
    }
};