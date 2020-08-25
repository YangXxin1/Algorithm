#include <iostream>
#include <string>

using namespace std;

//����
int GetNumRoot(int num)
{
	if (num <= 9)
		return num;
	int result = 0;
	while (num)
	{
		result = result + num % 10;
		num /= 10;
	}
	while (result > 9)
		result = GetNumRoot(result);
	return result;
}
int main()
{
	string str;
	while (cin >> str)
	{
		int num = 0;
		for (size_t i = 0; i < str.size(); ++i)
		{
			//��������λ�������
			num = str[i] - '0' + num;
		}
		int ret = GetNumRoot(num);

		cout << ret << endl;
	}


	return 0;
}