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

		//在上一个if条件已经判断过board[row][col]与word[pos]的关系
		//因此这里的判断条件是pos == word.size() - 1就可跳出了
		if (pos == word.size() - 1)
			return true;

		char tmp = board[row][col];//保存当前字符, 方便后续回溯
		board[row][col] = '/';//表示该位置已经走过, 不能再走

		//DFS深度优先遍历
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
				//遍历找到递归入口
				//也就是寻找起始位置
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