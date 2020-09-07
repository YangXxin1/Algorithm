#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int strToInt(string str) {
		//首先对字符串进行处理
		int i = 0;
		int len = (int)str.size();
		int flag = 1;

		//跳过空格字符
		while (str[i] == ' ')
			++i;

		//确定符号
		if (str[i] == '-')
			flag = -1;
		if (str[i] == '+' || str[i] == '-')
			++i;

		//无法进行有效转换
		if (str[i] < '0' || str[i] > '9')
			return 0;

		int res = 0;//用来记录转换结果
		int boundary_val = INT_MAX / 10;//为了方便对越界情况进行判断, 保存这样一个边界值
		// INT_MAX = 2147483647
		// INT_MAX / 10 = 214748364
		// 由此可以得到
		// res * 10 >= 2147483650 时一定会越界, 此时的 res > 214748364
		// res * 10 == 2147483640 时, 若 tmp > 7, 则越界, 此时 res == 214748364
		while (i < len)
		{
			if (str[i] < '0' || str[i] > '9')
				break;
			int tmp = str[i] - '0';
			//越界判断
			if (res > boundary_val || (res == boundary_val && tmp > 7))
			{
				if (flag == -1)
					return INT_MIN;
				else
					return INT_MAX;
			}
			res = res * 10 + tmp;
			++i;
		}
		return flag * res;
	}
};


int main()
{


	return 0;
}