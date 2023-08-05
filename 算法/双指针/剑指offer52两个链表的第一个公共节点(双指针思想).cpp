/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};*/
class Solution {
  public:

	/**

	情况1: 两个长度相等的链表, 如果有公共节点, 那么同时从前往后遍历, 第一个相等的位置, 就是第一个公共节点

	情况2: 两个长度不相等的链表, 可以通过链表相互拼接的方式, 转换为第一种情况.


	为什么情况2可以转换为情况1:

	链表1长度M=a+c, 链表2长度N=b+c.        

	把链表2接在链表1后面, 长度就是a+b+2c, 且链表的末尾c个节点是公共节点

	把链表1接在链表2后面, 长度也是a+b+2c, 且链表的末尾c个节点是公共节点

	如果有公共节点, 最多O(M+N), 能找到结果

	
	
	
	
	Q: 如果没有公共节点, 会出现死循环吗? 如何避免死循环?
	
	链表末尾的nullptr可看作是公共节点, 经过O(M+N), 双指针都是nullptr, 这个时候会退出循环, 不会出现死循环


	
	*/
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* curNode1 = pHead1;
        ListNode* curNode2 = pHead2;
		while (curNode1!=curNode2) {
			curNode1 =  curNode1==nullptr ? pHead2 : curNode1->next;
			curNode2 =  curNode2==nullptr ? pHead1 : curNode2->next;
		}
        return curNode1;
    }
};

