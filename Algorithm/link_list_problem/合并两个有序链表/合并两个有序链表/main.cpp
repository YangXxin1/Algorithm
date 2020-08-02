#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr)
			return l2;
		if (l2 == nullptr)
			return l1;
		ListNode* new_head = nullptr;
		ListNode* new_tail = nullptr;

		while (l1 != nullptr && l2 != nullptr)
		{
			ListNode* node = (l1->val < l2->val) ? l1 : l2;
			if (node == l1)
				l1 = l1->next;
			if (node == l2)
				l2 = l2->next;

			//第一次插入的情况
			if (new_head == nullptr)
			{
				new_head = node;
				new_tail = node;
			}
			else
			{
				new_tail->next = node;
				new_tail = node;
			}
		}

		if (l1 == nullptr)
			new_tail->next = l2;
		else
			new_tail->next = l1;
		return new_head;
	}
};

int main()
{
	return 0;
}