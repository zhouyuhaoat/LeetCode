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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        // Floyd's cycle detection: turtle, hare
        ListNode *slow = head, *fast = head;
        // list = head + cycle = a + c
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next; // f = 2s
            if (slow == fast) { // f - s = nc
                // => f = 2nc, s = nc
                // cycle begins: k = a + nc = head + slow
                // slow move forward more head steps
                fast = head;
                while (slow != fast) {
                    slow = slow->next, fast = fast->next;
                }
                return slow;
                // list = head + list; f = 2nc; s = nc
                // if slow starts from the entry of cycle, eventually it will returns to the entry
                // however, since slow has already moved head steps, it hasn't reached the entry yet
                // the distance between it's current position and the entry is exactly head steps
                // therefore, move head steps more, it will reach the entry of the cycle
            }
        }
        return nullptr;
    }
};
// @lc code=end
