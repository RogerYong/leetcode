import java.util.*;
public class Solution {
    public String ReverseSentence(String str) {

        if (str == null || str.isEmpty()) {
            return "";
        }
        // List<String> ls = Arrays.asList(str.split("\s+")); // Arrays.asList转出来的结果不能修改
        List<String> ls = new ArrayList<>();
        Collections.addAll(ls,str.split("\\s+"));
        Collections.reverse(ls);
        return  String.join(" ", ls);
    }
}
