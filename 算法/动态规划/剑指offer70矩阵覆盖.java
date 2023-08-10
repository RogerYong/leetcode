import java.util.*;
public class Solution {
    public int rectCover(int target) {
        if(target==0){
            return 0;
        }
        if(target == 1){
            return 1;
        }
        if(target == 2){
            return 2;
        }

        int[] ans = new int[target+1];
        ans[1] = 1;
        ans[2] = 2;
        for(int i=3;i<=target;++i){
            ans[i] = ans[i-1] + ans[i-2] ;
        }

        return ans[target];
    }
}
