#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int len = prices.size();
		//典型动态规划问题
		//[7, 1, 5, 3, 6, 4]
		//用dp[i]表示以i为结尾的子数组的最大利润(换句话说就是第i日卖出可获得的最大利润为多少)
		//动态转移方程 dp[i] = max(dp[i - 1], prices[i] - min(min_cost, prices[i]))
		//min_cost表示从[0, i]中的最小值
		//初始化 dp[0] = 0; 即首日利润为0
		vector<int> dp(len, 0);
		dp[0] = 0;
		int min_cost = prices[0];
		for (int i = 1; i < len; ++i)
		{
			dp[i] = max(dp[i - 1], prices[i] - min(min_cost, prices[i]));
			if (prices[i] < min_cost)
				min_cost = prices[i];
		}

		return dp[len - 1];
	}
};

int main()
{

	return 0;
}