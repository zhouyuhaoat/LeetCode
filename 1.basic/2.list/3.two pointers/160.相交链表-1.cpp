/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:59
 *   modified:  2025-06-25 16:06:32
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> vis;
        ListNode *ptr = headA;
        while (ptr) {
            vis.emplace(ptr);
            ptr = ptr->next;
        }
        ptr = headB;
        while (ptr) {
            if (vis.contains(ptr)) return ptr;
            ptr = ptr->next;
        }
        return nullptr;
    }
};
// @lc code=end
