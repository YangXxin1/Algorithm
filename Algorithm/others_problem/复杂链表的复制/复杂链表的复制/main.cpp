
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return head;

		//ʵ��������Ҫ��ÿһ��������������
		//�¶���ĸı䲻��Ӱ�쵽�ɶ���
		//���� unordered_map<Node*, Node*>�������֮��Ķ�Ӧ��ϵ
		unordered_map<Node*, Node*> mp;
		Node* tmp = head;
		while (tmp)
		{
			//����һ���µĽ��, ����ԭ�ȵĽ��͸���֮�����ӳ���ϵ
			mp[tmp] = new Node(tmp->val);
			tmp = tmp->next;
		}

		tmp = head;//��tmp���������Ϊhead, Ŀ����Ϊ��ԭ����˳����unordered_map�в���
		while (tmp)
		{
			if (tmp->next)
				mp[tmp]->next = mp[tmp->next];
			if (tmp->random)
				mp[tmp]->random = mp[tmp->random];
			tmp = tmp->next;
		}
		return mp[head];
	}
};

int main()
{

	return 0;
}