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
		//˫ָ��ⷨ
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

		//�Ż�˫ָ�뷨�����ù�ϣ����ÿ���ַ���Ӧ���±�
		//ʹ��ͷָ���ƶ�ʱ�������ƶ�����ֱ���ڹ�ϣ���в���
		//�ҵ������ظ��ַ���λ�ã���ͷָ����ת����λ�õ���һ��λ��
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
				//����Ҫע����ǣ���ϣ���п��ܻ���ڶ���ظ�Ԫ�أ�ע���ж�head��λ��
				//������max�����ж�head��um[tmp] + 1�Ĵ�С��ϵ�Ϳ������ҵ�ǰ��ȥ��
				head = max(head, um[tmp] + 1);

			//ע���ڹ�ϣ����û���ҵ��ظ�Ԫ�ص�ʱ��ҲҪ����ӳ���ϵ
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