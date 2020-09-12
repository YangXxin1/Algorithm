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
		//如果当前要插入的值比辅助双端队列尾部元素要大, 就将尾元素pop掉
		//如果当前要插入的值比辅助双端队列尾部元素要小, 就直接入队
		//通过这种方式保持辅助双端队列的单调性(非递增)
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
	//维护一个双端队列, 辅助保存队列最大值
	deque<int> max_queue;
};

int main()
{


	return 0;
}