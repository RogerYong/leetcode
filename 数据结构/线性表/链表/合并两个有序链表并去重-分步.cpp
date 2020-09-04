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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // 去重
        if (head == nullptr)
        {
            return nullptr;
        }
        // 循环实现
        // 空间O(1)
        ListNode new_head = ListNode(0);
        // 把链表第一个元素加进来
        new_head.next = head;
        head = head->next;

        ListNode *tail = new_head.next;
        tail->next = nullptr;

        while (head != nullptr)
        {
            if (head->val == tail->val)
            {
                head = head->next;
            }
            else
            {
                tail->next = head;

                head = head->next;

                tail = tail->next;
                tail->next = nullptr;
            }
        }

        return new_head.next;
    }

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

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        else if (l1 == nullptr)
        {
            return deleteDuplicates(l2);
        }
        else if (l2 == nullptr)
        {
            return deleteDuplicates(l1);
        }
        else
        {
            return deleteDuplicates(mergeTwoLists(l1, l2));
        }
    }
};
