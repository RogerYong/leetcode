// 下面是O(n)的解法
// 要求是O(1)
// 则通过copy的方式删除

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
    ListNode *deleteNode(ListNode *head, int val)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *current_ptr = head;
        ListNode *pre_ptr = head;
        while (current_ptr != nullptr)
        {
            if (current_ptr->val == val)
            {
                // 删除
                if (pre_ptr == current_ptr)
                {
                    return head->next;
                }
                else
                {
                    pre_ptr->next = current_ptr->next;
                    return head;
                }
            }
            else
            {
                pre_ptr = current_ptr;
                current_ptr = current_ptr->next;
            }
        }
        return head;
    }
};