

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

	int count = nums1.size() + nums2.size();

	int idx1 = floor((count - 1) / (float)2);
	int idx2 = ceil((count - 1) / (float)2);

	int i1 = 0;
	int i2 = 0;

	int r1 = 0;
	int r2 = 0;

	for (int i = 0; i <= idx2; i++)
	{
		int val = 0;
		int temp = nums1.size() - 1;
		if (i1 <= temp)
		{
			temp = nums2.size() - 1;
			if (i2 <= temp)
			{
				if (nums1[i1] < nums2[i2])
				{
					val = nums1[i1];
					++i1;
				}
				else
				{
					val = nums2[i2];
					++i2;
				}
			}
			else
			{
				val = nums1[i1];
				++i1;
			}
		}
		else
		{
			val = nums2[i2];
			++i2;
		}

		if (i == idx1)
		{
			r1 = val;
		}
		if (i == idx2)
		{
			r2 = val;
		}

	}

	return(double)(r1 + r2) / 2;

}

int main()
{
	vector<int> nums1{ 1,3 };
	vector<int> nums2{ 2 };

	cout << "answer:" << findMedianSortedArrays(nums1, nums2);
}