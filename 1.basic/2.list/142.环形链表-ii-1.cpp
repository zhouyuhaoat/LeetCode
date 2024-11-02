/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 11:14:06
 * 	 modified: 	2024-11-02 11:14:55
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
        unordered_set<ListNode*> vis;
        while (head) {
            if (vis.count(head) != 0) {
                return head;
            }
            vis.emplace(head);
            head = head->next;
        }
        return nullptr;
    }
};
// @lc code=end
