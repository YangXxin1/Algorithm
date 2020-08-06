#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	*
	* @param m int整型
	* @param n int整型
	* @return int整型
	*/
	int uniquePaths(int m, int n) {
		// write code here
		if (m < 0 || n < 0)
			return 0;
		//注意要给v开空间
		//m行, n列
		vector<vector<int>> v(m, vector<int>(n, 1));

		//定义状态: F(i,j)表示从(0,0)到(i,j)的不同路径数
		//动态转移方程F(i,j)=F(i - 1, j) + F(i, j - 1);
		//返回值: F(m-1, n-1)
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				/*if (i == 0)
				v[0][j] = 1;
				else if (j == 0)
				v[i][0] = 1;
				else*/
				//初始化v时,全为1,省去给第一行第一列的赋值
				//注意双循环的起始也要改为从第二行第二列开始
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m - 1][n - 1];
	}
};

int main()
{

	return 0;
}