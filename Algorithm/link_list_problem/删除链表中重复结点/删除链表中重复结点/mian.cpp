#include <iostream>

using namespace std;


//while (tail->next && tail->val != tail->next->val)
//{
//prev = prev->next;
//tail = tail->next;
//}


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) 
	{

	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		/*if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		//Ϊ�˷���ɾ��ͷ����ظ������, ���ǹ���һ���ڱ����
		ListNode* new_head = new ListNode(0);
		new_head->next = pHead;

		ListNode* prev = new_head;
		ListNode* tail = prev->next;

		while (tail)
		{
			while (tail->next && tail->val == tail->next->val)
				tail = tail->next;

			if (prev->next == tail)
			{
				//˵�����������Ȼ����,û����Ҫɾ������Ч����
				prev = prev->next;
			}
			else
			{
				//����������Ҫɾ��
				prev->next = tail->next;
			}
			tail = tail->next;
		}
		return new_head->next;*/

		//�򻯴���
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		//Ϊ�˷���ɾ��ͷ����ظ������, ���ǹ���һ���ڱ����
		ListNode* new_head = new ListNode(0);
		new_head->next = pHead;

		ListNode* prev = new_head;
		ListNode* tail = prev->next;

		while (tail)
		{
			//����ͨ�����������ֱ���ҵ���Ҫɾ�������ͷ���
			//prev���λ��tail���ǰ��
			//�ҵ����ֵʱͨ���ƶ�tailָ���λ���ҵ���Ҫɾ�������һ�����
			//����ʱprev������λ������Ҫɾ���ĵ�һ������ǰ�����
			while (tail->next && tail->val != tail->next->val)
			{
				prev = prev->next;
				tail = tail->next;
			}
			while (tail->next && tail->val == tail->next->val)
				tail = tail->next;

			if (prev->next != tail)
			{
				//˵������Ҫɾ���Ľ��
				prev->next = tail->next;
			}
			tail = tail->next;
		}
		return new_head->next;
	}
};

int main()
{

	return 0;
}