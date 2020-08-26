#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//判断一棵树是否是另一棵树的子结构
class Solution {
public:
	bool _isSubStructure(TreeNode* A, TreeNode* B)
	{
		if (B == nullptr)
			return true;
		if (A == nullptr)
			return false;

		if (A->val != B->val)
			return false;

		return _isSubStructure(A->left, B->left) && _isSubStructure(A->right, B->right);
	}
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		if (A == nullptr || B == nullptr)
			return false;

		if (A->val == B->val && _isSubStructure(A, B))
			return true;

		return isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
};

int main()
{


	return 0;
}