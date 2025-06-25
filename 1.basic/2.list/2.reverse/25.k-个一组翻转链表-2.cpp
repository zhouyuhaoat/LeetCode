/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:24
 *   modified:  2025-02-22 11:48:21
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
public:
    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
        ListNode *prev = nullptr, *curr = head, *end = tail->next;
        while (curr != end) { // when curr = tail, tail->next is changed
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head), *prev = dummy;
        while (head) {
            ListNode *tail = prev;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return dummy->next;
            }
            ListNode *nextGroup = tail->next;
            tie(head, tail) = reverse(head, tail);
            prev->next = head, tail->next = nextGroup;
            prev = tail, head = nextGroup;
        }
        return dummy->next;
    }
};
// @lc code=end
