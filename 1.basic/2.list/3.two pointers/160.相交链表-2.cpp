/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-30 12:41:38
 * 	 modified: 	2025-01-18 10:16:31
 * 	 project: 	LeetCode of labuladong
 * 	 venue: 	914, Harbin
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
        // A: a + c; B: b + c => A: a + c -> B: b <=> B: b + c -> A: a
        // c = 0 => A: a; B: b => A: a -> B: b <=> B: b -> A: a
        // no intersection, all end with nullptr
        while (p != q) {
            // alternate traverse
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};
// @lc code=end
