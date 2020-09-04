// Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    // ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // 空间 O(1)
        ListNode head = ListNode();
        ListNode *tail = &head;

        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                tail = tail->next;

                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                tail = tail->next;

                l2 = l2->next;
            }
        }
        if (l1 == nullptr)
        {
            tail->next = l2;
        }
        else
        {
            tail->next = l1;
        }
        return head.next;
    }
};
