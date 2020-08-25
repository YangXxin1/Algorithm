#include <iostream>

using namespace std;

//数字序列中某一位的数字
//01234567891011121314....
//0 1 2 3 4 5  6 7 8 9 10 11 12 13 14.....
class Solution {
public:
	int findNthDigit(int n) {
		long start = 1;//从1开始
		int digit = 1;//数位为1
		long count = 9;//数位对应的数字个数

		while (n > count)
		{
			n -= count;
			start *= 10;//根据位数确定起始数字, 比如两位数从10开始, 三位数从100开始
			digit += 1;//位数每次加1
			count = 9 * start * digit;//计算数位对应的数字个数
		}

		int num = start + (n - 1) / digit;//计算出n所处的数字为多少
		int tmp = (n - 1) % digit;//计算出n在该数字中所处的位置
		tmp = digit - tmp;//按两位数举例来看, tmp为0表示是num的第0位, 此时要模两次(digit次)得到结果
		//tmp为1,则模1次可以得到结果(dight - tmp)
		int ret = num;
		while (tmp--)
		{
			ret = num % 10;
			num /= 10;
		}
		return ret;
	}
};

int main()
{


	return 0;
}