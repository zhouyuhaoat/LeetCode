/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:59
 *   modified:  2025-02-27 18:36:21
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> vis;
        while (head) {
            if (vis.contains(head)) {
                return head;
            }
            vis.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};
// @lc code=end
