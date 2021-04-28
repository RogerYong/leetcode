#
# @lc app=leetcode.cn id=2 lang=python3
#
# [2] 两数相加
#
# https://leetcode-cn.com/problems/add-two-numbers/description/
#
# algorithms
# Medium (33.81%)
# Total Accepted:    116.5K
# Total Submissions: 344.6K
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
#
# 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
#
# 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
#
# 示例：
#
# 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
# 输出：7 -> 0 -> 8
# 原因：342 + 465 = 807
#
#
#
# Definition for singly-linked list.
# from typing import List


# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#     @staticmethod
#     def makeLinkedList(l: List[int]):
#         list_rear = None
#         list_head = None
#         for i in l:
#             temp_node = ListNode(i)

#             if list_head is None and list_rear is None:
#                 list_head = temp_node
#                 list_rear = temp_node
#             else:
#                 list_rear.next = temp_node
#                 list_rear = temp_node

#         return list_head


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        l1_item = l1
        l2_item = l2
        carry_item = None
        res_head = None
        res_rear = None
        while l1_item != None or l2_item != None or carry_item != None:
            temp_res, carry_item = self.carryAdd(l1_item, l2_item, carry_item)
            if res_head is None and res_rear is None:
                res_head = res_rear = temp_res
            else:
                res_rear.next = temp_res
                res_rear = temp_res

            if l1_item != None:
                l1_item = l1_item.next
            if l2_item != None:
                l2_item = l2_item.next

        return res_head

    def carryAdd(self, a: ListNode, b: ListNode, carry: ListNode) -> List[ListNode]:
        a_v, b_v, c_v = 0, 0, 0
        if a is not None:
            a_v = a.val
        if b is not None:
            b_v = b.val
        if carry is not None:
            c_v = carry.val

        tempSum = a_v + b_v + c_v
        tempVal = int(tempSum % 10)
        tempCarry = int(tempSum / 10)

        val = ListNode(tempVal)
        if tempCarry == 0:
            carry = None
        else:
            carry = ListNode(tempCarry)

        return [val, carry]

#     def walk(self, l: ListNode, inverse=True) -> list:
#         s = []
#         while l != None:
#             if inverse is False:
#                 s.insert(0, l.val)
#             else:
#                 s.append(l.val)
#             l = l.next

#         return s


# if __name__ == "__main__":
#     s = Solution()

#     l1 = ListNode.makeLinkedList([5])
#     l2 = ListNode.makeLinkedList([5])

#     res = s.addTwoNumbers(l1, l2)

#     print(s.walk(l1))
#     print(s.walk(l2))
#     print(s.walk(res))

    # print(s.walk(l1,inverse=False))
    # print(s.walk(l2, inverse=False))
    # print(s.walk(res, inverse=False))
