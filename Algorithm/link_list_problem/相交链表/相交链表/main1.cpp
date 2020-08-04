#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//方法一
		/*if (headA == nullptr || headB == nullptr)
		return nullptr;

		int lenA = 0, lenB = 0;

		//遍历得到两个链表长度
		ListNode* node = headA;
		while (node != nullptr)
		{
			node = node->next;
			++lenA;
		}
		node = headB;
		while (node != nullptr)
		{
			node = node->next;
			++lenB;
		}

		//较长的链表先走差值步
		int count = abs(lenA - lenB);
		if (lenA > lenB)
		{
			while (count--)
				headA = headA->next;
			}
		else
		{
			while (count--)
				headB = headB->next;
		}
		//较长的链表走完两个链表的差值之后, 接下俩两个指针一起走, 直至相等
		while (headA != nullptr)
		{
			if (headA == headB)
				break;
			headA = headA->next;
			headB = headB->next;
		}
		return headA;*/

		//方法二
		//优化双指针法
		if (headA == nullptr || headB == nullptr)
			return nullptr;

		ListNode* pA = headA;
		ListNode* pB = headB;
		//pA, pB一起向后走, 较短的先走到末尾
		//若pA走到末尾, 下次循环则将pA置为headB
		//反之, pB置为headA

		//链表A : a + c
		//链表B : b + c
		//c为公共部分
		// a + c + b + c == b + c + a + c
		//相交则最终在公共部分c相遇(因为a+c+b = b+c+a)
		//不相交则为 a + b == b + a, 最终为nulltr
		while (pA != pB)
		{
			pA = (pA == nullptr) ? headB : pA->next;
			pB = (pB == nullptr) ? headA : pB->next;
		}
		return pA;

	}
};

int main()
{

	return 0;
}