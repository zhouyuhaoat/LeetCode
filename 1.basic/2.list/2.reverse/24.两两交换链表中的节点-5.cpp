/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:26
 *   modified:  2025-02-25 12:36:53
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode dummy(0, head), *pred = &dummy;
        ListNode *curr = head;
        while (curr && curr->next) {
            pred->next = curr->next, curr->next = curr->next->next, pred->next->next = curr;
            // left -> right -> middle
            pred = curr, curr = curr->next;
        }
        return dummy.next;
    }
};
// @lc code=end
