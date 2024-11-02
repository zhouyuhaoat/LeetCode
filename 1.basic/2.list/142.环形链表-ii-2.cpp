/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 11:18:17
 * 	 modified: 	2024-11-02 11:27:50
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
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
        // list = head + cycle = a + b
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next; // f = 2s
            if (slow == fast) { // f - s = nb
                // => f = 2nb, s = nb
                // cycle begins: k = a + nb = head + slow
                fast = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
// @lc code=end
