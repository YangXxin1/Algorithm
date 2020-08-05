#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		//定义状态: f(i)表示字符串s的前i个字符是否可以被分割
		//状态转移方程: j < i && f(j) && [j + 1, i]
		//为了确定f(i), 我们要先去看它的子问题, 也就是要确定f(0)-f(i- 1)是否
		//可以被分割, 若可以, 接下来要确定的就是[j + 1, i]是否可以在
		//字典中找到, 可以找到则f(i)可以被分割, 反之不可以被分割

		if (s.empty())
		{
			return false;
		}
		if (dict.empty())
		{
			return false;
		}
		size_t len = s.size();
		vector<bool> canBreak(len + 1, false);
		//初始化, 表示一个辅助状态, 也就是将空串记为true
		canBreak[0] = true;

		for (int i = 1; i <= len; ++i)
		{
			for (int j = i - 1; j >= 0; --j)//j < i
			{
				if (canBreak[j] && (dict.find(s.substr(j, i - j)) != dict.end()))
				{
					canBreak[i] = true;
					break;
				}
			}
		}
		return canBreak[len];
	}
};

int main()
{

	return 0;
}