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
			//从左到右
			for (int j = left; j <= right; ++j)
				ret.push_back(matrix[up][j]);

			//从上到下
			for (int i = up + 1; i <= down; ++i)
				ret.push_back(matrix[i][right]);

			if (left < right && up < down)
			{
				//从右到左
				for (int j = right - 1; j >= left; --j)
					ret.push_back(matrix[down][j]);

				//注意下一次是从left开始的, 因此这里的循环终止条件是i > up
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