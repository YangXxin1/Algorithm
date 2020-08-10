#include <iostream>

using namespace std;


//while (tail->next && tail->val != tail->next->val)
//{
//prev = prev->next;
//tail = tail->next;
//}


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr) 
	{

	}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		/*if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		//为了方便删除头结点重复的情况, 我们构造一个哨兵结点
		ListNode* new_head = new ListNode(0);
		new_head->next = pHead;

		ListNode* prev = new_head;
		ListNode* tail = prev->next;

		while (tail)
		{
			while (tail->next && tail->val == tail->next->val)
				tail = tail->next;

			if (prev->next == tail)
			{
				//说明两个结点仍然相邻,没有需要删除的有效区间
				prev = prev->next;
			}
			else
			{
				//不相邻则需要删除
				prev->next = tail->next;
			}
			tail = tail->next;
		}
		return new_head->next;*/

		//简化代码
		if (pHead == nullptr || pHead->next == nullptr)
			return pHead;

		//为了方便删除头结点重复的情况, 我们构造一个哨兵结点
		ListNode* new_head = new ListNode(0);
		new_head->next = pHead;

		ListNode* prev = new_head;
		ListNode* tail = prev->next;

		while (tail)
		{
			//首先通过不相等条件直接找到需要删除区间的头结点
			//prev结点位于tail结点前面
			//找到相等值时通过移动tail指针的位置找到需要删除的最后一个结点
			//而此时prev所处的位置是需要删掉的第一个结点的前驱结点
			while (tail->next && tail->val != tail->next->val)
			{
				prev = prev->next;
				tail = tail->next;
			}
			while (tail->next && tail->val == tail->next->val)
				tail = tail->next;

			if (prev->next != tail)
			{
				//说明有需要删除的结点
				prev->next = tail->next;
			}
			tail = tail->next;
		}
		return new_head->next;
	}
};

int main()
{

	return 0;
}