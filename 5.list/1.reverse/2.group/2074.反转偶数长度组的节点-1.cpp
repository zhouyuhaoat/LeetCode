/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 10:46:21
 *   modified:  2026-01-19 21:21:50
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 *
 * [2074] 反转偶数长度组的节点
 */

// @lc code=start
class Solution {
private:
    pair<ListNode *, int> getTailAndSize(ListNode *node, int dis) {
        int size = 0;
        for (int i = 0; i < dis && node->next; i++) { // tail
            size++;
            node = node->next;
        }
        return {node, size};
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

public:
    ListNode *reverseEvenLengthGroups(ListNode *head) {
        ListNode dummy(0, head), *pred = &dummy;
        int group = 0; // group size
        while (head) {
            auto [tail, len] = getTailAndSize(pred, ++group); // actual size
            ListNode *succ = tail->next;
            if (len % 2 == 0) {
                // pred -> head -> ... -> tail -> succ
                tie(head, tail) = reverse(head, tail);
                pred->next = head, tail->next = succ;
            }
            pred = tail, head = succ;
        }
        return dummy.next;
    }
};
// @lc code=end
