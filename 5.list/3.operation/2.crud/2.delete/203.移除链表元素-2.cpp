/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 18:39:11
 *   modified:  2026-01-17 21:29:18
 *   project:   LeetCode
 *   venue:     A20, Harbin
 */

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) return nullptr;
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
// @lc code=end
