/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-22 11:56:32
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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

    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
        ListNode *prev = nullptr, *curr = head;
        while (prev != tail) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return {tail, head};
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy(0, head), *pred = advance(&dummy, left - 1);
        ListNode *lo = pred->next, *hi = advance(lo, right - left);
        ListNode *succ = hi->next;
        // pred -> lo -> ... -> hi -> succ
        tie(lo, hi) = reverse(lo, hi);
        pred->next = lo, hi->next = succ; // connect
        return dummy.next;
    }
};
// @lc code=end
