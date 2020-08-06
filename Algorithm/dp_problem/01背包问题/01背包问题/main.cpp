#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A: Given n items with size A[i]
	* @param V: Given n items with value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> &A, vector<int> &V) {
		// write your code here
		int row = A.size() + 1;
		int col = m + 1;
		vector<vector<int>> max_val(row, vector<int>(col, 0));

		//����״̬: F(i,j)��ʾ������СΪj����i����Ʒ������ֵ
		//��̬ת�巽��: 
		//��� A[i - 1] > j,���ʾ��i����Ʒ�޷����뱳��,���F(i,j)=F(i-1,j)
		//��֮ A[i - 1] <= j,������i����Ʒ���Է��뱳��, ��ô���ڵ�i����Ʒ������ѡ��
		//�Ż����ǲ���
		//�����ŵ�i����Ʒ,�˻�Ϊ��һ״̬F(i-1,j)
		//�������i����Ʒ,Ҫ����������A[i-1]�Ŀռ��С
		//��F(i,j)=max(F(i-1,j),F(i, j-A[i - 1])+V[i - 1]);
		if (A.empty() || V.empty())
			return 0;

		for (int i = 1; i < row; ++i)
		{
			for (int j = 1; j < col; ++j)
			{
				if (j < A[i - 1])
					max_val[i][j] = max_val[i - 1][j];
				else
				{
					max_val[i][j] = max(max_val[i - 1][j], max_val[i - 1][j - A[i - 1]] + V[i - 1]);
				}
			}
		}
		return max_val[row - 1][col - 1];
	}
};

int main()
{
	return 0;
}