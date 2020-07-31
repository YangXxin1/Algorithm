#include <iostream>
#include <vector>

using namespace std;

//DFS���
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
		//�ݹ���ֹ����
		if (root == nullptr)
		{
			return;
		}
		int val = root->val;
		expectNumber -= val;
		tmp.push_back(root->val);//��ֵ��ӵ���ʱ�����
		if (root->left == nullptr && root->right == nullptr && expectNumber == 0)
		{
			ret.push_back(tmp);//����������·����ӵ����ս������
			//�����������֮����return,��ΪҪ����
		}

		_FindPath(root->left, expectNumber, ret, tmp);
		_FindPath(root->right, expectNumber, ret, tmp);

		tmp.pop_back();//����
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		vector<vector<int>> ret;//���ս����
		vector<int> tmp;//��ʱ�����

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