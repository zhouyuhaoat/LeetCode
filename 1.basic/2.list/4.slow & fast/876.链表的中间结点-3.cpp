/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-27 18:41:02
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *slow = head, *fast = head;
        /*
            minimum working example (MWE):
            1. odd: 1, 3, ...
                - fast stops at the tail
            2. even: 2, ...
                - fast stops until null
        */
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
// @lc code=end
