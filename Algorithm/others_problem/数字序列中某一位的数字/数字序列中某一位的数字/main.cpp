#include <iostream>

using namespace std;

//����������ĳһλ������
//01234567891011121314....
//0 1 2 3 4 5  6 7 8 9 10 11 12 13 14.....
class Solution {
public:
	int findNthDigit(int n) {
		long start = 1;//��1��ʼ
		int digit = 1;//��λΪ1
		long count = 9;//��λ��Ӧ�����ָ���

		while (n > count)
		{
			n -= count;
			start *= 10;//����λ��ȷ����ʼ����, ������λ����10��ʼ, ��λ����100��ʼ
			digit += 1;//λ��ÿ�μ�1
			count = 9 * start * digit;//������λ��Ӧ�����ָ���
		}

		int num = start + (n - 1) / digit;//�����n����������Ϊ����
		int tmp = (n - 1) % digit;//�����n�ڸ�������������λ��
		tmp = digit - tmp;//����λ����������, tmpΪ0��ʾ��num�ĵ�0λ, ��ʱҪģ����(digit��)�õ����
		//tmpΪ1,��ģ1�ο��Եõ����(dight - tmp)
		int ret = num;
		while (tmp--)
		{
			ret = num % 10;
			num /= 10;
		}
		return ret;
	}
};

int main()
{


	return 0;
}