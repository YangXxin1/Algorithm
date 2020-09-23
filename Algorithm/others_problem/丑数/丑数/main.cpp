#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n);

		//动态规划问题
		//初始化, 习惯将1作为第一个丑数
		dp[0] = 1;

		int a = 0, b = 0, c = 0;

		//设丑数的序列为x1, x2, ..., xn
		//现在求x(n+1)
		// x(n + 1) = x(a) * 2, a in [1, n]
		// x(n + 1) = x(b) * 3, b in [1, n]
		// x(n + 1) = x(c) * 3, c in [1, n]

		// x(a) * 2 > x(n) >= x(a - 1) * 2, 即x(a)是首个乘2后大于x(n)的丑数
		// x(b) * 3 > x(n) >= x(b - 1) * 3, 即x(b)是首个乘3后大于x(n)的丑数
		// x(c) * 5 > x(n) >= x(c - 1) * 2, 即x(c)是首个乘5后大于x(n)的丑数

		//动态转移方程dp[i] = min(min(dp[i - 1] * 2, dp[i - 1] * 3), dp[i - 1] * 5)
		for (int i = 1; i < n; ++i)
		{
			int n1 = dp[a] * 2;
			int n2 = dp[b] * 3;
			int n3 = dp[c] * 5;

			dp[i] = min(min(n1, n2), n3);

			if (dp[i] == n1)
				++a;
			if (dp[i] == n2)
				++b;
			if (dp[i] == n3)
				++c;
		}
		return dp[n - 1];
	}
};

int main()
{

	return 0;
}

