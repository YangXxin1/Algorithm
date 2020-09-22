#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> constructArr(vector<int>& a) {
		vector<int> ret;
		if (a.size() == 0)
			return ret;

		int len = a.size();
		ret.resize(len, 1);

		//举例来看, 假如数组a中的值为1, 2, 3, 4, 5
		//      对应ret中的值ret[0]=1* 2* 3* 4* 5
		//                  ret[1]=1* 1* 3* 4* 5
		//                  ret[2]=1* 2* 1* 4* 5
		//                  ret[3]=1* 2* 3* 1* 5
		//                  ret[4]=1* 2* 3* 4* 1
		//可以观察到对角线全为1, 以对角线为分割线, 将其分为上三角和下三角

		//先计算下三角部分, 对ret中的值进行更新
		for (int i = 1; i < len; ++i)
			ret[i] = ret[i - 1] * a[i - 1];

		//再计算上三角部分
		int tmp = 1;//用临时变量保存上三角每一行乘积
		for (int i = len - 2; i >= 0; --i)
		{
			tmp *= a[i + 1];//更新tmp的值
			ret[i] *= tmp;
		}

		return ret;
	}
};

int main()
{

	return 0;
}