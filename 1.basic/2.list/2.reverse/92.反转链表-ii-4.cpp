/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-28 09:43:45
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode dummy(0, head), *pred = &dummy;
        for (int i = 0; i < left - 1; i++) {
            pred = pred->next;
        }
        /*
            two pass -> one pass: head insertion with anchor
            1. pred -> pred->next = head -> ... -> tail -> next -> next->next
            2. pred -> pred->next = head = next -> ... -> tail -> next->next
        */
        ListNode *tail = pred->next; // fix the first node as the anchor
        for (int i = left; i < right; i++) {
            ListNode *next = tail->next;
            tail->next = next->next;
            next->next = pred->next, pred->next = next;
        }
        return dummy.next;
    }
};
// @lc code=end
