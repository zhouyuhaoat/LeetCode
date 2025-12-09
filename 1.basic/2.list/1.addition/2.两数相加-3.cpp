/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:57
 *   modified:  2025-02-22 10:52:06
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0) { // default parameter
        if (!l1 && !l2 && carry == 0) return nullptr;
        int sum = carry;
        if (l1) sum += l1->val, l1 = l1->next;
        if (l2) sum += l2->val, l2 = l2->next;
        return new ListNode(sum % 10, addTwoNumbers(l1, l2, sum / 10));
    }
};
// @lc code=end
