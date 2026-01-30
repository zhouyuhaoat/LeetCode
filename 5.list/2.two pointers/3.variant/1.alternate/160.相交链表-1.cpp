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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode *> vis;
        while (headA) {
            vis.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (vis.contains(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};
// @lc code=end
