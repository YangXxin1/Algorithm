#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int strToInt(string str) {
		//���ȶ��ַ������д���
		int i = 0;
		int len = (int)str.size();
		int flag = 1;

		//�����ո��ַ�
		while (str[i] == ' ')
			++i;

		//ȷ������
		if (str[i] == '-')
			flag = -1;
		if (str[i] == '+' || str[i] == '-')
			++i;

		//�޷�������Чת��
		if (str[i] < '0' || str[i] > '9')
			return 0;

		int res = 0;//������¼ת�����
		int boundary_val = INT_MAX / 10;//Ϊ�˷����Խ����������ж�, ��������һ���߽�ֵ
		// INT_MAX = 2147483647
		// INT_MAX / 10 = 214748364
		// �ɴ˿��Եõ�
		// res * 10 >= 2147483650 ʱһ����Խ��, ��ʱ�� res > 214748364
		// res * 10 == 2147483640 ʱ, �� tmp > 7, ��Խ��, ��ʱ res == 214748364
		while (i < len)
		{
			if (str[i] < '0' || str[i] > '9')
				break;
			int tmp = str[i] - '0';
			//Խ���ж�
			if (res > boundary_val || (res == boundary_val && tmp > 7))
			{
				if (flag == -1)
					return INT_MIN;
				else
					return INT_MAX;
			}
			res = res * 10 + tmp;
			++i;
		}
		return flag * res;
	}
};


int main()
{


	return 0;
}