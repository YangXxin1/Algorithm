#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		// 递归
		/*if (n == 0)
		return 0;
		if (n == 1 || n == 2)
		return 1;
		return Fibonacci(n - 2) + Fibonacci(n - 1);*/

		// 动态规划
		/*int dp[40] = {0};
		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i < 40; ++i)
		{
		dp[i] = dp[i - 2] + dp[i - 1];
		}
		return dp[n];*/

		//递归复杂度较高, 可以利用map进行剪枝, 保存已有结果在map中
		//可以省去递归重复计算的结果
		//map为 key-val模型
		//对应 n-第n项斐波那契数
		//进一步, map底层为红黑树, 搜索效率低于哈希
		//我们可以选择unordered_map
		if (n == 0 || n == 1)
			return n;
		int prev;
		int post;
		if (_m.find(n - 2) != _m.end())
		{
			prev = _m[n - 2];
		}
		else
		{
			prev = Fibonacci(n - 2);
			_m[n - 2] = prev;
		}
		if (_m.find(n - 1) != _m.end())
		{
			post = _m[n - 1];
		}
		else
		{
			post = Fibonacci(n - 1);
			_m[n - 1] = post;
		}
		return prev + post;
	}
private:
	unordered_map<int, int> _m;
};

int main()
{
	return 0;
}