/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:59
 *   modified:  2025-06-25 16:06:46
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        /*
            alternate traverse two lists with two pointers
            - list: specific part + common or share part
                A:  a ---------
                                \
                                  ----------- c
                                /
                B:   b --------
            - a + c + b = b + c + a
                - The key is that both pointers will traverse the same number of nodes.
                - If there is no intersection (c = 0), both pointers will eventually reach nullptr.
        */
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }
        return p;
    }
};
// @lc code=end
