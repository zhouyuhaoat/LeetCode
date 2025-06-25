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
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *ptr = head;
        for (int i = 0; i < k; i++) {
            if (!ptr) return head;
            ptr = ptr->next;
        }
        ListNode *prev = nullptr, *curr = head;
        for (int i = 0; i < k; i++) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
// @lc code=end
