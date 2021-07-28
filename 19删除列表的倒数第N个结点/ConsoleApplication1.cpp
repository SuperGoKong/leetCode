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
#if  0
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
#endif
	return head;
}

void printNodeList(ListNode *head)
{
	//output ListNode
	if (head== NULL)
	{
		cout << "[ ]" << endl;
		return;
	}
	while (head->next != NULL)
	{
		cout << head->val << "->";
		head = head->next;
	}
	cout << head->val << endl;
}

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
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	ListNode* fast = head;
	ListNode* temp = new ListNode(0, head);
	ListNode* slow = temp;
	int i = 0;
	while (i < n)
	{
		fast = fast->next;
		i++;
	}

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = slow->next->next;
	ListNode* ans = temp->next;
	delete temp;
	return ans;
}
int main()
{
	ListNode *head = initNodeList();

	int n = 1; //链表倒数第二个

	head = removeNthFromEnd(head, n);

	//head = middleNode(head);

	printNodeList(head);

    return 0;
}

