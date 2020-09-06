#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
	bool chisexist(string& s, char c, int begin, int end)
	{
		for (int i = begin; i <= end; ++i)
		{
			if (s[i] == c)
				return true;
		}
		return false;
	}

	int lengthOfLongestSubstring(string s) {
		//双指针解法
		//if (s.size() == 0)
		//	return 0;
		//if (s.size() == 1)
		//	return 1;

		//int len = s.size();

		//int head = 0, tail = 1;
		//int ret = 1;
		//while (tail < len)
		//{
		//	if (!chisexist(s, s[tail], head, tail - 1))
		//		ret = max(ret, tail - head + 1);

		//	else
		//	{
		//		while (chisexist(s, s[tail], head, tail - 1))
		//			head++;
		//	}

		//	tail += 1;
		//}
		//return ret;

		//优化双指针法，利用哈希保存每个字符对应的下标
		//使得头指针移动时不用逐步移动，可直接在哈希表中查找
		//找到出现重复字符的位置，让头指针跳转到该位置的下一个位置
		if (s.size() == 0)
			return 0;
		if (s.size() == 1)
			return 1;

		int len = s.size();

		unordered_map<char, int> um;
		int head = 0, tail = 0;
		int ret = 1;

		while (tail < len)
		{
			char tmp = s[tail];
			if (um.find(tmp) != um.end())
				//这里要注意的是，哈希表中可能会存在多个重复元素，注意判断head的位置
				//不适用max函数判断head和um[tmp] + 1的大小关系就可能又找到前面去了
				head = max(head, um[tmp] + 1);

			//注意在哈希表中没有找到重复元素的时候也要建立映射关系
			um[tmp] = tail;
			ret = max(ret, tail - head + 1);
			tail++;
		}
		return ret;
	}
};

int main()
{


	return 0;
}