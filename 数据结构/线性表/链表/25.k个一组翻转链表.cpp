
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    void reverse(ListNode *head, ListNode *tail)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (pre != tail)
        {
            ListNode *originNext = cur->next;
            cur->next = pre;

            // 维护两个变量
            pre = cur;
            cur = originNext;
        }
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr || k == 1)
        {
            return head;
        }

        // 新建一个节点, 作为链表头, 把边界的情况统一处理了
        ListNode *hair = new ListNode(0, head);

        ListNode *pre = hair;    // 上一个区间的tail
        ListNode *nex = nullptr; // 下一个区间的Head
        while (pre->next != nullptr)
        {
            ListNode *kHead = pre->next;
            ListNode *kTail = pre;

            for (int i = 0; i < k; i++) // 移动k次, 得到当前区间的tail
            {
                kTail = kTail->next;
                if (kTail == nullptr) // 不足k个, 已经到达链表末尾
                {
                    return hair->next;
                }
            }

            //迭代反转
            nex = kTail->next;
            reverse(kHead, kTail);
            pre->next = kTail;
            kHead->next = nex;

            pre = kHead;
            nex = nullptr;
        }

        return hair->next;
    }
};