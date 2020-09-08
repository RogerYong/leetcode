
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
    int len_of_list(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            /* code */
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        int len = len_of_list(head);
        if (k < 1)
        {
            return nullptr;
        }
        else if (k >= len) // k > 链表长度
        {
            return head;
        }
        else // 1 <= k < len
        {
            int idx = len - k;
            int i = 0; // i 从0开始
            ListNode *res = head;
            while (i != idx)
            {
                ++i;
                res = res->next;
            }
            return res;
        }
    }
};