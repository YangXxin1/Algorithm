#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string minNumber(vector<int>& nums) {
		string ret;
		if (nums.size() == 0)
			return ret;

		//将原数组中的元素转换为字符串
		vector<string> v;
		for (int i = 0; i < (int)nums.size(); ++i)
			v.push_back(to_string(nums[i]));

		// 假如将字符串 s1, s2进行拼接
		// s1 + s2 > s2 + s1, 这说明 s1 > s2
		// s1 + s2 < s2 + s1, 这说明 s1 < s2
		// 例如 "36" "38", "3638" < "3836"(s1 + s2 < s2 + s1)
		// s1 < s2;
		// 根据题意, 我们需要的是 s1 < s2 的情况(最终要所有数字最小的)
		// 即 s1 + s2 < s2 + s1

		// 注意一下使用lambda表达式写的比较规则
		// 我们要保证的是 s1 + s2 < s2 + s1
		// 这不等同于 s1 < s2
		// 比如 "3" < "30"
		// 但是 "330" > "303"
		sort(v.begin(), v.end(),
			[](string& s1, string& s2){return s1 + s2 < s2 + s1; });

		for (int i = 0; i < (int)v.size(); ++i)
			ret += v[i];

		return ret;
	}
};

int main()
{

	return 0;
}