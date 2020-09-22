#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> ret;
		if (a.size() == 0)
			return ret;

		int len = a.size();
		ret.resize(len, 1);

		//��������, ��������a�е�ֵΪ1, 2, 3, 4, 5
		//      ��Ӧret�е�ֵret[0]=1* 2* 3* 4* 5
		//                  ret[1]=1* 1* 3* 4* 5
		//                  ret[2]=1* 2* 1* 4* 5
		//                  ret[3]=1* 2* 3* 1* 5
		//                  ret[4]=1* 2* 3* 4* 1
		//���Թ۲쵽�Խ���ȫΪ1, �ԶԽ���Ϊ�ָ���, �����Ϊ�����Ǻ�������

		//�ȼ��������ǲ���, ��ret�е�ֵ���и���
		for (int i = 1; i < len; ++i)
			ret[i] = ret[i - 1] * a[i - 1];

		//�ټ��������ǲ���
		int tmp = 1;//����ʱ��������������ÿһ�г˻�
		for (int i = len - 2; i >= 0; --i)
		{
			tmp *= a[i + 1];//����tmp��ֵ
			ret[i] *= tmp;
		}

		return ret;
	}
};

int main()
{

	return 0;
}