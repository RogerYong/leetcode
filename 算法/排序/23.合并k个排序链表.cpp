/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val; // 
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> que(cmp);
        for (auto ln : lists)
        {
            if (ln)
            {
                que.push(ln);
            };
        }
        ListNode *head, *rear;
        head = rear = nullptr;
        while (!que.empty())
        {
            ListNode *tmp = que.top();
            que.pop();

            if (head == nullptr)
            {
                head = rear = tmp;
            }
            else
            {
                rear->next = tmp;
                rear = tmp;
            }

            if (tmp->next != nullptr)
            {
                que.push(tmp->next);
            }
        }
        return head;
    }
};
// @lc code=end
