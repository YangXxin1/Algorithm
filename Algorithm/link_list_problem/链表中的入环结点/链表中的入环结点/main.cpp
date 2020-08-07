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
		//����һ,ʹ��set
		//���������ҵ�һ���ظ����ֵĽ�㲢����
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

		//������,����ָ�뷨
		//Ҫ�ҵ��뻷���,����Ҫȷ��������
		//�ҵ�����ָ���һ�������Ľ��,��������
		//��ʱ����ָ������ָ������ͷ������ָ��ͬʱ��ǰ��,ֱ��������Ϊ�뻷���
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