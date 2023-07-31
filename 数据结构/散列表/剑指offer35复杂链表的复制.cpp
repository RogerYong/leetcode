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

        map<RandomListNode*, RandomListNode*> oldToNew;

        RandomListNode* res = new RandomListNode(0);

        RandomListNode* curOld = pHead;
        RandomListNode* preNew = res;
        while (curOld != nullptr) {
            RandomListNode* curNew = new RandomListNode(curOld->label);
            preNew->next = curNew;

            oldToNew[curOld] = curNew;

            curOld = curOld->next;
            preNew = curNew;
        }

        // 复制random
        for (auto it : oldToNew) {
            if ( it.first->random != nullptr) {
                it.second->random = oldToNew[it.first->random ];
            }
        }
        return res->next;
    }
};