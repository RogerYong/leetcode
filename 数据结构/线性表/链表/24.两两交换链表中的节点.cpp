#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    // ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *newHead = head->next;
        ListNode *preNode = nullptr;
        ListNode *firstNode = head;
        ListNode *secondNode = nullptr;
        while (firstNode != nullptr && firstNode->next != nullptr)
        {
            //
            secondNode = firstNode->next;

            // 维护3个节点的next
            if (preNode != nullptr)
            {
                preNode->next = secondNode;
            }
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            // 维护3个Node变量
            preNode = firstNode;
            firstNode = preNode->next;
        }

        return newHead;
    }
};