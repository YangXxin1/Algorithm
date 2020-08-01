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

		//�ݹ鷽��
		//����Ϊ�ջ���������ֻ��һ���ڵ�
		if (head == nullptr || head->next == nullptr)
			return head;
		//�ݹ��õ����һ���ǿս��
		ListNode* new_head = reverseList(head->next);
		//��ʱheadָ���λ��Ϊ�����ڶ������
		head->next->next = head;
		head->next = nullptr;
		return new_head;
	}

};

int main()
{

	return 0;
}