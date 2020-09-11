#include <iostream>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		int high = n / 10, low = 0;//��cur��ǰλ�����ַָ�, ���Ϊ��λ, �ұ�Ϊ��λ
		//ע����long��ֹ���
		long digit = 1;//��ʾ��λ, 1�����λ, 10����ʮλ...
		int cur = n % 10;//cur��ʾ��ǰΪ����
		int count = 0;

		while (high || cur)
		{
			if (cur == 0)
				count = count + high * digit;
			else if (cur == 1)
				count = count + (high * digit) + low + 1;
			else
				count = count + (high + 1) * digit;
			n /= 10;
			high = n / 10;
			low = low + cur * digit;
			digit *= 10;
			cur = n % 10;
		}

		return count;
	}
};

int main()
{


	return 0;
}