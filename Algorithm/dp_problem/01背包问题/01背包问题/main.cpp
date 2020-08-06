#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		int row = A.size() + 1;
		int col = m + 1;
		vector<vector<int>> max_val(row, vector<int>(col, 0));

		//定义状态: F(i,j)表示背包大小为j放入i个商品的最大价值
		//动态转义方程: 
		//如果 A[i - 1] > j,这表示第i个商品无法放入背包,因此F(i,j)=F(i-1,j)
		//反之 A[i - 1] <= j,表明第i个商品可以放入背包, 那么对于第i个商品有两种选择
		//放或者是不放
		//若不放第i个商品,退化为上一状态F(i-1,j)
		//若放入第i个商品,要给背包留出A[i-1]的空间大小
		//即F(i,j)=max(F(i-1,j),F(i, j-A[i - 1])+V[i - 1]);
		if (A.empty() || V.empty())
			return 0;

		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				if (j < A[i - 1])
					max_val[i][j] = max_val[i - 1][j];
				else
				{
					max_val[i][j] = max(max_val[i - 1][j], max_val[i - 1][j - A[i - 1]] + V[i - 1]);
				}
			}
		}
		return max_val[row - 1][col - 1];
	}
};

int main()
{
	return 0;
}