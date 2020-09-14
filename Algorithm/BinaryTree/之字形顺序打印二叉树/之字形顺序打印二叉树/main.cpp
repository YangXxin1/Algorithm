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

		stack<TreeNode*> st;//用来保存每次遍历的结点
		queue<TreeNode*> q;//辅助队列

		vector<int> tmp;//保存每一行的结果
		st.push(root);//根结点入队

		//用flag来控制打印方向
		//1. 表示从左向右将下层结点入栈, 出栈的顺序即是从右向左
		//2. 表示从右向左将下层结点入栈, 出栈的顺序即是从左向右
		int flag = 1;
		while (!st.empty())
		{
			int len = st.size();
			for (int i = 0; i < len; ++i)
			{
				TreeNode* cur = st.top();//循环拿出栈中所有结点
				st.pop();

				tmp.push_back(cur->val);

				TreeNode* first = (flag == 1) ? cur->left : cur->right;
				TreeNode* second = (flag == 1) ? cur->right : cur->left;

				//下一层的结点顺序入辅助队列
				if (first)
					q.push(first);

				if (second)
					q.push(second);
			}

			ret.push_back(tmp);//保存每一层的结果

			while (!q.empty())
			{
				//每一层按顺序入栈, 则下次循环会从栈顶开始取结点
				//结点从左至右入栈, 则下次从右向左出栈
				//反之, 结点从右向左入栈, 则下次从左至右出栈
				//也就是将队列中结点逆序的过程
				st.push(q.front());
				q.pop();
			}

			tmp.clear();
			flag = (flag == 1) ? 2 : 1;//控制下次循环方向
		}

		return ret;
	}
};

int main()
{

	return 0;
}