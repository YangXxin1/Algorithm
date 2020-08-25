#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
	//��ȡ��λ֮��
	int getCount_NUm(int num)
	{
		if (num < 10)
			return num;
		int ret = 0;
		while (num)
		{
			ret = ret + num % 10;
			num /= 10;
		}
		return ret;
	}
public:
	int movingCount(int m, int n, int k) {
		int count = 0;//����ͳ�ƿ��Ե���ĸ�������

		//��������ʹ��BFS, ������ȱ�������
		//������ȳ����ö���, ���浱ǰ״̬, �õ�ǰ״̬ȥ�����ܹ����������״̬������
		//���е��б��浱ǰ��������λ��
		queue<pair<int, int>> q;
		q.push({ 0, 0 });//��(0, 0)���, ��ʾ��(0, 0)����

		vector<vector<int>> map(m, vector<int>(n, 0));//������ͼ
		while (!q.empty())
		{
			int row = q.front().first;
			int col = q.front().second;
			q.pop();
			if (row < 0 || row >= m || col < 0 || col >= n
				|| getCount_NUm(row) + getCount_NUm(col) > k || map[row][col] == 1)
				continue;
			map[row][col] = 1;//���߹��ķ�����Ϊ1
			q.push({ row + 1, col });//������
			q.push({ row, col + 1 });//������
			++count;
		}

		return count;
	}
};

int main()
{

	return 0;
}