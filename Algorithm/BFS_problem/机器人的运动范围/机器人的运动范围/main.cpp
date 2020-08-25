#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
	//获取数位之和
	int getCount_NUm(int num)
	{
		if (num < 10)
			return num;
		int ret = 0;
		while (num)
		{
			ret = ret + num % 10;
			num /= 10;
		}
		return ret;
	}
public:
	int movingCount(int m, int n, int k) {
		int count = 0;//用来统计可以到达的格子数量

		//这里我们使用BFS, 广度优先遍历方法
		//广度优先常利用队列, 保存当前状态, 用当前状态去推它能够到达的所有状态再择优
		//队列当中保存当前所处坐标位置
		queue<pair<int, int>> q;
		q.push({ 0, 0 });//将(0, 0)入队, 表示从(0, 0)出发

		vector<vector<int>> map(m, vector<int>(n, 0));//给定地图
		while (!q.empty())
		{
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			if (row < 0 || row >= m || col < 0 || col >= n
				|| getCount_NUm(row) + getCount_NUm(col) > k || map[row][col] == 1)
				continue;
			map[row][col] = 1;//将走过的方格置为1
			q.push({ row + 1, col });//向下走
			q.push({ row, col + 1 });//向右走
			++count;
		}

		return count;
	}
};

int main()
{

	return 0;
}