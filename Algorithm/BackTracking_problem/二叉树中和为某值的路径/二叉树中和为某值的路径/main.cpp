#include <iostream>
#include <vector>

using namespace std;

//DFS穷举
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
	//DFS
	void _FindPath(TreeNode* root, int expectNumber, vector<vector<int>>& ret, vector<int>& tmp)
	{
		//递归终止条件
		if (root == nullptr)
		{
			return;
		}
		int val = root->val;
		expectNumber -= val;
		tmp.push_back(root->val);//将值添加到临时结果集
		if (root->left == nullptr && root->right == nullptr && expectNumber == 0)
		{
			ret.push_back(tmp);//满足条件将路径添加到最终结果集中
			//这里条件结果之后不能return,因为要回溯
		}

		_FindPath(root->left, expectNumber, ret, tmp);
		_FindPath(root->right, expectNumber, ret, tmp);

		tmp.pop_back();//回溯
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> ret;//最终结果集
		vector<int> tmp;//临时结果集

		if (root == nullptr)
			return ret;
		_FindPath(root, expectNumber, ret, tmp);
		return ret;
	}
};

int main()
{
	return 0;
}