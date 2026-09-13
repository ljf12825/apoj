// LC2. Add Two Numbers

/*
   You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two number and return the sum as a linked list.

   You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/*
   Example 1:
   Input: l1 = [2,4,3], l2 = [5,6,4]
   Output: [7,0,8]
   Explanation: 342 + 45 = 807

   Example 2:
   Input: l1 = [0], l2 = [0]
   Output: [0]

   Example 3:
   Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
   Output: [8,9,9,9,0,0,0,1]
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) :val(x), next(next) {}
};

// 我的写法 修改l1，O(n) 时间，O(1) 空间
class Solution1 {
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        int carry = 0;
        ListNode* tail1;
        ListNode* tail2;

        while (l1 != nullptr && l2 != nullptr) {
            int sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10; // sum 每次每位求和结果是必要的，因为l1->val参与计算，且l1->val被修改，需要一个第三方sum记录结果
            if (l1->next == nullptr) tail1 = l1;
            if (l2->next == nullptr) tail2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 != nullptr && l2 == nullptr) {
            while (l1 != nullptr) {
                int sum = l1->val + carry;
                l1->val = sum % 10;
                carry = sum / 10;
                if (l1->next == nullptr) tail1 = l1;
                l1 = l1->next;
            }

            if (carry) tail1->next = new ListNode(carry);
        }

        if (l1 == nullptr && l2 != nullptr) {
            while (l2 != nullptr) {
                tail1->next = l2;
                int sum = l2->val + carry;
                l2->val = sum % 10;
                carry = sum / 10;
                if (l2->next == nullptr) tail2 = l2;
                l2 = l2->next;
                tail1 = tail1->next;
            }

            if (carry) tail2->next = new ListNode(carry);
        }

        if (l1 == nullptr && l2 == nullptr)
            if (carry) tail1->next = new ListNode(carry);
        
        return head;
    }

};

// Solution2 新建链表，优化判断
class Solution2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            carry = sum / 10;
        }

        return dummy.next;
    }
};
