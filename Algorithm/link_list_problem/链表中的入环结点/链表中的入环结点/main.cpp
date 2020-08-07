#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		//方法一,使用set
		//遍历链表找到一个重复出现的结点并返回
		// if (head == nullptr || head->next == nullptr)
		//     return nullptr;

		// set<ListNode*> s;
		// ListNode* node = head;
		// while (node)
		// {
		//     if (s.find(node) != s.end())
		//         return node;
		//     s.insert(node);
		//     node = node->next;
		// }
		// return nullptr;

		//方法二,快慢指针法
		//要找到入环结点,首先要确定环存在
		//找到快慢指针第一次相遇的结点,即环存在
		//此时将快指针重新指向链表头部与慢指针同时向前走,直至相遇则为入环结点
		if (head == nullptr || head->next == nullptr)
			return nullptr;

		ListNode* slow = head;
		ListNode* fast = head;

		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
			{
				fast = head;
				while (slow != fast)
				{
					slow = slow->next;
					fast = fast->next;
				}
				return fast;
			}
		}
		return nullptr;
	}
};