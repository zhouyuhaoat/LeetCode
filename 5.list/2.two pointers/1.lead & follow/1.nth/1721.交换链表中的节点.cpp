/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:36:11
 *   modified:  2026-01-22 11:06:29
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
 */

// @lc code=start
class Solution {
private:
    ListNode *advance(ListNode *node, int dis) {
        for (int i = 0; i < dis; i++) {
            node = node->next;
        }
        return node;
    }

    ListNode *getNth(ListNode *head, int n) {
        return advance(head, n - 1);
    }

    ListNode *getNthFromEnd(ListNode *head, int n) {
        ListNode *lo = head, *hi = head;
        while (n--) {
            hi = hi->next;
        }
        while (hi) {
            lo = lo->next, hi = hi->next;
        }
        return lo;
    }

public:
    ListNode *swapNodes(ListNode *head, int k) { // 1-based index
        ListNode *left = getNth(head, k), *right = getNthFromEnd(head, k);
        swap(left->val, right->val);
        return head;
    }
};
// @lc code=end
