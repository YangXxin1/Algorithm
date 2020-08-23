#include <iostream>
#include <vector>

using namespace std;

//DFS������ȱ���

int row, col;//��ͼ�к���
//������ʱ·��
vector<vector<int>> temp_path;
//�������·��
vector<vector<int>> best_path;
//��ͼ
vector<vector<int>> map(row, vector<int>(col, 0));

void findMinPath(int i, int j)
{
	map[i][j] = 1;//���߹���·����Ϊ1, ��ʾ���治����������
	temp_path.push_back({ i, j });

	if (i == row - 1 && j == col - 1)
	{
		//��ʾ�Ѿ��ߵ����
		if (best_path.empty() || best_path.size() > temp_path.size())
			best_path = temp_path;
	}

	if (i - 1 >= 0 && map[i - 1][j] == 0)//��ʾ����������
		findMinPath(i - 1, j);

	if (i + 1 < row && map[i + 1][j] == 0)//��ʾ����������
		findMinPath(i + 1, j);

	if (j - 1 >= 0 && map[i][j - 1] == 0)//��ʾ����������
		findMinPath(i, j - 1);

	if (j + 1 < col && map[i][j + 1] == 0)//��ʾ����������
		findMinPath(i, j + 1);

	//����
	map[i][j] = 0;
	temp_path.pop_back();
}

int main()
{
	while (cin >> row >> col)
	{
		map = vector<vector<int>>(row, vector<int>(col, 0));
		temp_path.clear();
		best_path.clear();
		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				cin >> map[i][j];
			}
		}

		findMinPath(0, 0);

		for (auto& i : best_path)
		{
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
		}
	}

	return 0;
}