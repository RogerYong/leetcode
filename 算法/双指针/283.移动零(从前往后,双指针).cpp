class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0; // 处理完成的列表末尾
        int right = 0; // 

        // 维护左指针左边均为非0
        // 维护右指针左边直到左指针处均为0

        int n = nums.size();
        while(right < n){
            if(nums[right]){
                swap(nums[left], nums[right]);
                left ++ ;
            }
            right ++;
        }
        
    }

};