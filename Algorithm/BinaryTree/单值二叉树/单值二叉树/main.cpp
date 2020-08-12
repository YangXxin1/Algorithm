#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//µ¥Öµ¶ş²æÊ÷
class Solution {
public:
	bool _isUnivalTree(TreeNode* root, int val)
	{
		if (root == nullptr)
			return true;

		if (root->val == val)
			return _isUnivalTree(root->left, val)
			&& _isUnivalTree(root->right, val);
		return false;
	}

	bool isUnivalTree(TreeNode* root) {
		if (root == nullptr)
			return true;

		return _isUnivalTree(root->left, root->val)
			&& _isUnivalTree(root->right, root->val);
	}
};

int main()
{

	return 0;
}