/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 11:29:54
 * 	 modified: 	2024-11-02 11:56:06
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
        ListNode *p = headA, *q = headB;
        // A: a + c; B: b + c => A: a + c -> B: b = B: b + c -> A: a
        while (p != q) { // if no intersect, all end with nullptr
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};
// @lc code=end
