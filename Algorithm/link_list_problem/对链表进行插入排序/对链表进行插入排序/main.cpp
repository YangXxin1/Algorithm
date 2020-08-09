#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode* new_head = new ListNode(0);
		new_head->next = head;

		ListNode* prev = head;
		ListNode* tail = head->next;

		while (tail)
		{
			if (tail->val < prev->val)
			{
				//用来从头进行遍历,找到插入位置
				ListNode* tmp = new_head;
				while (tmp->next && tmp->next->val < tail->val)
				{
					tmp = tmp->next;
				}
				//保存下一个要插入的结点
				//保持prev位于要插入结点的前一个为
				prev->next = tail->next;
				tail->next = tmp->next;
				tmp->next = tail;
				tail = prev->next;
			}
			else
			{
				prev = prev->next;
				tail = tail->next;
			}
		}
		return new_head->next;
	}
};

int main()
{

	return 0;
}