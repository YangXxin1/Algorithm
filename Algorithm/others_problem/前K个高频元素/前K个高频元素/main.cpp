#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>

using namespace std;

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> ret;

		unordered_map<int, int> m;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			m[nums[i]]++;//统计次数
		}

		//小堆
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
		//priority_queue<pair<int, int>> q;

		for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
		{
			if (q.size() == k)
			{
				if (it->second > q.top().first)
				{
					q.pop();
					q.push(make_pair(it->second, it->first));
				}
			}
			else
			{
				q.push(make_pair(it->second, it->first));//按出现的次数排序
			}
		}

		while (!q.empty())
		{
			ret.push_back(q.top().second);
			q.pop();
		}

		//reverse(ret.begin(), ret.end());

		return ret;
	}
};

int main()
{


	return 0;
}