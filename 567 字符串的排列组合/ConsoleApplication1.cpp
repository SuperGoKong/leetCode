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
#include <unordered_set>
#include <map>
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

// 时间超时
bool checkInclusion(string s1, string s2)
{
	int n = s1.length();
	int m = s2.length();

	if (n > m)
	{
		return false;
	}
	map<char, int> windowMap;
	map<char, int> temp;

	for (char i : s1)
	{
		windowMap[i] += 1; // 记录子窗的个数
	}
	
	int left = 0; int right = 0;
	int counter = 0;
	int moveBit = 0;
	for (int left = 0; left < m; left++)
	{
		counter = 0;
		moveBit = 0;
		int start = left;
		temp.clear();
		while (windowMap.count(s2[left]) != 0 && moveBit<n) //循环子窗，判断当前字符是否在字典中，并且判断移动次数
		{
			temp[s2[left]] += 1;
			if (temp.find(s2[left])->second>windowMap.find(s2[left])->second)// 判断重复的个数，重复次数不得超过字段字符的计数
			{
				break;
			}
			moveBit = moveBit + 1;
			left = start + moveBit;
			counter++;
			
		}
		left = start;
		if (counter == n) // 如果counter 与 字典个数相等就 输出true
		{
			return true;
		}
	}

	return false;
}

bool checkInclusion1(string s1, string s2)
{
	int n = s1.length();
	int m = s2.length();

	if (n > m)
	{
		return false;
	}
	map<char, int> windowMap;
	map<char, int> temp;

	for (char i : s1)
	{
		windowMap[i] += 1; // 记录子窗的个数
	}

	int counter = 0;
	int index_r = 0;
	int right = 0;
	int left = 0;
	while (right < s2.size())
	{
		temp[s2[right]]++;
		if (right - left + 1 == n) {
			//cout << mp_s2.size() << endl;
			if (windowMap == temp)
				return true;
			temp[s2[left]]--;
			if (temp[s2[left]] == 0)
				temp.erase(s2[left]);
			left++;
		}
		right++;
	}
	
	return false;
}

int main()
{
	string s1 = "io"; 
	string s2 = "eidboaoo";
	
	bool flag = checkInclusion1(s1, s2);

	if (flag)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}


    return 0;
}

