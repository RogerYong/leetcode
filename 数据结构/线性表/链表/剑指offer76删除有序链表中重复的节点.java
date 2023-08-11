import java.util.*;
/*
 public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}
*/

/**
 * 时间复杂度O(N)
 * 空间复杂度O(1)
 * 
 * 如果用hash, 要遍历2次链表, 第一次计数, 第二次删除; 需要额外O(N)空间保存计数
 */
public class Solution {
    public ListNode deleteDuplication(ListNode pHead) {

        ListNode fakeHead = new ListNode(-1);
        fakeHead.next = pHead;

        ListNode prevNode = fakeHead; // prevNode表示不重复的节点
        // 判断prevNode的下一个节点是否重复节点
        // 重复节点的条件: 至少有两个连续节点, 节点值相等
        while (prevNode != null && prevNode.next != null &&
                prevNode.next.next != null) {
            // 第一步, 寻找prevNode后的重复节点值, 记录在repeatVal中, repeatVal==-1表示不存在重复节点
            int repeatVal = -1;
            if (prevNode.next.val == prevNode.next.next.val) {
                repeatVal = prevNode.next.val;
            }
            if (repeatVal == -1) {
                // 如果下一个节点是非重复节点, prevNode右移
                prevNode = prevNode.next;
            } else {
                // 删除重复节点
                while (prevNode.next != null && prevNode.next.val == repeatVal) {
                    prevNode.next = prevNode.next.next;
                }
            }

        }
        return fakeHead.next;
    }
}
