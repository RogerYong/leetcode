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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
        {
            return head;
        }
        int len = len_of_list(head);

        if (n > len)
        {
            return head;
        }
        else if (n == len)
        {
            return head->next;
        }
        else // 找到前一个删除
        {
            int idx = 0;
            ListNode *pre = head;
            while (idx < (len - n - 1))
            {
                pre = pre->next;
                idx++;
            }

            // idx == len - n - 1
            pre->next = pre->next->next;

            return head;
        }
    }
};