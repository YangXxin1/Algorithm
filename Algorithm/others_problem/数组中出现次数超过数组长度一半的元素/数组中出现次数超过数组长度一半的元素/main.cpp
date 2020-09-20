#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.size() == 0)
			return 0;
		/*int tmp = numbers[0];
		int count = 1;
		for (int i = 1; i < numbers.size(); ++i)
		{
		if (tmp == numbers[i])
		++count;
		else
		{
		--count;
		if (count == 0)
		{
		tmp = numbers[i + 1];
		count = 1;
		}
		}
		}
		count = 0;
		for (int i = 0; i < numbers.size(); ++i)
		{
		if (tmp == numbers[i])
		++count;
		}
		return (count > (numbers.size() / 2)) ? tmp : 0;*/
		map<int, int> m;
		for (size_t i = 0; i < numbers.size(); ++i)
		{
			m[numbers[i]]++;
		}
		for (auto& e : m)
		{
			if (e.second >(numbers.size() / 2))
				return e.first;
		}
		return 0;
	}
};

int main()
{

	return 0;
}