#include <vector>
#include <string>
#include <string.h>
using namespace std;

class Trie
{
public:
    bool isEnd;
    Trie *nexts[26]; // 26字母
    int split;       // 分支数量
    int theIdx;      // 唯一分支的idx

    Trie()
    {
        isEnd = false; // 不是结尾
        split = 0;
        theIdx = -1;
        for (int i = 0; i < 26; i++)
        {
            nexts[i] = nullptr;
        }
    }

    void insert(string word)
    {
        Trie *node = this;
        for (char c : word)
        {
            if (node->nexts[c - 'a'] == nullptr)
            {
                node->nexts[c - 'a'] = new Trie();
                node->split++;
                node->theIdx = c - 'a';
            }
            node = node->nexts[c - 'a'];
        }
        node->isEnd = true; // 单词结尾
    }

    bool search(string word)
    {
        Trie *node = this;
        for (auto c : word)
        {
            node = node->nexts[c - 'a'];
            if (node == nullptr)
            {
                return false;
            }
        }
        return node->isEnd;
    }
    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (auto c : prefix)
        {
            node = node->nexts[c - 'a'];
            if (node == nullptr)
            {
                return false;
            }
        }
        return true;
    }

    string longestCommonPrefix()
    {
        string s;
        Trie *node = this;
        while (node->split == 1 && (not node->isEnd))
        {
            s.push_back(node->theIdx + 'a');
            node = node->nexts[node->theIdx];
        }
        return s;
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie trie;
        for (auto s : strs)
        {
            trie.insert(s);
        }
        return trie.longestCommonPrefix();
    }
};