/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-27 18:19:00
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> vis;
        while (head) {
            if (vis.contains(head)) {
                return true;
            }
            vis.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end
