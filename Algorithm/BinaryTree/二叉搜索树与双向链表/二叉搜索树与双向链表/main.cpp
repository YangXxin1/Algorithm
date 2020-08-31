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
	//注意这里参数传的是Node*&, 否则我们修改的知识拷贝后指针的指向
	void _treeToDoublyList(Node* root, Node*& head, Node*& prev)
	{
		//递归终止条件
		if (root == nullptr)
			return;

		//递归左子树, 直至为左结点为空
		_treeToDoublyList(root->left, head, prev);

		//第一次执行到这一步, root此时为最左结点, 也就是结点值最小的地方, 即head应该指向的位置
		if (head == nullptr)
		{
			//找到head所指向的头结点
			head = root;
			//更新prev结点, 使得每一层栈中, root为当前结点, 而prev则为root的前驱结点
			prev = root;
		}
		else
		{
			//prev为root前驱结点, 即root为prev的后继
			//更改对应结点的指向
			prev->right = root;
			root->left = prev;
			//仍然要记得更新prev结点的位置
			prev = root;
		}

		//递归右子树
		_treeToDoublyList(root->right, head, prev);
	}

	Node* treeToDoublyList(Node* root) {
		//判空
		if (root == nullptr)
			return nullptr;

		Node* head = nullptr;
		Node* prev = nullptr;
		_treeToDoublyList(root, head, prev);

		//因为是双向循环链表, 因此最后要记得将头尾连接在一起
		head->left = prev;
		prev->right = head;

		return head;
	}
};

int main()
{


	return 0;
}