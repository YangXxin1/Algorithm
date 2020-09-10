#include <iostream>
#include <queue>
#include <deque>

using namespace std;

class MaxQueue 
{
public:
	MaxQueue() {}

	int max_value() 
	{
		if (max_queue.empty())
			return -1;
		return max_queue.front();
	}

	void push_back(int value) 
	{
		q.push(value);
		//�����ǰҪ�����ֵ�ȸ���˫�˶���β��Ԫ��Ҫ��, �ͽ�βԪ��pop��
		//�����ǰҪ�����ֵ�ȸ���˫�˶���β��Ԫ��ҪС, ��ֱ�����
		//ͨ�����ַ�ʽ���ָ���˫�˶��еĵ�����(�ǵ���)
		while (!max_queue.empty() && value > max_queue.back())
			max_queue.pop_back();
		max_queue.push_back(value);
	}

	int pop_front() 
	{
		if (q.empty())
			return -1;
		int tmp = q.front();
		q.pop();
		if (tmp == max_queue.front())
			max_queue.pop_front();
		return tmp;
	}
private:
	queue<int> q;
	//ά��һ��˫�˶���, ��������������ֵ
	deque<int> max_queue;
};

int main()
{


	return 0;
}