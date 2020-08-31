#include <vector>

using namespace std;

//输入一个非空整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
class Solution {
public:
	bool _VerifySquenceOfBST(vector<int>& v, int begin, int end)
	{
		if (begin >= end)
			return true;
		int root = v[end];
		int i = begin;
		//先判断左子树序列是否满足条件(< root)
		while (i < end && v[i] < root)
			++i;
		int j = i;
		for (; j < end; ++j)
		{
			if (v[j] < root)
				return false;
		}
		return _VerifySquenceOfBST(v, begin, i - 1) && _VerifySquenceOfBST(v, i, end - 1);
	}

	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;

		return _VerifySquenceOfBST(sequence, 0, sequence.size() - 1);
	}
};

int main()
{

	return 0;
}