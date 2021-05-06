#include <string>
using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int word_right = s.size() - 1;

        while (word_right >= 0 && s[word_right] == ' ')
        {
            word_right--;
        }

        int word_left = word_right;
        while (word_left >= 0 && s[word_left] != ' ')
        {
            word_left--;
        }
        return word_right - word_left;
    }
};