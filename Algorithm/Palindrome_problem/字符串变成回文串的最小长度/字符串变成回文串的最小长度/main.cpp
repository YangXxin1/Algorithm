#include <iostream>
#include <string>

using namespace std;

//�жϻ��Ĵ�
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
			//ÿ���ж�����[i, len - 1]����
			//���� abc
			//abc ���ǻ��Ĵ�, �ں������a -->  abca
			//��ʱa��a���ɻ���, �����Ҫ�ж�bc�Ƿ��ǻ��Ĵ�
			//bc ���ǻ���, �����Դ�ַ��������ba  -->  abcba
			//��ʱab��ba���ɻ���, ����ж�c�Ƿ����
			//�����ַ����ɻ���
			//���շ��صĻ��Ĵ�����Ϊ 5
			if (isPalindrome(str.substr(i, length - i)))
				break;
			++count;
		}
		count += length;
		cout << count << endl;
	}

	return 0;
}