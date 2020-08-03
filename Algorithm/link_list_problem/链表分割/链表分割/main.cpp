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

		//С��x�Ľ��ҵ�small������
		//���ڵ���x�Ľ��ҵ�large������
		ListNode* small = new ListNode(0);
		ListNode* large = new ListNode(0);

		//���������������ͷ���, ����������һ��
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
		//large��λ�����һ����Ч���
		large->next = nullptr;
		//small��λ��С��x�����һ����Ч���
		small->next = large_head->next;

		return small_head->next;
	}
};

int main()
{

	return 0;
}