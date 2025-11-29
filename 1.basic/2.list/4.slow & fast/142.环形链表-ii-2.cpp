/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:59
 *   modified:  2025-02-28 10:09:59
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // slow and fast pointers: Floyd's cycle detection algorithm
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *nonCycle = head; // move from head
                while (slow != nonCycle) {
                    slow = slow->next;
                    nonCycle = nonCycle->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
// @lc code=end
