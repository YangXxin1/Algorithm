#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		if (pHead == nullptr)
			return pHead;

		//小于x的结点挂到small链表上
		//大于等于x的结点挂到large链表上
		ListNode* small = new ListNode(0);
		ListNode* large = new ListNode(0);

		//保存两个新链表的头结点, 方便最后挂在一起
		ListNode* small_head = small;
		ListNode* large_head = large;

		while (pHead)
		{
			if (pHead->val < x)
			{
				small->next = pHead;
				small = pHead;
			}
			else
			{
				large->next = pHead;
				large = pHead;
			}
			pHead = pHead->next;
		}
		//large总位于最后一个有效结点
		large->next = nullptr;
		//small总位于小于x的最后一个有效结点
		small->next = large_head->next;

		return small_head->next;
	}
};

int main()
{

	return 0;
}