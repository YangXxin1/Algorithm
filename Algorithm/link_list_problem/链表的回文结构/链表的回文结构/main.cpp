#include <iostream>
#include <stack>

using namespace std;

//����Ļ��Ľṹ
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		//����һ:ʹ�����鱣�������ж�Ӧ��val
		//�������������Ƿ����
		//if (A == nullptr || A->next == nullptr)
		//	return false;
		//int v[901];
		//ListNode* node = A;
		//int k = 0;
		//while (node->next)
		//{
		//	v[k++] = node->val;
		//	node = node->next;
		//}
		//v[k++] = node->val;

		//for (int i = 0, j = k - 1; i < j; ++i, --j)
		//{
		//	if (v[i] != v[j])
		//		return false;
		//}
		//return true;

		//������:ʹ��ջ
		//���������������н���Ӧֵ��ջ
		//��ջʱ�Ա������е�ֵ
		if (A == nullptr || A->next == nullptr)
			return false;

		stack<int> st;

		ListNode* node = A;
		while (node)
		{
			st.push(node->val);
			node = node->next;
		}
		int len = st.size() / 2;
		while (!st.empty() && len)
		{
			if (st.top() != A->val)
				return false;
			st.pop();
			A = A->next;
			--len;
		}
		return true;
	}
};

int main()
{

	return 0;
}