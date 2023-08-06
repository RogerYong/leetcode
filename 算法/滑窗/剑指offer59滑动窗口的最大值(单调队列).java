import java.util.*;

public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param num  int整型一维数组
     * @param size int整型
     * @return int整型ArrayList
     */

    public ArrayList<Integer> maxInWindows(int[] num, int size) {
        // write code here
        ArrayList<Integer> ans = new ArrayList<>();
        if (num == null || size == 0 || num.length < size) {
            return ans;
        }

        Deque<Integer> queue = new LinkedList(); 
        // 单调队列法, 保存了当前窗口, 从大到小值的下标
        // 队首是当前窗口的最大值的下标
        for (int i = 0; i < num.length; ++i) {
            while (!queue.isEmpty() && num[queue.getLast()] < num[i]) {
                queue.pollLast();
            }
            queue.addLast(i);
            // 维护窗口
            if (queue.getFirst() + size - 1 < i) {
                queue.pollFirst();
            }
            // 获取当前窗口的最大值
            if (i + 1 >= size) {
                ans.add(num[queue.getFirst()]);
            }
        }
        return ans;
    }
}