/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:01
 *   modified:  2025-02-27 20:19:55
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *curr = head;
        while (curr && curr->next) {
            ListNode *next = curr->next;
            while (next && curr->val == next->val) {
                ListNode *node = next;
                curr->next = next = next->next;
                delete node;
            }
            if (next) curr = next;
        }
        return head;
    }
};
// @lc code=end
