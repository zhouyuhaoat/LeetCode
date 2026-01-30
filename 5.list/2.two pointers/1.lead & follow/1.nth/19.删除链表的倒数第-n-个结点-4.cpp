/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2026-01-22 10:09:11
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
class Solution {
private:
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

    void deleteNode(ListNode *pred) {
        ListNode *node = pred->next;
        pred->next = node->next;
        delete node;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0, head), *pred = getNthFromEnd(&dummy, n + 1);
        deleteNode(pred);
        return dummy.next;
    }
};
// @lc code=end
