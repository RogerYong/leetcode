
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
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
};