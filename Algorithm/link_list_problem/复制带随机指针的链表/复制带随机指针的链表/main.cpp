#include <iostream>
#include <unordered_map>
#include <memory>

using namespace std;

//���ƴ��漴ָ�������(���)
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
		//��ϣ
		if (head == nullptr)
			return nullptr;
		unordered_map<Node*, Node*> m;
		Node* node = head;
		while (node)
		{
			Node* cur = new Node(node->val);
			m[node] = cur;
			node = node->next;
		}
		node = head;
		while (node)
		{
			m[node]->next = m[node->next];
			m[node]->random = m[node->random];
			node = node->next;
		}
		return m[head];
	}
};

int main()
{

	return 0;
}