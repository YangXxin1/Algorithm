#include <iostream>
#include <string>

using namespace std;

//判断回文串
bool isPalindrome(const string& s)
{
	if (s.size() == 1)
		return true;
	int left = 0, right = s.size() - 1;
	while (left < right)
	{
		if (s[left] != s[right])
			return false;
		++left;
		--right;
	}
	return true;
}

int main()
{
	string str;
	while (cin >> str)
	{
		int count = 0;
		int length = str.size();
		for (int i = 0; i < length; ++i)
		{
			//每次判断区间[i, len - 1]即可
			//比如 abc
			//abc 不是回文串, 在后面添加a -->  abca
			//此时a和a构成回文, 因此需要判断bc是否是回文串
			//bc 不是回文, 因此在源字符串后添加ba  -->  abcba
			//此时ab和ba构成回文, 最后判断c是否回文
			//单个字符构成回文
			//最终返回的回文串长度为 5
			if (isPalindrome(str.substr(i, length - i)))
				break;
			++count;
		}
		count += length;
		cout << count << endl;
	}

	return 0;
}