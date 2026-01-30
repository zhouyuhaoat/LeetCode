/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2026-01-22 12:55:24
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
class Solution {
private:
    ListNode *getMedian(ListNode *head) {
        ListNode *lo = head, *hi = head;
        while (hi && hi->next) { // stride = 2
            lo = lo->next;
            hi = hi->next->next;
        }
        return lo;
    }

public:
    ListNode *middleNode(ListNode *head) {
        return getMedian(head);
    }
};
// @lc code=end
