#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void getMaxVal(vector<vector<int>>& grid, int row, int col, int& global, int tmp)
	{
		if (row == grid.size() - 1 && col == grid[0].size() - 1)
		{
			tmp += grid[row][col];
			if (tmp > global)
				global = tmp;
			return;
		}

		if (row < 0 || row >= (int)grid.size() || col < 0 || col >= (int)grid[0].size())
			return;

		tmp += grid[row][col];

		getMaxVal(grid, row + 1, col, global, tmp);
		getMaxVal(grid, row, col + 1, global, tmp);
	}

	int maxValue(vector<vector<int>>& grid) {
		//DFS深度优先遍历
		//数据量过大时会导致栈溢出
		int global = 0, tmp = 0;
		getMaxVal(grid, 0, 0, global, tmp);

		return global;
	}
};

int main()
{

	system("pause");
	return 0;
}