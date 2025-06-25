/*
 *   author:    zhouyuhao
 *   created:   2025-02-28 12:42:21
 *   modified:  2025-02-28 12:51:09
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */

// @lc code=start
class Solution {
public:
    ListNode *reverse(ListNode *head) {
        /*
            reverse a singly linked list by head insertion
            - precondition: the head is not null
            - fixed the first node as the tail, also an anchor
            - move the next node after the tail to the front
                - from the second node to the end
                - until the next node is null
            - first bypass the next node, then insert it at the front
                - avoid the infinite loop when the tail is the head
        */
        ListNode *newHead = head, *tail = head;
        while (tail->next) {
            ListNode *next = tail->next;
            tail->next = next->next, next->next = newHead;
            newHead = next;
        }
        return newHead;
    }

    ListNode *add(ListNode *l1, ListNode *l2) {
        ListNode dummy, *curr = &dummy;
        int carry = 0;
        while (l1 || l2 || carry > 0) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            curr = curr->next = new ListNode(sum % 10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        return reverse(add(l1, l2));
    }
};
// @lc code=end
