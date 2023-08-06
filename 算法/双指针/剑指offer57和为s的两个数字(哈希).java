import java.util.*;
import java.util.ArrayList;
public class Solution {
    public ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
        Set<Integer> si = new HashSet<>();
        ArrayList<Integer> ans = new ArrayList<>();

        if(array==null){
            return ans;
        }
        for(int i: array){
            int j = sum - i;
            if(si.contains(j)){
                ans.add(i);
                ans.add(j);
                return ans;
            }else{
                si.add(i);
            }
        }

        return ans;
        
    }
}