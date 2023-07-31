import java.util.*;
/*
public class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}
*/
public class Solution {
    public RandomListNode Clone(RandomListNode pHead) {
        if (pHead == null) {
            return null;
        }
        Map<RandomListNode, RandomListNode> oldToNew = new HashMap<>();

        RandomListNode newHead = new RandomListNode(0); // 链头

        RandomListNode oldObj = pHead;
        RandomListNode newPtr = newHead;

        while (oldObj != null) {
            RandomListNode newObj = new RandomListNode(oldObj.label);

            newPtr.next = newObj;
            oldToNew.put(oldObj, newObj);

            newPtr = newObj;
            oldObj = oldObj.next;
        }


        // 拷贝random
        for(Map.Entry<RandomListNode, RandomListNode> entry : oldToNew.entrySet()){
            if(entry.getKey().random != null){
                entry.getValue().random = oldToNew.get(entry.getKey().random);
            }
        }

        return newHead.next;
    }
}
