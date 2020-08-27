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
	//DFS������ȱ���
	void FindPath(vector<int>& ret, TreeNode* root, int sum)
	{
		//��ǰ���Ϊ��, ��ֹ�ݹ�
		if (root == nullptr)
			return;

		int num = root->val;
		sum -= num;
		ret.push_back(root->val);

		//���ҽ���Ϊ��,��ʾ��ǰ���ΪҶ�ӽ��
		if (root->left == nullptr && root->right == nullptr && sum == 0)
		{
			//ע��������������֮�󻹲���return
			//��Ӱ��������
			_all_path.push_back(ret);
		}

		FindPath(ret, root->left, sum);
		FindPath(ret, root->right, sum);
		//���л���
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