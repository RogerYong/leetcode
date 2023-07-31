import java.util.*;
public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if (sequence.length == 0) {
            return false;
        }
        if (sequence.length < 3) {
            return true;
        }

        return verify(sequence,  0,  sequence.length - 1);
    }


    private boolean verify(int [] sequence,
                           int startIdx, int endIdx) {
                            
        if(startIdx>=endIdx){
            return true;
        }

        int root = sequence[endIdx];

        // 寻找左子树  [startIdx, i)
        int i = startIdx;
        for (; sequence[i] < root && i < endIdx; ++i) {

        }
        // 校验右子树 [i, endIdx)
        int k = i;
        for(;k<endIdx;++k){
            if(sequence[k]<=root){
                return false;
            }
        }
        // 校验左子树
        if(!verify(sequence, startIdx, i-1)){
            return false;
        }
        // 校验右子树
        return verify(sequence, i, endIdx -1);
    }
}