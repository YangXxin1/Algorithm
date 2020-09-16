#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
	int translateNum(int num) {
		//��̬�滮����
		//F(i)��ʾ�Ե�iλΪ��β��ǰ׺���ж����ֲ�ͬ�ķ��뷽��
		//i > 0, �����i - 1λ���iλ��ɵ�����10 <= x <= 25
		//˵��
		//��ʱf(i) = f(i - 1) + f(i - 2)
		//��֮, ���ǲ�������һ����, Ҳ����˵��iλ��Ҫ��������, ��ʱf(i) = f(i - 1)

		//����ת��Ϊ�ַ���
		string str = to_string(num);
		int len = str.size();

		//�Ż��ռ临�Ӷ�, ��ȥ���ٶ���ռ�
		int ret = 1;//������, Ĭ��Ϊ1, ��Ϊֻ��һ������, ������������forѭ��, ֱ�ӷ���1
		//��ʼ��
		int a1 = 1;
		int a2 = 1;
		for (int i = 1; i< len; ++i)
		{
			int tmp = (str[i - 1] - '0') * 10 + (str[i] - '0');
			//f(i) = f(i - 1) + f(i - 2)
			if (tmp >= 10 && tmp <= 25)
				ret = a1 + a2;//��i - 1λ���iλ��������һ����, ���ҵ�iλҲ���Ե�������
			else
				ret = a2;//��iλ��Ҫ��������, ��ʱf(i) = f(i - 1)
			a1 = a2;
			a2 = ret;
		}
		return ret;
	}
};

int main()
{

	return 0;
}