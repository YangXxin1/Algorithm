#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
	int translateNum(int num) {
		//动态规划问题
		//F(i)表示以第i位为结尾的前缀串有多少种不同的翻译方法
		//i > 0, 如果第i - 1位与第i位组成的数字10 <= x <= 25
		//说明
		//此时f(i) = f(i - 1) + f(i - 2)
		//反之, 它们不能连在一起翻译, 也就是说第i位需要单独翻译, 此时f(i) = f(i - 1)

		//数字转化为字符串
		string str = to_string(num);
		int len = str.size();

		//优化空间复杂度, 不去开辟额外空间
		int ret = 1;//保存结果, 默认为1, 因为只有一个数字, 不会进入下面的for循环, 直接返回1
		//初始化
		int a1 = 1;
		int a2 = 1;
		for (int i = 1; i< len; ++i)
		{
			int tmp = (str[i - 1] - '0') * 10 + (str[i] - '0');
			//f(i) = f(i - 1) + f(i - 2)
			if (tmp >= 10 && tmp <= 25)
				ret = a1 + a2;//第i - 1位与第i位可以连在一起翻译, 并且第i位也可以单独翻译
			else
				ret = a2;//第i位需要单独翻译, 此时f(i) = f(i - 1)
			a1 = a2;
			a2 = ret;
		}
		return ret;
	}
};

int main()
{

	return 0;
}