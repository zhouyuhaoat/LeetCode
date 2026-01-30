/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 22:25:11
 *   modified:  2026-01-18 10:09:52
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] 合并零之间的节点
 */

// @lc code=start
class Solution {
public:
    ListNode *mergeNodes(ListNode *head) {
        ListNode *tail = head; // in place
        for (ListNode *curr = head->next; curr->next; curr = curr->next) {
            if (curr->val != 0) {
                tail->val += curr->val;
            } else {
                tail = tail->next;
                tail->val = 0;
            }
        }
        tail->next = nullptr; // cut
        return head;
    }
};
// @lc code=end
