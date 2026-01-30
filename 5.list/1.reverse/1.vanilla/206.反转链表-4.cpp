/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 10:56:37
 *   modified:  2025-12-16 11:02:18
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
        if (!head || !head->next) return head; // empty list or single node
        ListNode *newHead = reverseList(head->next), *newTail = head->next;
        newTail->next = head, head->next = nullptr;
        return newHead;
    }
};
// @lc code=end
