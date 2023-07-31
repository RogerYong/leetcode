import java.util.*;
public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if (sequence.length == 0) {
            return false;
        }
        Stack<Integer> s = new Stack<>();
        int root = Integer.MAX_VALUE;
        for (int i = sequence.length - 1; i >= 0 ; --i ) {

            if (sequence[i] > root) {
                return false;
            }

            while (!s.empty() && s.peek() > sequence[i] ) {
                root = s.pop();
            }
            s.push(sequence[i]);
        }
        return true;
    }



}