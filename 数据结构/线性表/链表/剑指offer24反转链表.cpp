struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *new_head = head;
        ListNode *next = head->next;
        head->next = nullptr;

        ListNode *old_head;
        while (next != nullptr)
        {
            old_head = new_head;
            new_head = next;

            next = next->next;
            new_head->next = old_head;
        }

        return new_head;
    }
};