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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) return nullptr;
        if (!l1 || !l2) return l1 ? l1 : l2;
        int sum = l1->val + l2->val;
        ListNode *head = new ListNode(sum % 10);
        head->next = addTwoNumbers(l1->next, l2->next);
        if (int carry = sum / 10) {
            head->next = addTwoNumbers(head->next, new ListNode(carry));
        }
        return head;
    }
};
// @lc code=end
