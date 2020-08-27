#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	//DFS深度优先遍历
	void FindPath(vector<int>& ret, TreeNode* root, int sum)
	{
		//当前结点为空, 终止递归
		if (root == nullptr)
			return;

		int num = root->val;
		sum -= num;
		ret.push_back(root->val);

		//左右结点均为空,表示当前结点为叶子结点
		if (root->left == nullptr && root->right == nullptr && sum == 0)
		{
			//注意这里满足条件之后还不能return
			//会影响后面回溯
			_all_path.push_back(ret);
		}

		FindPath(ret, root->left, sum);
		FindPath(ret, root->right, sum);
		//进行回溯
		ret.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return _all_path;

		vector<int> tmp_path;
		FindPath(tmp_path, root, sum);

		return _all_path;
	}

	vector<vector<int>> _all_path;
};

int main()
{


	return 0;
}