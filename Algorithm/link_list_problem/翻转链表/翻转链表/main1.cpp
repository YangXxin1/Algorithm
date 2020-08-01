#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// if (head == nullptr || head->next == nullptr)
		//     return head;
		// ListNode* prev = head;
		// ListNode* mid = head->next;
		// ListNode* last = mid->next;
		// while (last != nullptr)
		// {
		//     mid->next = prev;
		//     prev = mid;
		//     mid = last;
		//     last = last->next;
		// }
		// mid->next = prev;
		// head->next = nullptr;
		// head = mid;
		// return head;

		//递归方法
		//链表为空或者链表中只有一个节点
		if (head == nullptr || head->next == nullptr)
			return head;
		//递归拿到最后一个非空结点
		ListNode* new_head = reverseList(head->next);
		//此时head指针的位置为倒数第二个结点
		head->next->next = head;
		head->next = nullptr;
		return new_head;
	}

};

int main()
{

	return 0;
}