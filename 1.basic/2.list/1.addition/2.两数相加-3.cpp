/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:57
 *   modified:  2025-02-22 10:55:42
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) { // default parameter
        if (!l1 && !l2) return carry > 0 ? new ListNode(carry) : nullptr;
        if (!l1) swap(l1, l2); // ensure l1 != nullptr
        int sum = l1->val + (l2 ? l2->val : 0) + carry;
        l1->val = sum % 10; // (in place) operation on l1, no need to create new node
        l1->next = addTwoNumbers(l1->next, l2 ? l2->next : nullptr, sum / 10);
        return l1;
    }
};
// @lc code=end
