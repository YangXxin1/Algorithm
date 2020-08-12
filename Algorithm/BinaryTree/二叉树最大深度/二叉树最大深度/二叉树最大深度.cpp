#include <iostream>

//二叉树最大深度
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		int left_depth = maxDepth(root->left) + 1;
		int right_depth = maxDepth(root->right) + 1;

		return left_depth > right_depth ? left_depth : right_depth;
	}
};

int main()
{

	return 0;
}