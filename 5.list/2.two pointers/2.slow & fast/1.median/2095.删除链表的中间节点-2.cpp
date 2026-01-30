/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:36:32
 *   modified:  2026-01-22 11:16:25
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
    ListNode *getMedian(ListNode *& pred, ListNode *head) {
        ListNode *lo = head, *hi = head;
        while (hi && hi->next) {
            pred = lo; // predecessor
            lo = lo->next;
            hi = hi->next->next;
        }
        return lo;
    }

    void deleteNode(ListNode *pred) {
        ListNode *node = pred->next;
        pred->next = node->next;
        delete node;
    }

public:
    ListNode *deleteMiddle(ListNode *head) {
        if (!head->next) return nullptr; // single node
        ListNode dummy(0, head), *pred = &dummy;
        getMedian(pred, head);
        deleteNode(pred);
        return dummy.next;
    }
};
// @lc code=end
