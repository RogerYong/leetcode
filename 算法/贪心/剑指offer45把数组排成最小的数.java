import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型一维数组
     * @return string字符串
     */
    public String PrintMinNumber (int[] numbers) {
        // write code here
        List<String> ns = new ArrayList<>();
        for (int n : numbers) {
            ns.add(String.valueOf(n));
        }

        ns.sort((s1, s2)->
                (s1 + s2).compareTo(s2 + s1)
               );


        StringBuilder sb = new StringBuilder();
        for(String s: ns){
            sb.append(s);
        }

        return sb.toString();
    }
}