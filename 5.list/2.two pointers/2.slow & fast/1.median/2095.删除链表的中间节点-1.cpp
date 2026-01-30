/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:36:32
 *   modified:  2026-01-22 12:51:20
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] 删除链表的中间节点
 */

// @lc code=start
class Solution {
private:
    ListNode *getMedian(ListNode *lo, ListNode *hi) {
        while (hi && hi->next) {
            lo = lo->next;
            hi = hi->next->next;
        }
        return lo;
    }

    void deleteNode(ListNode *pred) {
        ListNode *node = pred->next;
        pred->next = node->next;
        // delete node;
    }

public:
    ListNode *deleteMiddle(ListNode *head) {
        ListNode dummy(0, head), *pred = getMedian(&dummy, head);
        deleteNode(pred);
        return dummy.next;
    }
};
// @lc code=end
