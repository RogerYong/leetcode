import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */

    public int single(char ch) {
        return ch == '0' ? 0 : 1;
    }


    public int concat(char ch1, char ch2) {
        if (ch1 == '1') {
            return 1;
        } else if (ch1 == '2') {
            return ch2 >= '0' && ch2 <= '6' ? 1 : 0;
        } else {
            return 0;
        }
    }

    public int solve (String nums) {
        // write code here

        if (nums == null || nums.isEmpty()) {
            return 0;
        }


        List<Integer> li = new ArrayList<>();
        for (int i = 0; i < nums.length(); ++i) {
            li.add(0);
        }


        for (int i = 0; i < nums.length(); ++i) {
            if (i == 0) {
                li.set(0, single(nums.charAt(0)));
            } else if (i == 1) {
                li.set(i, single(nums.charAt(i)) * li.get(i - 1)   +
                       concat(nums.charAt(i - 1), nums.charAt(i)));
            } else {
                li.set(i,  single(nums.charAt(i)) * li.get(i - 1)   +
                       concat(nums.charAt(i - 1), nums.charAt(i)) * li.get(i - 2));
            }
        }

        return li.get(nums.length() - 1);
    }
}