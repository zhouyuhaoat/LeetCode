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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* front;
    bool isPalindromeRecursive(ListNode* cur) {
        if (cur) {
            if (!isPalindromeRecursive(cur->next)) {
                // recursive to the end of the list
                return false;
            }
            if (cur->val != front->val) { // backtracking
                return false;
            }
            front = front->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        front = head;
        return isPalindromeRecursive(head);
    }
};
// @lc code=end
