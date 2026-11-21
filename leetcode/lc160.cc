// LC160. Intersection of Two Linked Lists

/*
   Given the heads of two singly linked-lists `headA` and `headB`, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return `null`.

   For example, the following two linked lists begin to intersect at node `c1`:

   A:     a1->a2
                \
                c1->c2->c3
                /
   B: b1->b2->b3

   The test cases are generated such that there are no cycles anywhere in the entire linked structure.

   Note that the linked lists must retain their original structure after the function returns.

   Custom Judge:

   The inputs to the judge are given as follows (your program is not given these inputs):

   - `intersectVal` - The value of the node where the intersection occurs. This is `0` if there is no intersected node.
   - `listA` - The first linked list.
   - `listB` - The second linked list
   - `skipA` - The number of nodes to skip ahead in `listA`(starting from the head) to get to the intersected node.
   - `skipB` - The number of nodes to skip ahead in `listB`(starting from the head) to get to the intersected node.

   The judge will then create the linked structure based on these inputs and pass the two heads, `headA` and `headB` to your program. If you correctly return the intersected node, then your solution will be accepted.
*/

/*
   Example1:\
   A:     4->1
              \
               8->4->5
              /
   B:  5->6->1

   Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3\
   Output: intersected at '8'\

   Example2:\
   A: 1->9->1
             \
              2->4
             /
   B:       3

   Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1\
   Output: intersected at '2'

   Example3:\
   A: 2->6->4

   B: 1->5

   Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2\
   Output: No Intersection
*/

// Definition for singly-linked list.
#include <set>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution1：写入表格并查表，时间复杂度为O((m + n)log m)，假设A长度为m，B长度为n，空间复杂度为O(m)
class Solution1 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        std::set<ListNode*> table;
        while (headA) {
            table.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (table.find(headB) != table.end()) return headB;
            headB = headB->next;
        }

        return nullptr;
    }
};

// Solution2：双指针换头法，两个指针分别从headA和headB开始走，走到头后换到对方的头节点往下走。如果skipA和skipB相同，那他们走同样的步长，会同时达到交点（如果相交），问题就是如果skipA和skipB不相等，那么如果两个链表相交，他们的相交部分长度是一样的，这样交换的走，让两个指针走的步长等于skipA + skipB，让他们同时到达相交点，时间复杂度为O(n + m)，空间复杂为O(1)

class Solution2 {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB) return nullptr;

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) { // 调换头结点后他们会同时到达nullptr
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};
