/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-28 09:48:14
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        /*
            slow and fast pointers
            - slow: tortoise; fast: hare
            - relative speed
                - slow moves 1 step, fast moves 2 steps
                - stationary slow vs. moving fast
            - no cycle
                - fast will reach the end of the list
            - cycle
                - slow and fast will get stuck in the cycle
                - fast will eventually catch up with slow
        */
        while (fast && fast->next) { // loop: at least 2 nodes
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
// @lc code=end
