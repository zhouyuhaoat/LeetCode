/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:01
 *   modified:  2025-02-27 20:14:26
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(0, head), *prev = &dummy;
        while (prev->next && prev->next->next) {
            ListNode *curr = prev->next, *next = curr->next;
            if (curr->val == next->val) {
                int val = curr->val; // value of the duplicate nodes
                while (curr && curr->val == val) {
                    ListNode *node = curr;
                    prev->next = curr = curr->next;
                    delete node;
                }
            } else {
                prev = curr;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
