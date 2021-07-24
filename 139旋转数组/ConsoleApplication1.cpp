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
	vector<int> nums = {1,2,3,4,5,6,7};
	int k = 3;
#if 0 //时间复杂度不过关
	k = k % nums.size();
	int count = 0;
	vector<int>::iterator it=nums.begin();
	while (count < k)
	{
		int deleteData = nums[nums.size() - 1];
		nums.pop_back();
		//vector<int>::iterator it1 = nums.erase(it+nums.size()-1);		
		it = nums.insert(it, deleteData); // inset 比较花时间，导致时间复杂度不够
		count++;
	}

#else
	// for循环采用分段赋值的方法，很好理解的解题方法，但问题关键在于如果k大于nums.size()，怎么解决。
    // k = k % nums.size()
    // 解决办法:用k求模容器的大小(相当于一个循环),保证k小于nums.size()
	k = k % nums.size();
	vector<int> temp;

	for (int i = nums.size() - k; i < nums.size(); i++) // 填写要转移的部分
	{
		temp.push_back(nums[i]);
	}
	for (int i = 0; i <nums.size() - k; i++) //填写其他部分
	{
		temp.push_back(nums[i]);
	}
	nums = temp;
#endif
	for (int i = 0; i < nums.size(); i++)
	{
		cout << nums[i] << endl;
	}

    return 0;
}

