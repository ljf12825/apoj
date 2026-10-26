// LC24. Swap Nodes in Pairs

/*
   Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes(i.e., only nodes themselves may be changed.)
*/

/*
   Example1:\
   Input: head = [1,2,3,4]\
   Output: [2,1,3,4]

   Example2:\
   Input: head = []\
   Output: []

   Example3:\
   Input: head = [1]\
   Output: [1]

   Example4:\
   Input: head = [1,2,3]\
   Output: [2,1,3]
*/

/*
   Constraints:

   - The number of nodes in the list is in the range `[0, 100]`
   - `0 <= Node.val <= 100`
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Solution0：我的写法，我当时的想法是复用head这个名字，导致搞的逻辑很混乱
class Solution0 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* fakenode = &dummy;

        if (head && head->next) {
            fakenode->next = head->next;
            head->next = fakenode->next->next;
            fakenode->next->next = head;
        }

        while (head && head->next && head->next->next) {
            ListNode* temp = head->next;
            head->next = head->next->next;
            temp->next = head->next->next;
            head->next->next = temp;
            head = temp;
        }

        return fakenode->next;
    }
};

// Solution1：标准解法，三个节点一组进行相同操作，做这种题千万不要省步骤，自己在纸上画一下过程，少一个步骤就会断链或成环
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        return dummy.next;
    }
};
