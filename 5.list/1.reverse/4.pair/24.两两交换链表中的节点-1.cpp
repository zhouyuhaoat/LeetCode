/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:26
 *   modified:  2026-01-21 20:49:36
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
class Solution {
private:
    ListNode *advance(ListNode *node, int dis) {
        for (int i = 0; i < dis; i++) {
            node = node->next;
            if (!node) break;
        }
        return node;
    }

    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
        ListNode *prev = nullptr, *curr = head;
        while (prev != tail) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0, head), *pred = &dummy;
        while (head) {
            ListNode *tail = advance(pred, k);
            if (!tail) break;
            ListNode *succ = tail->next;
            tie(head, tail) = reverse(head, tail);
            pred->next = head, tail->next = succ;
            pred = tail, head = succ;
        }
        return dummy.next;
    }

public:
    ListNode *swapPairs(ListNode *head) {
        return reverseKGroup(head, 2); // group = 2
    }
};
// @lc code=end
