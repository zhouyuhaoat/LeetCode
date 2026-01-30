/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:24
 *   modified:  2025-02-22 11:51:21
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
class Solution {
private:
    ListNode *advance(ListNode *node, int dis) {
        for (int i = 0; i < dis && node; i++) { // out of range
            node = node->next;
        }
        return node;
    }

    void reverse(ListNode *& prev, ListNode *& curr, int size) {
        for (int i = 0; i < size; i++) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0, head), *pred = &dummy;
        ListNode *tail = advance(pred, k);
        if (!tail) return dummy.next;
        ListNode *prev = nullptr, *curr = head;
        reverse(prev, curr, k);
        ListNode *newHead = prev, *succ = curr;
        head->next = reverseKGroup(succ, k);
        return newHead;
    }
};
// @lc code=end
