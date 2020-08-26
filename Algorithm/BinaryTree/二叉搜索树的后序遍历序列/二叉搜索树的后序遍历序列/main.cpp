#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool _verifyPostorder(vector<int>& postorder, int left, int right)
	{
		if (left >= right)
			return true;

		int root = postorder[right];
		int i = 0;
		for (; i < right && postorder[i] < root; ++i);
		int mid = i;
		while (i < right)
		{
			if (postorder[i] < root)
				return false;
			++i;
		}

		return _verifyPostorder(postorder, left, mid - 1) && _verifyPostorder(postorder, mid, right - 1);
	}

	bool verifyPostorder(vector<int>& postorder) {
		/*
		��Ҫ���⿪�ٿռ�ÿ�α���������������
		�����Ż�
		ʹ���Ӻ������еݹ��ж�, �ڵݹ麯����ÿ�δ����жϵ�����, ����Ҫ���⿪�ٿռ�
		if ((postorder.size() == 1) || (postorder.size() == 0))
		return true;
		int len = postorder.size() - 1;
		int root = postorder[len];

		int i = 0;
		vector<int> left;
		vector<int> right;
		for (; (i < len) && (postorder[i] < root); ++i)
		{
		left.push_back(postorder[i]);
		}

		while (i < len)
		{
		if (postorder[i] < root)
		return false;
		right.push_back(postorder[i]);
		++i;
		}

		return verifyPostorder(left) && verifyPostorder(right);
		*/
		int len = postorder.size() - 1;
		return _verifyPostorder(postorder, 0, len);
	}
};

int main()
{


	return 0;
}