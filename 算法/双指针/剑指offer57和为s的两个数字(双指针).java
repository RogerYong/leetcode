import java.util.*;
import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
        Set<Integer> si = new HashSet<>();
        ArrayList<Integer> ans = new ArrayList<>();

        if(array==null){
            return ans;
        }
        int left = 0;
        int right = array.length -1;
        for(;left< right && left<array.length;left++){
            int l = array[left];
            while(left< right && l + array[right] >sum ){
                    right--;
            }
            if(l + array[right] ==sum){
                ans.add(l);
                ans.add(array[right]);
                return ans;
            }
        }

        return ans;
    }
}