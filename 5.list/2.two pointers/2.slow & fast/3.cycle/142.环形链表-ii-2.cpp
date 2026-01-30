/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:59
 *   modified:  2025-02-28 10:09:59
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *lo = head, *hi = head;
        while (hi && hi->next) { // Floyd's cycle detection algorithm
            lo = lo->next;
            hi = hi->next->next;
            if (lo == hi) { // meeting point -> nonCycle steps -> cycle entry
                hi = head;
                while (lo != hi) {
                    lo = lo->next, hi = hi->next;
                }
                return lo;
            }
        }
        return nullptr;
    }
};
// @lc code=end
