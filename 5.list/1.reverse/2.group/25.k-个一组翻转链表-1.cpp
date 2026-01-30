/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-22 11:48:04
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
        for (int i = 0; i < dis; i++) {
            node = node->next;
            if (!node) break; // out of range
        }
        return node;
    }

    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
        // range reverse: [head, tail]
        ListNode *prev = nullptr, *curr = head;
        while (prev != tail) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return {tail, head};
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0, head), *pred = &dummy;
        while (head) {
            ListNode *tail = advance(pred, k);
            if (!tail) break;
            ListNode *succ = tail->next;
            // pred -> head -> ... -> tail -> succ
            tie(head, tail) = reverse(head, tail);
            pred->next = head, tail->next = succ; // connect
            pred = tail, head = succ; // shift
        }
        return dummy.next;
    }
};
// @lc code=end
