/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 22:25:11
 *   modified:  2026-01-18 10:05:20
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
        ListNode dummy, *tail = &dummy;
        int sum = 0;
        for (ListNode *curr = head->next; curr; curr = curr->next) {
            if (curr->val != 0) {
                sum += curr->val;
            } else {
                tail = tail->next = new ListNode(sum);
                sum = 0;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
