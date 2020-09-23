#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		vector<int> dp(n);

		//��̬�滮����
		//��ʼ��, ϰ�߽�1��Ϊ��һ������
		dp[0] = 1;

		int a = 0, b = 0, c = 0;

		//�����������Ϊx1, x2, ..., xn
		//������x(n+1)
		// x(n + 1) = x(a) * 2, a in [1, n]
		// x(n + 1) = x(b) * 3, b in [1, n]
		// x(n + 1) = x(c) * 3, c in [1, n]

		// x(a) * 2 > x(n) >= x(a - 1) * 2, ��x(a)���׸���2�����x(n)�ĳ���
		// x(b) * 3 > x(n) >= x(b - 1) * 3, ��x(b)���׸���3�����x(n)�ĳ���
		// x(c) * 5 > x(n) >= x(c - 1) * 2, ��x(c)���׸���5�����x(n)�ĳ���

		//��̬ת�Ʒ���dp[i] = min(min(dp[i - 1] * 2, dp[i - 1] * 3), dp[i - 1] * 5)
		for (int i = 1; i < n; ++i)
		{
			int n1 = dp[a] * 2;
			int n2 = dp[b] * 3;
			int n3 = dp[c] * 5;

			dp[i] = min(min(n1, n2), n3);

			if (dp[i] == n1)
				++a;
			if (dp[i] == n2)
				++b;
			if (dp[i] == n3)
				++c;
		}
		return dp[n - 1];
	}
};

int main()
{

	return 0;
}

