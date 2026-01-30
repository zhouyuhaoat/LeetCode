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
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0) {
        if (!l1 && !l2) return carry ? new ListNode(carry) : nullptr;
        if (!l1) swap(l1, l2); // assure l1 is not null
        int sum = l1->val + carry;
        if (l2) sum += l2->val, l2 = l2->next;
        l1->val = sum % 10; // in place
        l1->next = addTwoNumbers(l1->next, l2, sum / 10);
        return l1;
    }
};
// @lc code=end
