/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 10:59:46
 * 	 modified: 	2024-11-02 11:01:32
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> vis;
        while (head) {
            if (vis.count(head) != 0) {
                return true;
            }
            vis.emplace(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end
