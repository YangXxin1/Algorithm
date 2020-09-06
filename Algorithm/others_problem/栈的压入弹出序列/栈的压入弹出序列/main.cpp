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

			//这里将popped中的数据与辅助栈顶比较
			//与辅助栈顶相同就将栈顶元素弹出
			//这里要注意某些特殊情况
			//比如[1, 0] [1, 0]
			//这种情况第一次将元素1入栈
			//栈顶元素此时与popped[0]相同, 弹栈
			//此时辅助栈为空, 在进行pop操作就会出错
			//因此判断条件还要对栈进行判空操作
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