#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;

		int ret = 0;
		for (int i = 0; i < 32; ++i)
		{
			int count = 0;
			for (int j = 0; j < (int)nums.size(); ++j)
			{
				if (nums[j] & (1 << i))
					++count;
			}
			if (count % 3 == 1)
			{
				ret |= (1 << i);
			}
		}
		return ret;
	}
};

int main()
{

	return 0;
}


