/*
和面试题3数组中重复的数字一样, 


注意, 这里pHead是第0个节点
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode *EntryNodeOfLoop(ListNode *pHead)
    {
        // 是否存在环
        ListNode *mp = MeetingNode(pHead);
        if (mp == nullptr)
        {
            return nullptr;
        }

        // 计算环的长度
        int nodesInLoop = 1;
        ListNode *pNode1 = mp;
        while (pNode1->next != mp)
        {
            pNode1 = pNode1->next;
            ++nodesInLoop;
        }
        // 使用快慢针查找环的入口
        pNode1 = pHead;
        for (int i = 0; i < nodesInLoop; i++)
        {
            pNode1 = pNode1->next;
        }
        ListNode *pNode2 = pHead;
        while (pNode1 != pNode2)
        {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        return pNode1;
    }
    ListNode *MeetingNode(ListNode *pHead)
    {
        if (pHead == nullptr)
        {
            return nullptr;
        }
        ListNode *pFast, *pSlow;
        pSlow = pHead->next;
        if (pSlow == nullptr)
        {
            return nullptr;
        }

        pFast = pSlow->next;

        if (pFast == nullptr)
        {
            return nullptr;
        }
        while (pFast != nullptr && pSlow != nullptr)
        {
            if (pFast == pSlow)
            {
                return pFast;
            }

            if (pSlow->next == nullptr)
            {
                return nullptr;
            }
            else
            {
                pSlow = pSlow->next;
            }

            if (pFast->next != nullptr && pFast->next->next != nullptr)
            {
                pFast = pFast->next->next;
            }
            else
            {
                return nullptr;
            }
        }
        return nullptr;
    }
};