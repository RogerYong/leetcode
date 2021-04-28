class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None


def list2linkedlist(l):
    ll = [ListNode(_) for _ in l]
    for i in range(len(l) - 1):
        ll[i].next = ll[i + 1]

    return ll[0]


def printll(head):
    node = head
    while node is not None:
        print(node.val, " ", end='')
        node = node.next
    print()


def reverse(linked_list):
    '''
    链表反转
    '''
    if not linked_list or not linked_list.next:
        return linked_list
    tail = linked_list
    cur_node = linked_list
    next_node = linked_list.next
    cur_node.next = None

    while next_node is not None:

        tmp_node = next_node
        next_node = next_node.next

        tmp_node.next = cur_node
        cur_node = tmp_node

    return cur_node, tail


def get_k(linked_list, k):
    '''
    是否有k个
    '''
    if not linked_list:
        return None, None, 0
    cur_head = linked_list
    next_head = None

    tmp_node = linked_list
    cnt = 1
    while tmp_node is not None and cnt < k:
        tmp_node = tmp_node.next
        if tmp_node is not None:
            cnt += 1

    if tmp_node is not None:
        next_head = tmp_node.next
        tmp_node.next = None
    return cur_head, next_head, cnt


def reverse_k(linked_list, k):
    '''
    递归实现链表反转
    时间O(n)
    空间O(1)
    '''
    if not linked_list:
        return
    cur_head, next_head = get_k(linked_list, k)
    res_head, tail = reverse(cur_head)

    while next_head is not None:
        cur_head, next_head = get_k(next_head, k)
        tmp_head, tmp_tail = reverse(cur_head)
        tail.next = tmp_head
        tail = tmp_tail

    return res_head


cases = [([1, 2, 3, 4, 5, 6], 2), ([1, 2, 3, 4, 5, 6], 3),
         ([1, 2, 3, 4, 5, 6], 4), ([1, 2, 3, 4, 5, 6], 5)]
for l, k in cases:
    l = list2linkedlist(l)
    printll(reverse_k(l, k))
