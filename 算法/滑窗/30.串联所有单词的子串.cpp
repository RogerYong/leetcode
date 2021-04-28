#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;

        map<string, int> word_cnt;
        for (auto &w : words)
        {
            word_cnt[w]++;
        }

        auto word_len = words[0].size();
        int num_word = words.size();
        if (num_word < 1 || s.size() < word_len)
        {
            return ans;
        }

        // 滑窗
        for (int i = 0; i < word_len; i++)
        {
            map<string, int> tmp_word_cnt;
            int cnt = 0;   // 已经匹配的单词数量
            int left = i;  // 窗口左边
            int right = i; // 当前遍历到的位置
            for (; right <= s.size() - word_len; right += word_len)
            {
                string tmp_word = s.substr(right, word_len);
                if (word_cnt.find(tmp_word) != word_cnt.end())
                {
                    // 找到单词了
                    tmp_word_cnt[tmp_word]++; // 计数+1
                    cnt++;

                    // 超出数量了
                    // 右移left
                    while (tmp_word_cnt[tmp_word] > word_cnt[tmp_word])
                    {
                        tmp_word_cnt[s.substr(left, word_len)]--;
                        cnt--;
                        left += word_len;
                    }

                    if (cnt == num_word)
                    {
                        ans.push_back(left);
                    }
                }
                else
                {
                    left = right + word_len;
                    cnt = 0;
                    tmp_word_cnt.clear();
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    auto ans = s.findSubstring(str, words);
    return 0;
}