#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/**
	*
	* @param m int����
	* @param n int����
	* @return int����
	*/
	int uniquePaths(int m, int n) {
		// write code here
		if (m < 0 || n < 0)
			return 0;
		//ע��Ҫ��v���ռ�
		//m��, n��
		vector<vector<int>> v(m, vector<int>(n, 1));

		//����״̬: F(i,j)��ʾ��(0,0)��(i,j)�Ĳ�ͬ·����
		//��̬ת�Ʒ���F(i,j)=F(i - 1, j) + F(i, j - 1);
		//����ֵ: F(m-1, n-1)
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				/*if (i == 0)
				v[0][j] = 1;
				else if (j == 0)
				v[i][0] = 1;
				else*/
				//��ʼ��vʱ,ȫΪ1,ʡȥ����һ�е�һ�еĸ�ֵ
				//ע��˫ѭ������ʼҲҪ��Ϊ�ӵڶ��еڶ��п�ʼ
				v[i][j] = v[i - 1][j] + v[i][j - 1];
			}
		}
		return v[m - 1][n - 1];
	}
};

int main()
{

	return 0;
}