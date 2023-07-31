/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
#include<map>
class Solution {
  public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }

        // 双指针法


        // 第一次遍历, 创建节点, 链表合并
        RandomListNode* curOld = pHead;
        RandomListNode* curNew = nullptr;
        while (curOld != nullptr) {
            curNew  = new  RandomListNode(curOld->label);
            curNew->next = curOld->next;
            curOld->next = curNew;
            curOld = curNew->next;
        }

        // 第二次遍历, 拷贝random
        curOld = pHead;
        curNew = nullptr;
        while (curOld != nullptr) {
            curNew = curOld->next;
            if (curOld->random != nullptr) {
                curNew->random = curOld->random->next;
            }

            curOld = curNew->next;
        }

        // 第三次遍历, 链表拆分
        RandomListNode* res = pHead->next;

        curOld = pHead;
        curNew = nullptr;
        while (curOld != nullptr) {
            curNew = curOld->next;

            curOld->next = curNew->next;
            if (curNew->next != nullptr) {
                curNew->next = curNew->next->next;
            }
            curOld = curOld->next;
        }


        return res;
    }
};