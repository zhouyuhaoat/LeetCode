/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-28 09:43:23
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

    void reverse(ListNode *& prev, ListNode *& curr, int size) {
        for (int i = 0; i < size; i++) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy(0, head), *pred = advance(&dummy, left - 1);
        ListNode *lo = pred->next;
        ListNode *prev = nullptr, *curr = lo;
        reverse(prev, curr, right - left + 1); // on the fly
        ListNode *hi = prev, *succ = curr;
        // pred -> lo <- ... <- hi   succ
        pred->next = hi, lo->next = succ; // from left to right
        return dummy.next;
    }
};
// @lc code=end
