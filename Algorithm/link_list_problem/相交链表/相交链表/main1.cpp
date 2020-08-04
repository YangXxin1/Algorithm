#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		//����һ
		/*if (headA == nullptr || headB == nullptr)
		return nullptr;

		int lenA = 0, lenB = 0;

		//�����õ�����������
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

		//�ϳ����������߲�ֵ��
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
		//�ϳ�������������������Ĳ�ֵ֮��, ����������ָ��һ����, ֱ�����
		while (headA != nullptr)
		{
			if (headA == headB)
				break;
			headA = headA->next;
			headB = headB->next;
		}
		return headA;*/

		//������
		//�Ż�˫ָ�뷨
		if (headA == nullptr || headB == nullptr)
			return nullptr;

		ListNode* pA = headA;
		ListNode* pB = headB;
		//pA, pBһ�������, �϶̵����ߵ�ĩβ
		//��pA�ߵ�ĩβ, �´�ѭ����pA��ΪheadB
		//��֮, pB��ΪheadA

		//����A : a + c
		//����B : b + c
		//cΪ��������
		// a + c + b + c == b + c + a + c
		//�ཻ�������ڹ�������c����(��Ϊa+c+b = b+c+a)
		//���ཻ��Ϊ a + b == b + a, ����Ϊnulltr
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