
#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* current1 = l1;
	ListNode* current2 = l2;
	ListNode* result = nullptr;
	ListNode* current = nullptr;
	int addValue = 0;
	while (current1 != nullptr || current2 != nullptr)
	{
		int v = addValue;
		if (current1 != nullptr)
		{
			v += current1->val;
			current1 = current1->next;
		}

		if (current2 != nullptr)
		{
			v += current2->val;
			current2 = current2->next;
		}

		addValue = v / 10;

		ListNode* newNode = new ListNode(v % 10);
		if (current == nullptr)
		{
			current = newNode;
		}
		else
		{
			current->next = newNode;
			current = newNode;
		}

		if (result == nullptr)
		{
			result = current;
		}
	}

	if (addValue > 0)
	{
		ListNode* newNode = new ListNode(addValue);
		if (current == nullptr)
		{
			current = newNode;
		}
		else
		{
			current->next = newNode;
			current = newNode;
		}
	}

	return result;
}

void PrintAll(ListNode* list)
{
	ListNode* current = list;
	while (current != nullptr)
	{
		cout << current->val;
		current = current->next;
		if (current != nullptr)
		{
			cout << "->";
		}
	}
}

ListNode * CreateList(vector<int> nums)
{
	ListNode *first = nullptr;
	ListNode *current = nullptr;
	for (size_t i = 0; i < nums.size(); i++)
	{
		ListNode *newNode = new ListNode(nums[i]);

		if (current == nullptr)
		{
			current = newNode;
		}
		else
		{
			current->next = newNode;
			current = newNode;
		}

		if (first == nullptr)
		{
			first = current;
		}
	}
	return first;
}

int main()
{
	vector<int> nums1{ 2,4,3 };
	vector<int> nums2{ 5,6,4 };

	ListNode *l1 = CreateList(nums1);
	ListNode *l2 = CreateList(nums2);

	PrintAll(addTwoNumbers(l1, l2));
}
