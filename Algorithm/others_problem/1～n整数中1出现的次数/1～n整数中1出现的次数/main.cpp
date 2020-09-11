#include <iostream>

using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		int high = n / 10, low = 0;//以cur当前位将数字分割, 左边为高位, 右边为低位
		//注意用long防止溢出
		long digit = 1;//表示数位, 1代表个位, 10代表十位...
		int cur = n % 10;//cur表示当前为数字
		int count = 0;

		while (high || cur)
		{
			if (cur == 0)
				count = count + high * digit;
			else if (cur == 1)
				count = count + (high * digit) + low + 1;
			else
				count = count + (high + 1) * digit;
			n /= 10;
			high = n / 10;
			low = low + cur * digit;
			digit *= 10;
			cur = n % 10;
		}

		return count;
	}
};

int main()
{


	return 0;
}