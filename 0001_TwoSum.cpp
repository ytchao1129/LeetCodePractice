
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;


vector<int> twoSum(vector<int>& nums, int target)
{
	int count = nums.size();
	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if ((nums[i] + nums[j]) == target)
			{
				return vector<int> { i, j };
			}
		}
	}

	return vector<int>();
}

int main()
{
	vector<int> nums{ 2,7,11,15 };
	int target = 9;

	vector<int> result = twoSum(nums, target);

	cout << "[" << result[0] << "," << result[1] << "]";

}