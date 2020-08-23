#include <iostream>
#include <string>
#include <vector>

using namespace std;

//公共字符串计算
int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int len1 = str1.size();
		int len2 = str2.size();

		int max = 0;//用来保存最大的结果

		vector<vector<int>> v(len2, vector<int>(len1, 0));
		for (int i = 0; i < len2; ++i)
		{
			for (int j = 0; j < len1; ++j)
			{
				if (str2[i] == str1[j])
				{
					if (i >= 1 && j >= 1)
					{
						v[i][j] = v[i - 1][j - 1] + 1;
					}
					else
						v[i][j] = 1;
				}
				if (v[i][j] > max)
					max = v[i][j];
			}
		}
		cout << max << endl;
	}

	return 0;
}