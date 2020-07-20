#
# @lc app=leetcode.cn id=23 lang=python3
#
# [23] 合并K个排序链表
#
# https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
#
# algorithms
# Hard (44.83%)
# Total Accepted:    20.3K
# Total Submissions: 45.4K
# Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
#
# 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
#
# 示例:
#
# 输入:
# [
# 1->4->5,
# 1->3->4,
# 2->6
# ]
# 输出: 1->1->2->3->4->4->5->6
#
#
# Definition for singly-linked list.

# 以下是小根堆方法
# todo 分治方法
from typing import List


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
    @staticmethod
    def makeLinkedList(l: List[int]):
        list_rear = None
        list_head = None
        for i in l:
            temp_node = ListNode(i)

            if list_head is None and list_rear is None:
                list_head = temp_node
                list_rear = temp_node
            else:
                list_rear.next = temp_node
                list_rear = temp_node

        return list_head
    @staticmethod
    def walk(l):
        s = []
        while l != None:
            s.append(l.val)
            l = l.next
        return s

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        lists = [  l for l in lists if l != None]
        lists.sort(key=lambda node: node.val)
        res_head = None
        res_rear = None
        while len(lists) > 0:
            list_contains_min_val = lists.pop(0)

            current_node = list_contains_min_val

            if res_head is None and res_rear is None:
                res_head = res_rear = current_node
            else:
                res_rear.next = current_node
                res_rear = current_node

            list_contains_min_val = current_node.next

            if list_contains_min_val != None:
                # insert into lists
                # 维护一个小根堆 
                # 插入排序
                lists = self.insertSort(lists, list_contains_min_val)

        return res_head

    def insertSort(self, lists: List[ListNode], item: ListNode) -> List[ListNode]:
        left_index = 0
        right_index = len(lists) - 1

        while left_index <= right_index:
            mid_index = int((left_index + right_index) / 2)
            if lists[mid_index].val > item.val:
                right_index = mid_index - 1
            else:
                left_index = mid_index + 1
        lists.insert(left_index, item)

        return lists


if __name__ == "__main__":
    s = Solution()
    # hi = [
    #     [12,32,342,435546,56],
    #     [895643,21,3456,3241,564,432],
    #     [342,6,675,8,43,76,87],
    #     [534,76,67,786,342,356,6]
    # ]
    # hi = [[1,4,5],[1,3,4],[2,6]]
    hi = [ []]
    for i in hi:
        i.sort()


    lists = []
    for i in hi:
        aa = ListNode.makeLinkedList(i)
        lists.append(aa)
        print(ListNode.walk(aa))

    res = s.mergeKLists(lists)
    print(ListNode.walk(res))
