#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
public:
	void swap(string& s, int x, int y)
	{
		char tmp = s[x];
		s[x] = s[y];
		s[y] = tmp;
	}
	void dealString(vector<string>& ret, string& s, int pos)
	{
		if (pos == s.size() - 1)
		{
			//去重操作(剪枝)
			if (_s.find(s) == _s.end())
				ret.push_back(s);
			_s.insert(s);
			return;
		}

		for (int i = pos; i < (int)s.size(); ++i)
		{
			swap(s, i, pos);
			dealString(ret, s, pos + 1);
			swap(s, i, pos);
		}
	}

	vector<string> permutation(string s) {
		//字符串全排列问题
		//DFS深度优先遍历
		vector<string> ret;
		if (s.size() == 0)
			return ret;

		dealString(ret, s, 0);

		return ret;
	}

private:
	unordered_set<string> _s;
};

int main()
{

	return 0;
}