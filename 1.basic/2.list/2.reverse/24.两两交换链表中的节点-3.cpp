/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:26
 *   modified:  2025-02-22 11:45:07
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) return head; // base case: no pairs
        ListNode *newHead = head->next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;
        return newHead;
    }
};
// @lc code=end
