#include <iostream>

//�Ƴ�����Ԫ��
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) 
	{}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == nullptr)
			return head;

		//˫ָ��
		// ListNode* new_head = new ListNode(0);
		// new_head->next = head;

		// ListNode* prev = new_head;
		// ListNode* cur = head;

		// while (cur != nullptr)
		// {
		//     if (cur->val == val)
		//         prev->next = cur->next;
		//     else
		//         prev = cur;
		//     cur = cur->next;
		// }
		// return new_head->next;

		//�ݹ鷽��
		head->next = removeElements(head->next, val);

		if (head->val == val)
			return head->next;
		return head;
	}
};

int main()
{
	return 0;
}