/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 10:56:37
 *   modified:  2025-12-16 11:00:22
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
        ListNode *newHead = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = newHead, newHead = curr; // head insertion
            curr = next;
        }
        return newHead;
    }
};
// @lc code=end
