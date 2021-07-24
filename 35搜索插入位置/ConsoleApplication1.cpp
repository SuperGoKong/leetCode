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

int main()
{
	vector<int> nums = { 1,3,5,6,7 };
	int target = 0;
	int i = 0;
	int j = nums.size() - 1;
	while (i <=j)
	{
		int m = i+  (j-i) / 2;
		if (target == nums[m])
		{
			i = m;
			break; 
		}
		if (target > nums[m])//在后半段
		{
			i = m+1;
		}
		else //在前半段
		{
			j = m - 1;
		}
	}
	cout << i << endl;
    return 0;
}

