#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		if (pushed.empty() && popped.empty())
			return true;

		if (pushed.empty() || popped.empty())
			return false;

		int len1 = pushed.size();
		int len2 = popped.size();

		stack<int> s;
		int j = 0;
		for (int i = 0; i < len1; ++i)
		{
			s.push(pushed[i]);

			//���ｫpopped�е������븨��ջ���Ƚ�
			//�븨��ջ����ͬ�ͽ�ջ��Ԫ�ص���
			//����Ҫע��ĳЩ�������
			//����[1, 0] [1, 0]
			//���������һ�ν�Ԫ��1��ջ
			//ջ��Ԫ�ش�ʱ��popped[0]��ͬ, ��ջ
			//��ʱ����ջΪ��, �ڽ���pop�����ͻ����
			//����ж�������Ҫ��ջ�����пղ���
			while (j < len2 && !s.empty() && s.top() == popped[j])
			{
				s.pop();
				++j;
			}
		}

		return s.empty();
	}
};

int main()
{


	return 0;
}