import java.util.*;

/**

空间复杂度O(N)

时间复杂度O(2N)

 */
public class Solution {

    public int[] multiply (int[] A) {

        if(A==null || A.length <2){
            return null;
        }
        int[] ans = new int[A.length];

        
        ans[0]=1;


        // 从左往右
        for(int i=1;i<A.length;++i){
            ans[i] = A[i-1] * ans[i-1];
        }

        // 从右往左
        int right = 1;
        for(int i=A.length-2; i>=0; --i){
            right = right * A[i+1];
            ans[i] = ans[i] * right;
        }

        return ans;

    }
}