#include <iostream>

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(nullptr) {
}
};
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		/*if (pListHead == nullptr || k <= 0)
		return nullptr;

		ListNode* first = pListHead;
		ListNode* second = pListHead;

		while (first != nullptr && k)
		{
		first = first->next;
		k--;
		}
		//����ʱk������0,˵��k��������ĳ���,����������
		if (k > 0)
		return nullptr;

		while (first != nullptr)
		{
		first = first->next;
		second = second->next;
		}

		return second;*/

		//�ݹ鷽��
		if (pListHead == nullptr || k <= 0)
			return nullptr;

		ListNode* node = FindKthToTail(pListHead->next, k);
		if (node != nullptr)
			return node;
		++count;
		if (k == count)
			return pListHead;
		else
			return nullptr;
	}
private:
	unsigned int count = 0;
};

int main()
{

	return 0;
}
