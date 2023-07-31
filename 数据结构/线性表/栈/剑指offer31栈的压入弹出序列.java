import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型一维数组
     * @param popV int整型一维数组
     * @return bool布尔型
     */
    public boolean IsPopOrder (int[] pushV, int[] popV) {
        // write code here
        if (pushV.length == 0) {
            return popV.length == 0;
        }
        Stack<Integer> stack = new Stack<>();
        int pushIdx = 0;
        int popIndx = 0;

        while (popIndx < popV.length) {
            if (!stack.empty()) {
                if (stack.peek().equals(popV[popIndx])) {
                    stack.pop();
                    popIndx += 1;
                    continue;
                }
            }
            if (pushIdx < pushV.length) {
                stack.push(pushV[pushIdx]);
                pushIdx += 1;
            } else {
                return false;
            }
        }

        return true;
    }
}