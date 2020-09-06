#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ret;

		if (matrix.size() == 0)
			return ret;

		int up = 0, left = 0;
		int down = matrix.size() - 1;
		int right = matrix[0].size() - 1;

		while (up <= down && left <= right)
		{
			//������
			for (int j = left; j <= right; ++j)
				ret.push_back(matrix[up][j]);

			//���ϵ���
			for (int i = up + 1; i <= down; ++i)
				ret.push_back(matrix[i][right]);

			if (left < right && up < down)
			{
				//���ҵ���
				for (int j = right - 1; j >= left; --j)
					ret.push_back(matrix[down][j]);

				//ע����һ���Ǵ�left��ʼ��, ��������ѭ����ֹ������i > up
				for (int i = down - 1; i > up; --i)
					ret.push_back(matrix[i][left]);
			}
			++up;
			++left;
			--right;
			--down;
		}
		return ret;
	}
};

int main()
{

	return 0;
}