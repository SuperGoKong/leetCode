// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iterator>     // std::back_inserter
#include <vector>       // std::vector
#include <string.h>   
#include<algorithm>
#include <iterator>
#include <new>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* initNodeList()
{
	ListNode *head = (ListNode*)malloc(sizeof(ListNode));
	head->val = 0;
	head->next = NULL;

	ListNode *p, *s;

	p = head;
	for (int i = 1; i < 6; i++)
	{

		s = (ListNode*)malloc(sizeof(ListNode));
		s->val = i;
		s->next = NULL;
		p->next = s;
		p = p->next;

	}

	return head;
}

void printNodeList(ListNode *head)
{
	//output ListNode
	while (head->next != NULL)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << head->val << endl;
}

// 0->1->2->3->4->5
// ^     ^
// |	 |
// sp    fp
// 根据双指针，知道中间结点
ListNode* middleNode(ListNode* head)
{
	ListNode* fp = head;
	ListNode* sp = head;

	while (fp!= NULL && fp->next != NULL)
	{
		sp = sp->next;
		fp = fp->next->next;
	}
	return sp;

}

int main()
{
	ListNode *head = initNodeList();

	head = middleNode(head);

	printNodeList(head);

    return 0;
}

