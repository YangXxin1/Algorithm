#include <vector>

using namespace std;

//����һ���ǿ��������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
class Solution {
public:
	bool _VerifySquenceOfBST(vector<int>& v, int begin, int end)
	{
		if (begin >= end)
			return true;
		int root = v[end];
		int i = begin;
		//���ж������������Ƿ���������(< root)
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