#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	vector<int> Fib_Array = { 1, 1 };
	Fib_Array.resize(10001);
	for (int i = 2; i < 10001; ++i)
	{
		Fib_Array[i] = Fib_Array[i - 2] + Fib_Array[i - 1];
		Fib_Array[i] = Fib_Array[i] % 10000;
	}

	int n, num;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> num;
			printf("%04d", Fib_Array[num]);
		}
		cout << endl;
	}
	return 0;
}