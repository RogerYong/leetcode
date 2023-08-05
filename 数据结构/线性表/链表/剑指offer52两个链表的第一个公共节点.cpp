/**
 * 
 * 
 * 性质: 如果两个链表长度相等. 从前往后遍历, 逐个比较是否相等, 相等表示公共节点
 * 
 * 时间复杂度O(M+N)
 * 空间复杂度O(1)
 * 
*/
class Solution {
  public:


    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = 0;
        int len2 = 0;

        ListNode* curNode1 = pHead1;
        ListNode* curNode2 = pHead2;
        while (curNode1 != nullptr) {
            curNode1 = curNode1->next;
            len1++;
        }

        while (curNode2 != nullptr) {
            curNode2 = curNode2->next;
            len2++;
        }


        curNode1 = pHead1;
        curNode2 = pHead2;
        while (len1 > len2) {
            curNode1 = curNode1->next;
            len1--;
        }

        while (len1 < len2) {
            curNode2 = curNode2->next;
            len2--;
        }

        while (len1 > 0) {
            if (curNode1 == curNode2) {
                return curNode1;
            } else {
                curNode1 = curNode1->next;
				curNode2 = curNode2->next;
                len1--;
            }
        }
        return nullptr;
    }
};
