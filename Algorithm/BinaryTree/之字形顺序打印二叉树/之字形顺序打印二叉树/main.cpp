#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ret;

		if (root == nullptr)
			return ret;

		stack<TreeNode*> st;//��������ÿ�α����Ľ��
		queue<TreeNode*> q;//��������

		vector<int> tmp;//����ÿһ�еĽ��
		st.push(root);//��������

		//��flag�����ƴ�ӡ����
		//1. ��ʾ�������ҽ��²�����ջ, ��ջ��˳���Ǵ�������
		//2. ��ʾ���������²�����ջ, ��ջ��˳���Ǵ�������
		int flag = 1;
		while (!st.empty())
		{
			int len = st.size();
			for (int i = 0; i < len; ++i)
			{
				TreeNode* cur = st.top();//ѭ���ó�ջ�����н��
				st.pop();

				tmp.push_back(cur->val);

				TreeNode* first = (flag == 1) ? cur->left : cur->right;
				TreeNode* second = (flag == 1) ? cur->right : cur->left;

				//��һ��Ľ��˳���븨������
				if (first)
					q.push(first);

				if (second)
					q.push(second);
			}

			ret.push_back(tmp);//����ÿһ��Ľ��

			while (!q.empty())
			{
				//ÿһ�㰴˳����ջ, ���´�ѭ�����ջ����ʼȡ���
				//������������ջ, ���´δ��������ջ
				//��֮, ������������ջ, ���´δ������ҳ�ջ
				//Ҳ���ǽ������н������Ĺ���
				st.push(q.front());
				q.pop();
			}

			tmp.clear();
			flag = (flag == 1) ? 2 : 1;//�����´�ѭ������
		}

		return ret;
	}
};

int main()
{

	return 0;
}