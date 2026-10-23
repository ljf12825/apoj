// LC19. Remove Nth Node From End of List

/*
   Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.
*/

/*
   Example1:\
   Input: head = [1,2,3,4,5], n = 2;\
   Output: [1,2,3,5]

   Example2:\
   Input: head = [1], n = 1\
   Output: []

   Example3:\
   Input: head = [1,2], n = 1\
   Output: [1]
*/

/*
   Constraints:\
   - The number of nodes in the list is `sz`
   - `1 <= sz <= 30`
   - `0 <= Node.val <= 100`
   - `1 <= n <= sz`
*/

#include <vector>
// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Solution1：将节点存入额外vector然后操作。这是一种简单思想，本题数据量小，这个方法的实际时间复杂度和空间复杂度很优秀，理论上时间复杂度O(n), 空间复杂度O(n)
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> vec;
        for (ListNode* p = head; p; p = p->next) vec.push_back(p);

        int idx = vec.size() - n;

        if (idx == 0) { // 删除头节点特判，可以在head前加一个dummy哑节点统一处理
            ListNode* newHead = head->next;

            return newHead;
        }

        vec[idx - 1]->next = vec[idx]->next;

        return head;
    }
};

// Solution2：双指针，先让fast指针走出一段n + 1的距离，然后slow和fast一块走，这样间距就固定，fast走到尾部后slow的位置就是要删除指针的前驱，时间复杂度O(n)，空间复杂度O(1)
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; ++i) fast = fast->next;

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};
