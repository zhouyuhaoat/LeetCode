/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:59
 *   modified:  2026-01-22 14:27:01
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode dummy1, dummy2, *tail1 = &dummy1, *tail2 = &dummy2;
        while (head) {
            if (head->val < x) {
                tail1 = tail1->next = head;
            } else {
                tail2 = tail2->next = head;
            }
            head = head->next;
        }
        tail1->next = dummy2.next, tail2->next = nullptr; // connect & cut
        return dummy1.next;
    }
};
// @lc code=end
