
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

		//实际上是需要对每一个链表结点进行深拷贝
		//新对象的改变不会影响到旧对象
		//利用 unordered_map<Node*, Node*>建立结点之间的对应关系
		unordered_map<Node*, Node*> mp;
		Node* tmp = head;
		while (tmp)
		{
			//复制一个新的结点, 建立原先的结点和复制之后结点的映射关系
			mp[tmp] = new Node(tmp->val);
			tmp = tmp->next;
		}

		tmp = head;//将tmp结点重新置为head, 目的是为了原链表顺序在unordered_map中查找
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