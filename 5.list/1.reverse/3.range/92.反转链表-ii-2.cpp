/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-25 11:41:05
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

    void reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy(0, head), *pred = advance(&dummy, left - 1);
        ListNode *lo = pred->next, *hi = advance(lo, right - left);
        ListNode *succ = hi->next;
        hi->next = nullptr; // cut for reverse
        reverse(lo);
        pred->next = hi, lo->next = succ;
        return dummy.next;
    }
};
// @lc code=end
