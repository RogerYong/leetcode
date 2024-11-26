class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longestConsecutive = 0;
        // c++ set初始化
        unordered_set<int> numSet;
        for(int num : nums){
            // c++ set添加元素
            numSet.insert(num);
        }

        int result = 0;
        // c++ 遍历集合, 使用引用
        for(const int& num: numSet){
            // c++ 判断集合是否含有元素
            if(!numSet.count(num-1)){
                int curNum = num;
                int consecutive = 1;

                while(numSet.count(curNum+1)){
                    curNum += 1;
                    consecutive += 1;
                }

                result = max(result, consecutive);
            }
        }
        return result;
    }
};