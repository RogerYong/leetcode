import java.util.*;
import java.util.Stack;

public class Solution {

    private Stack<Integer> stack = new Stack<>();
    private Stack<Integer> minStack = new Stack<>();

    public void push(int node) {
        if (stack.empty()) {
            stack.push(node);
            minStack.push(node);
        } else {
            stack.push(node);
            minStack.push( Math.min(node, minStack.peek().intValue()) );
        }
    }

    public void pop() {
        if (!stack.empty()) {
            stack.pop();
            minStack.pop();
        }
    }

    public int top() {
        if (!stack.empty()) {
            return stack.peek().intValue();
        } else {
            return 0;
        }
    }

    public int min() {
        if (!minStack.empty()) {
            return minStack.peek().intValue();
        } else {
            return 0;
        }
    }
}
