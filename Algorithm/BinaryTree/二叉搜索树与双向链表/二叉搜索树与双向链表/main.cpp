#include <iostream>

using namespace std;

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = nullptr;
		right = nullptr;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution {
public:
	//ע���������������Node*&, ���������޸ĵ�֪ʶ������ָ���ָ��
	void _treeToDoublyList(Node* root, Node*& head, Node*& prev)
	{
		//�ݹ���ֹ����
		if (root == nullptr)
			return;

		//�ݹ�������, ֱ��Ϊ����Ϊ��
		_treeToDoublyList(root->left, head, prev);

		//��һ��ִ�е���һ��, root��ʱΪ������, Ҳ���ǽ��ֵ��С�ĵط�, ��headӦ��ָ���λ��
		if (head == nullptr)
		{
			//�ҵ�head��ָ���ͷ���
			head = root;
			//����prev���, ʹ��ÿһ��ջ��, rootΪ��ǰ���, ��prev��Ϊroot��ǰ�����
			prev = root;
		}
		else
		{
			//prevΪrootǰ�����, ��rootΪprev�ĺ��
			//���Ķ�Ӧ����ָ��
			prev->right = root;
			root->left = prev;
			//��ȻҪ�ǵø���prev����λ��
			prev = root;
		}

		//�ݹ�������
		_treeToDoublyList(root->right, head, prev);
	}

	Node* treeToDoublyList(Node* root) {
		//�п�
		if (root == nullptr)
			return nullptr;

		Node* head = nullptr;
		Node* prev = nullptr;
		_treeToDoublyList(root, head, prev);

		//��Ϊ��˫��ѭ������, ������Ҫ�ǵý�ͷβ������һ��
		head->left = prev;
		prev->right = head;

		return head;
	}
};

int main()
{


	return 0;
}