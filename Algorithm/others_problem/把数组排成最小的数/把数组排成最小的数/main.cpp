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

		//��ԭ�����е�Ԫ��ת��Ϊ�ַ���
		vector<string> v;
		for (int i = 0; i < (int)nums.size(); ++i)
			v.push_back(to_string(nums[i]));

		// ���罫�ַ��� s1, s2����ƴ��
		// s1 + s2 > s2 + s1, ��˵�� s1 > s2
		// s1 + s2 < s2 + s1, ��˵�� s1 < s2
		// ���� "36" "38", "3638" < "3836"(s1 + s2 < s2 + s1)
		// s1 < s2;
		// ��������, ������Ҫ���� s1 < s2 �����(����Ҫ����������С��)
		// �� s1 + s2 < s2 + s1

		// ע��һ��ʹ��lambda���ʽд�ıȽϹ���
		// ����Ҫ��֤���� s1 + s2 < s2 + s1
		// �ⲻ��ͬ�� s1 < s2
		// ���� "3" < "30"
		// ���� "330" > "303"
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