#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		//定义状态 f(i)表示已i结尾的最大连续子向量的最大和
		//比如{6,-3,-2,7,-15,1,2,2}这个序列
		//f(3)就表示以7结尾的连续子向量的最大和
		//以7结尾的连续子向量有{7},{-2,7},{-3,-2,7},{6,-3,-2,7}
		//由此我们可以知道f(i) = max(f(i - 1) + array[i], array[i]);

		if (array.empty())
			return 0;
		int local_max = array[0];//局部最大和
		int max_sum = array[0];//全局最大和

		for (size_t i = 1; i < array.size(); ++i)
		{
			local_max = max(local_max + array[i], array[i]);
			if (local_max > max_sum)
				max_sum = local_max;
		}
		return max_sum;
	}
};

int main()
{
	return 0;
}