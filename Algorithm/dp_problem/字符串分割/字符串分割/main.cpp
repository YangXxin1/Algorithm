#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		//����״̬: f(i)��ʾ�ַ���s��ǰi���ַ��Ƿ���Ա��ָ�
		//״̬ת�Ʒ���: j < i && f(j) && [j + 1, i]
		//Ϊ��ȷ��f(i), ����Ҫ��ȥ������������, Ҳ����Ҫȷ��f(0)-f(i- 1)�Ƿ�
		//���Ա��ָ�, ������, ������Ҫȷ���ľ���[j + 1, i]�Ƿ������
		//�ֵ����ҵ�, �����ҵ���f(i)���Ա��ָ�, ��֮�����Ա��ָ�

		if (s.empty())
		{
			return false;
		}
		if (dict.empty())
		{
			return false;
		}
		size_t len = s.size();
		vector<bool> canBreak(len + 1, false);
		//��ʼ��, ��ʾһ������״̬, Ҳ���ǽ��մ���Ϊtrue
		canBreak[0] = true;

		for (int i = 1; i <= len; ++i)
		{
			for (int j = i - 1; j >= 0; --j)//j < i
			{
				if (canBreak[j] && (dict.find(s.substr(j, i - j)) != dict.end()))
				{
					canBreak[i] = true;
					break;
				}
			}
		}
		return canBreak[len];
	}
};

int main()
{

	return 0;
}