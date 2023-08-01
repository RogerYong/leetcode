/**
 * 
 * 快排的思路
 * 
 * 时间复杂度O(N)
 * 空间复杂度O(1)
*/

#include <fstream>
#include <iostream>
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param input int整型vector
     * @param k int整型
     * @return int整型vector
     */

    /**
    [l, r]
    */
    int partition(vector<int>& input, int l, int r) {
        int privotIdx = l;
        int privot = input[privotIdx];
        int left = l;
        int right = r;
        while (left < right) {
            while (left < right && input[right] >= privot) {
                right --;
            }
            while (left < right && input[left] <= privot) {
                left ++;
            }

            if (left < right) {
                swap(input[left], input[right]);
            }
        }
        // 循环break的条件是left==right
        swap(input[privotIdx], input[left]);
        privotIdx = left;
        return privotIdx;
    }

    vector<int> GetLeastNumbers_Solution(vector<int>& input, int k) {
        // write code here
        vector<int> ans;
        if (k == 0 || input.empty()) {
            return ans;
        }
        if (k >= input.size()) {
            return input;
        }

        int l = 0, r = input.size() - 1;
        while (l < r) {
            int privotIdx = partition(input, l, r);
            // cout << "left" << l << " " << privotIdx << " " << r << endl;
            // for (int i = l; i <= r; i++) {
            //     cout << i << " " << input[i] << endl;
            // }
            if (privotIdx + 1 == k) {
                return vector<int>({input.begin(), input.begin() + k}); // [0, k)
            }
            if (privotIdx + 1 < k) {
                l = privotIdx +1;
            } else {
                r = privotIdx;
            }

        }
        return ans;
    }
};