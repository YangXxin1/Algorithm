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
		需要额外开辟空间每次保存左右子树序列
		可以优化
		使用子函数进行递归判断, 在递归函数中每次传入判断的区间, 则不需要而外开辟空间
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