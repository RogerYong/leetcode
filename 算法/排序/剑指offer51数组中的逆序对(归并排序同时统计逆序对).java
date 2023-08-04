import java.util.*;


public class Solution {
    public static final long mod = 1000000007;


    /**

    [left, mid]
    [mid+1, right]
     */
    public long mergeCnd(int[] nums, int left, int mid, int right) {
        long cnt = 0;
        int idx1 = left;
        int idx2 = mid + 1;

        // out place merge. 以空间换时间
        // 空间复杂度O(n), 时间复杂度O(n)

        // 如果是inplace merge, 空间复杂度O(1), 但是时间复杂度O(n^2)
        List<Integer> sorted = new ArrayList<>();
        while (idx1 <= mid && idx2 <= right ) {
            if (nums[idx1] <= nums[idx2]) {
                sorted.add(nums[idx1]);
                idx1++;
            } else {
                sorted.add(nums[idx2]);
                idx2++;
                cnt = ( cnt +  (mid - idx1 + 1)) %
                      mod; // 交换一次, 就能修正多个逆序对, 这也是为什么归并排序复杂度低的原因
            }
        }
        while(idx1<=mid){
            sorted.add(nums[idx1]);
            idx1++;
        }
        while(idx2<=right){
            sorted.add(nums[idx2]);
            idx2++;
        }

        for(int i=0;i<sorted.size();++i){
            nums[left+i] = sorted.get(i); // outplace结果写回原数组
        }

        return cnt;
    }
    /**
        nums[left:right] 排序并的逆序对
     */
    public long mergeSort(int[] nums, int left, int right) {

        if (left >= right) {
            return 0;
        }
        if (left + 1 == right) {
            if (nums[left] <= nums[right]) {
                return 0;
            } else {
                // 基于相邻元素交换排序
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
                // 记录逆序对
                return 1;
            }
        }

        int mid = left + (right - left) / 2;

        long l = mergeSort(nums, left, mid); // 排序并记录逆序对
        long r = mergeSort(nums, mid + 1, right); // 排序并记录逆序对
        long m = mergeCnd(nums, left, mid, right); // 归并排序并记录逆序对

        return (l + r + m ) % mod;
    }

    public int InversePairs (int[] nums) {
        // write code here

        if (nums == null || nums.length < 2) {
            return 0;
        }
        return (int)mergeSort(nums, 0, nums.length - 1);
    }
}