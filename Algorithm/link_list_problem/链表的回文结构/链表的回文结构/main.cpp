#include <iostream>
#include <stack>

using namespace std;

//链表的回文结构
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		//方法一:使用数组保存链表中对应的val
		//遍历数组结果看是否回文
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

		//方法二:使用栈
		//遍历链表将链表所有结点对应值入栈
		//出栈时对比链表中的值
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