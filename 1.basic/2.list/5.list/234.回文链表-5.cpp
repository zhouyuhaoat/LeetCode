/*
 *   author:    zhouyuhao
 *   created:   2025-02-28 10:36:35
 *   modified:  2025-02-28 10:45:49
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
class Solution {
public:
    pair<bool, ListNode *> isPalindromeRecursive(ListNode *curr, ListNode *front) {
        if (!curr) return {true, front};
        auto [flag, node] = isPalindromeRecursive(curr->next, front);
        if (!flag || node->val != curr->val) return {false, node};
        return {true, node->next};
    }

    bool isPalindrome(ListNode *head) {
        return isPalindromeRecursive(head, head).first;
    }
};
// @lc code=end
