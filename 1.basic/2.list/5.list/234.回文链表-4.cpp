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
private:
    bool isPalindromeRecursive(ListNode *& front, ListNode *back) {
        if (!back) return true; // until end
        bool flag = isPalindromeRecursive(front, back->next);
        if (!flag || front->val != back->val) return false;
        front = front->next; // move front forward before backtrack back backward
        return true;
    }

public:
    bool isPalindrome(ListNode *head) {
        return isPalindromeRecursive(head, head);
    }
};
// @lc code=end
