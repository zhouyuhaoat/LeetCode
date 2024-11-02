/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 11:28:58
 * 	 modified: 	2024-11-02 11:29:32
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> vis;
        ListNode* ptr = headA;
        while (ptr) {
            vis.emplace(ptr);
            ptr = ptr->next;
        }
        ptr = headB;
        while (ptr) {
            if (vis.count(ptr) != 0) {
                return ptr;
            }
            ptr = ptr->next;
        }
        return nullptr;
    }
};
// @lc code=end
