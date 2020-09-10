#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;

		int len = prices.size();
		//���Ͷ�̬�滮����
		//[7, 1, 5, 3, 6, 4]
		//��dp[i]��ʾ��iΪ��β����������������(���仰˵���ǵ�i�������ɻ�õ��������Ϊ����)
		//��̬ת�Ʒ��� dp[i] = max(dp[i - 1], prices[i] - min(min_cost, prices[i]))
		//min_cost��ʾ��[0, i]�е���Сֵ
		//��ʼ�� dp[0] = 0; ����������Ϊ0
		vector<int> dp(len, 0);
		dp[0] = 0;
		int min_cost = prices[0];
		for (int i = 1; i < len; ++i)
		{
			dp[i] = max(dp[i - 1], prices[i] - min(min_cost, prices[i]));
			if (prices[i] < min_cost)
				min_cost = prices[i];
		}

		return dp[len - 1];
	}
};

int main()
{

	return 0;
}