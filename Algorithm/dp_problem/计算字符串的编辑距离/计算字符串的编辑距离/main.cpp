#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//�����ַ����ı༭����
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();

		vector<vector<int>> v(len1 + 1, vector<int>(len2 + 1, 0));

		//��ʼ��
		for (int i = 0; i <= len1; ++i)
			v[i][0] = i;
		for (int j = 0; j <= len2; ++j)
			v[0][j] = j;

		for (int i = 1; i <= len1; ++i)
		{
			for (int j = 1; j <= len2; ++j)
			{
				//ע���Ǵӵ�0���ַ���ʼ�Ƚ�
				if (str1[i - 1] == str2[j - 1])
				{
					v[i][j] = min(v[i - 1][j], v[i][j - 1]) + 1;
					v[i][j] = min(v[i][j], v[i - 1][j - 1]);
				}
				else
				{
					v[i][j] = min(v[i - 1][j], v[i][j - 1]) + 1;
					v[i][j] = min(v[i][j], v[i - 1][j - 1] + 1);
				}
			}
		}
		cout << v[len1][len2] << endl;
	}

	return 0;
}