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
    bool isPalindromeRecursive(ListNode *curr, ListNode *& front) {
        /*
            front -> ... -> middle -> ... -> back = curr -> nullptr
            - base case: reach the end of the list
            - recursive call to the next node until reaching the end
            - recursive case: compare front and back
            - move front forward before backtracking to middle
        */
        if (!curr) return true;
        bool flag = isPalindromeRecursive(curr->next, front);
        if (!flag || curr->val != front->val) return false;
        front = front->next;
        return true;
    }

    bool isPalindrome(ListNode *head) {
        return isPalindromeRecursive(head, head);
    }
};
// @lc code=end
