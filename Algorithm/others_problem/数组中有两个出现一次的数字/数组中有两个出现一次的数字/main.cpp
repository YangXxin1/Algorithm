#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> singleNumbers(vector<int>& nums) {
		vector<int> ret(2, 0);
		if (nums.size() == 0)
			return ret;

		int len = nums.size();
		int tmp = 0;
		for (int i = 0; i < len; ++i)
			tmp ^= nums[i];

		int pos = 0;
		int j = 0;
		while ((tmp & (1 << pos)) == 0)
			++pos;

		int a1 = 0, a2 = 0;
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] & (1 << pos))
				a1 ^= nums[i];
			else
				a2 ^= nums[i];
		}

		ret[0] = a1;
		ret[1] = a2;

		return ret;
	}
};

int main()
{

	return 0;
}