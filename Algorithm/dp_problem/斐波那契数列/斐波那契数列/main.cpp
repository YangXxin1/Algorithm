#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		// �ݹ�
		/*if (n == 0)
		return 0;
		if (n == 1 || n == 2)
		return 1;
		return Fibonacci(n - 2) + Fibonacci(n - 1);*/

		// ��̬�滮
		/*int dp[40] = {0};
		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2; i < 40; ++i)
		{
		dp[i] = dp[i - 2] + dp[i - 1];
		}
		return dp[n];*/

		//�ݹ鸴�ӶȽϸ�, ��������map���м�֦, �������н����map��
		//����ʡȥ�ݹ��ظ�����Ľ��
		//mapΪ key-valģ��
		//��Ӧ n-��n��쳲�������
		//��һ��, map�ײ�Ϊ�����, ����Ч�ʵ��ڹ�ϣ
		//���ǿ���ѡ��unordered_map
		if (n == 0 || n == 1)
			return n;
		int prev;
		int post;
		if (_m.find(n - 2) != _m.end())
		{
			prev = _m[n - 2];
		}
		else
		{
			prev = Fibonacci(n - 2);
			_m[n - 2] = prev;
		}
		if (_m.find(n - 1) != _m.end())
		{
			post = _m[n - 1];
		}
		else
		{
			post = Fibonacci(n - 1);
			_m[n - 1] = post;
		}
		return prev + post;
	}
private:
	unordered_map<int, int> _m;
};

int main()
{
	return 0;
}