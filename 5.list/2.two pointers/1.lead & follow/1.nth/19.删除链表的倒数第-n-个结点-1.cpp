/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2026-01-22 10:59:45
 *   project:   LeetCode of labuladong
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
    int getSize(ListNode *head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode *advance(ListNode *node, int dis) {
        for (int i = 0; i < dis; i++) {
            node = node->next;
        }
        return node;
    }

    ListNode *getNthFromEnd(ListNode *head, int n) {
        return advance(head, getSize(head) - n);
    }

    void deleteNode(ListNode *pred) {
        ListNode *node = pred->next;
        pred->next = node->next;
        delete node;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) { // 1-based index
        ListNode dummy(0, head), *pred = getNthFromEnd(&dummy, n + 1);
        deleteNode(pred);
        return dummy.next;
    }
};
// @lc code=end
