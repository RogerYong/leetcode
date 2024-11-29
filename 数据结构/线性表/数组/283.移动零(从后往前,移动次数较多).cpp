class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZero = -1;
        for(int i= nums.size()-1; i>=0; i--){
            if(nums[i]==0){
                // 往后挪
                if(lastNonZero==-1){
                    // 是列表最后的0, 不需要移动
                }else{
                    // 不是列表最后的0, 需要移动
                    moveFromTo(nums, i, lastNonZero);
                    lastNonZero = lastNonZero -1;
                }
            }else{
                // 不是0, 维护最后一个不是0的元素位置
                if(lastNonZero==-1){
                    lastNonZero = i;
                }
            }
        }
    }

    void moveFromTo(vector<int>& nums, int fromIdx, int toIdx){
        if(fromIdx<0 || fromIdx >= nums.size() || toIdx <0 || toIdx>=nums.size() || fromIdx >= toIdx){
            return;
        }
        int tmpNum = nums[fromIdx];
        for(int i=fromIdx; i<toIdx;i++){
            nums[i] = nums[i+1];
        }
        nums[toIdx] = tmpNum;
    }
};