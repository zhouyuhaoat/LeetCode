/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2026-01-22 12:54:06
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
    ListNode *getMedian(ListNode *& pred, ListNode *head) {
        ListNode *lo = head, *hi = head;
        while (hi && hi->next) {
            pred = lo; // predecessor
            lo = lo->next;
            hi = hi->next->next;
        }
        return lo;
    }

public:
    ListNode *middleNode(ListNode *head) {
        ListNode dummy(0, head), *pred = &dummy;
        getMedian(pred, head);
        return pred->next;
    }
};
// @lc code=end
