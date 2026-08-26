// LC21.Merge Two Sorted Lists

/*
   You are given the heads of two sorted linked lists `list1` and `list2`

   Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists

   Return the head of the merged linked list.

   Example 1:
   Input: list1 = [1, 2, 4], list2 = [1, 3, 4]
   Output: [1, 1, 2, 3, 4, 4]

   Example 2:
   Input: list1 = [], list2 = []
   Output: []

   Example3:
   Input: list1 = [], list2 = [0]
   Output: [0]
*/

struct LinkedNode
{
	int val;
	LinkedNode* next;
	LinkedNode() : val(0), next(nullptr) {}
	LinkedNode(int x) : val(x), next(nullptr) {}
	LinkedNode(int x, LinkedNode* ptr) : val(x), next(ptr) {}
};

class Solution_Recursion
{
public:
	LinkedNode* mergeTwoLists(LinkedNode* list1, LinkedNode* list2)
	{
		if (list1 == nullptr) return list2;
		else if (list2 == nullptr) return list1;
		else if (list1->val < list2->val)
		{
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
	}
};

class Solution_Iteration // 这是我一开始想到的写法，这道题思路很简单，但是我被指针搞的很烦
{
public:
	LinkedNode* mergeTwoLists(LinkedNode* list1, LinkedNode* list2)
	{
		LinkedNode faker; // 这是一个哨兵节点，用于指引整个list
		LinkedNode* list3 = &faker; // 这是提供操作的指针
		while (list1 && list2)
		{
			if (list1->val < list2->val)
			{
				list3->next = list1;
				list1 = list1->next;
			}
			else
			{
				list3->next = list2;
				list2 = list2->next;
			}
			list3 = list3->next;
		}
		list3->next = list1 == nullptr ? list2 : list1;
		return faker.next;
	}
};
