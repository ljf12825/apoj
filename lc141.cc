// LC141. Linked List Cycle

/*
    Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

    There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer.\
    Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. Note that `pos` is not passed as a parameter.

    Return `true` if there is a cycle in the linked list. Otherwise, return `false`
*/

/*
    Example1:\
    3 -> 2 -> 0 -> 4
         ^         |
         |_________|

    Input: head = [3,2,0,-4], pos = 1\
    Output: true

    Example2:\
    1 -> 2
    ^    |
    |____|
    Input: head = [1,2], pos = 0\
    Output: true

    Example3:\
    1
    Input: head = [1], pos = -1
    Output: false

*/
#include <unordered_set>
// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution1 Folyd算法（快慢指针）只要两个指针的行进速率不同，只要有环，某个时刻快指针就会窜到慢指针后面然后追上慢指针，这是最优解O(n), O(1)
class Solution1 {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) { // 值得注意的点就是要保证当前位置和下一个位置是有效的
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) return true;
        }

        return false;
    }
};

// Solution2 哈希集合，存访问过的节点的地址，判断地址是否重复，O(n), O(n)
class Solution2 {
public:
    bool hasCycle(ListNode* head) {
        std::unordered_set<ListNode*> visited;

        while (head) {
            if (visited.count(head)) return true;

            visited.insert(head);
            head = head->next;
        }

        return false;
    }
};