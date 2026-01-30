/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 10:43:46
 *   modified:  2026-01-18 14:02:01
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2807 lang=cpp
 *
 * [2807] 在链表中插入最大公约数
 */

// @lc code=start
class Solution {
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head) {
        ListNode *curr = head;
        while (curr->next) {
            ListNode *next = curr->next;
            curr->next = new ListNode(gcd(curr->val, next->val), next);
            curr = next;
        }
        return head;
    }
};
// @lc code=end
