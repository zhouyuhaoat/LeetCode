/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 10:56:37
 *   modified:  2025-12-16 10:57:29
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        // reverse a singly linked list
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next; // backup
            curr->next = prev; // reverse
            prev = curr, curr = next; // shift
        }
        return prev;
    }
};
// @lc code=end
