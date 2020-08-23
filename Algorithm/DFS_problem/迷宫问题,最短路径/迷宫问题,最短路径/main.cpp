#include <iostream>
#include <vector>

using namespace std;

//DFS深度优先遍历

int row, col;//地图行和列
//保存临时路径
vector<vector<int>> temp_path;
//保存最佳路径
vector<vector<int>> best_path;
//地图
vector<vector<int>> map(row, vector<int>(col, 0));

void findMinPath(int i, int j)
{
	map[i][j] = 1;//将走过的路径置为1, 表示后面不可以再走了
	temp_path.push_back({ i, j });

	if (i == row - 1 && j == col - 1)
	{
		//表示已经走到最后
		if (best_path.empty() || best_path.size() > temp_path.size())
			best_path = temp_path;
	}

	if (i - 1 >= 0 && map[i - 1][j] == 0)//表示可以向上走
		findMinPath(i - 1, j);

	if (i + 1 < row && map[i + 1][j] == 0)//表示可以向下走
		findMinPath(i + 1, j);

	if (j - 1 >= 0 && map[i][j - 1] == 0)//表示可以向左走
		findMinPath(i, j - 1);

	if (j + 1 < col && map[i][j + 1] == 0)//表示可以向右走
		findMinPath(i, j + 1);

	//回溯
	map[i][j] = 0;
	temp_path.pop_back();
}

int main()
{
	while (cin >> row >> col)
	{
		map = vector<vector<int>>(row, vector<int>(col, 0));
		temp_path.clear();
		best_path.clear();
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cin >> map[i][j];
			}
		}

		findMinPath(0, 0);

		for (auto& i : best_path)
		{
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
		}
	}

	return 0;
}