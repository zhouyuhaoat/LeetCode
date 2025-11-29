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
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy(0, head), *pred = &dummy;
        for (int i = 0; i < left - 1; i++) {
            pred = pred->next;
        }
        ListNode *prev = nullptr, *curr = pred->next;
        for (int i = left - 1; i < right; i++) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        pred->next->next = curr, pred->next = prev; // from right to left
        return dummy.next;
    }
};
// @lc code=end
