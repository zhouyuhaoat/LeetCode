/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 18:25:03
 *   modified:  2026-01-17 21:29:28
 *   project:   LeetCode
 *   venue:     A20, Harbin
 */

/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] 二进制链表转整数
 */

// @lc code=start
class Solution {
public:
    int getDecimalValue(ListNode *head) {
        int val = 0;
        while (head) {
            val = val * 2 + head->val;
            head = head->next;
        }
        return val;
    }
};
// @lc code=end
