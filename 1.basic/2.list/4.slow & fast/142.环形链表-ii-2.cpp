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
        /*
            slow and fast pointers
            - Floyd's cycle detection algorithm
            - list = non-cycle + cycle
            - fast = 2 * slow; fast - slow = k * cycle
                - slow = k * cycle
            - target: find the entry of the cycle
                - entry = non-cycle + k * cycle = non-cycle + slow
                - make slow move forward non-cycle steps more
            - the distance between slow and the entry is exactly non-cycle steps
                - if slow starts from the entry, eventually it will returns to the entry
                - however, since slow has already moved non-cycle steps, it hasn't reached the entry yet
                - therefore, move non-cycle steps more, it will reach the entry of the cycle
        */
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode *nonCycle = head;
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
