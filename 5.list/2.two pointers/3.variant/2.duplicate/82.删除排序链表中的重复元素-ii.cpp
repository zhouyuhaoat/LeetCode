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
        ListNode dummy(0, head), *pred = &dummy;
        while (pred->next && pred->next->next) { // adjacent
            ListNode *curr = pred->next, *next = curr->next;
            if (curr->val == next->val) { // duplicate
                int val = curr->val; // value
                while (curr && curr->val == val) {
                    ListNode *node = curr;
                    pred->next = curr = curr->next;
                    delete node;
                }
            } else {
                pred = curr;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
