/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-28 09:48:14
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *lo = head, *hi = head;
        while (hi && hi->next) {
            lo = lo->next; // tortoise
            hi = hi->next->next; // hare
            if (lo == hi) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
