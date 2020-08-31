#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//二叉树层序
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(nullptr), right(nullptr) {
	}
};
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ret;
		if (root == nullptr)
			return ret;

		queue<TreeNode*> q;
		q.push(root);//根结点入队

		while (!q.empty())
		{
			TreeNode* node = q.front();
			q.pop();
			ret.push_back(node->val);

			if (node->left != nullptr)
				q.push(node->left);
			if (node->right != nullptr)
				q.push(node->right);
		}
		return ret;
	}
};

int main()
{

	return 0;
}