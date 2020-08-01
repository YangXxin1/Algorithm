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
		//若此时k还大于0,说明k大于链表的长度,条件不满足
		if (k > 0)
		return nullptr;

		while (first != nullptr)
		{
		first = first->next;
		second = second->next;
		}

		return second;*/

		//递归方法
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
