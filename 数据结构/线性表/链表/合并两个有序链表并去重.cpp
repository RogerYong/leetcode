// Definition for singly-linked list.
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    // ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        // 空间 O(1)
        ListNode head = ListNode();
        ListNode *tail = &head;

        // 初始化head
        if (l1 == nullptr || (l1 != nullptr && l2 != nullptr && l1->val >= l2->val))
        {
            tail->next = l2;
            l2 = l2->next;

            tail = tail->next;
            tail->next = nullptr;
        }
        else
        {
            tail->next = l1;
            l1 = l1->next;

            tail = tail->next;
            tail->next = nullptr;
        }

        while (l1 != nullptr || l2 != nullptr)
        {
            // 去重
            while (l1 != nullptr && l1->val == tail->val)
            {
                l1 = l1->next;
            }
            while (l2 != nullptr && l2->val == tail->val)
            {
                l2 = l2->next;
            }

            if (l1 == nullptr && l2 == nullptr)
            {
                break;
            }
            // 合并链表
            else if (l1 == nullptr || (l1 != nullptr && l2 != nullptr && l2->val < l1->val))
            {
                tail->next = l2;
                l2 = l2->next;

                tail = tail->next;
                tail->next = nullptr;
            }
            else
            {
                tail->next = l1;
                l1 = l1->next;

                tail = tail->next;
                tail->next = nullptr;
            }
        }
        return head.next;
    }
};
