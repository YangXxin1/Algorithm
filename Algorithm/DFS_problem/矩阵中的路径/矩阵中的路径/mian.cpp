#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	bool FindPath(vector<vector<char>>& board, string& word, int row, int col, int pos)
	{
		if (row < 0 || row >= (int)board.size() || col < 0
			|| col >= (int)board[0].size() || board[row][col] == '/'
			|| board[row][col] != word[pos])
		{
			return false;
		}

		//����һ��if�����Ѿ��жϹ�board[row][col]��word[pos]�Ĺ�ϵ
		//���������ж�������pos == word.size() - 1�Ϳ�������
		if (pos == word.size() - 1)
			return true;

		char tmp = board[row][col];//���浱ǰ�ַ�, �����������
		board[row][col] = '/';//��ʾ��λ���Ѿ��߹�, ��������

		//DFS������ȱ���
		bool ret = FindPath(board, word, row + 1, col, pos + 1) ||
			FindPath(board, word, row - 1, col, pos + 1) ||
			FindPath(board, word, row, col + 1, pos + 1) ||
			FindPath(board, word, row, col - 1, pos + 1);
		board[row][col] = tmp;

		return ret;
	}

	bool exist(vector<vector<char>>& board, string word) {
		int row = board.size();
		int col = board[0].size();

		for (int i = 0; i < row; ++i)
		{
			for (int j = 0; j < col; ++j)
			{
				//�����ҵ��ݹ����
				//Ҳ����Ѱ����ʼλ��
				if (word[0] == board[i][j])
				{
					bool ret = FindPath(board, word, i, j, 0);
					if (ret == true)
						return true;
				}
			}
		}

		return false;
	}
};

int main()
{


	return 0;
}