#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		//����һ : �������¸���
		//����״̬: F(i, j)��ʾ��(0, 0)���(i, j)����С·����
		//F(i, j) = min(F(i - 1, j), F(i - 1, j - 1)) + v[i][j];
		//F(i, 0) = F(i - 1, 0) + v[i][0]
		//F(i, i) = F(i - 1, i - 1) + V[i][i]
		/*
		int row = triangle.size();
		if (row == 0)
			return 0;
		for (int i = 1; i < row; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0)
					triangle[i][j] += triangle[i - 1][0];
				else if (j == i)
					triangle[i][j] += triangle[i - 1][j - 1];
				else
					triangle[i][j] = min(triangle[i - 1][j], triangle[i - 1][j - 1]) + triangle[i][j];
			}
		}
		int result = triangle[row - 1][0];
		for (int j = 1; j < row; ++j)
		{
			if (triangle[row - 1][j] < result)
				result = triangle[row - 1][j];
		}
		return result;
		*/

		//������: �������ϸ���
		//����Ϸ���һ�����
		int row = triangle.size();
		if (row == 0)
			return 0;
		//F(i, j) = min(F(i + 1, j), F(i + 1, j + 1)) + v[i][j]
		for (int i = row - 2; i >= 0; --i)
		{
			for (int j = 0; j <= i; ++j)
			{
				triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return triangle[0][0];
	}
};

int main()
{

	return 0;
}