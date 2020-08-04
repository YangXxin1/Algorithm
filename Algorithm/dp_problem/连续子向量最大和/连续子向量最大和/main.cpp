#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		//����״̬ f(i)��ʾ��i��β���������������������
		//����{6,-3,-2,7,-15,1,2,2}�������
		//f(3)�ͱ�ʾ��7��β������������������
		//��7��β��������������{7},{-2,7},{-3,-2,7},{6,-3,-2,7}
		//�ɴ����ǿ���֪��f(i) = max(f(i - 1) + array[i], array[i]);

		if (array.empty())
			return 0;
		int local_max = array[0];//�ֲ�����
		int max_sum = array[0];//ȫ������

		for (size_t i = 1; i < array.size(); ++i)
		{
			local_max = max(local_max + array[i], array[i]);
			if (local_max > max_sum)
				max_sum = local_max;
		}
		return max_sum;
	}
};

int main()
{
	return 0;
}