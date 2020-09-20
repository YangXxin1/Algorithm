#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxValue(vector<vector<int>>& grid) {
		//利用动态规划来解
		if (grid.size() == 0)
			return 0;
		int row = grid.size();
		int col = grid[0].size();

		//初始化
		for (int j = 1; j < col; ++j)
			grid[0][j] += grid[0][j - 1];

		for (int i = 1; i < row; ++i)
			grid[i][0] += grid[i - 1][0];

		for (int i = 1; i < (int)grid.size(); ++i)
		{
			for (int j = 1; j < (int)grid[0].size(); ++j)
			{
				grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
			}
		}

		return grid[row - 1][col - 1];
	}
};

int main()
{

	system("pause");
	return 0;
}