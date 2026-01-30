/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-27 18:51:06
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
private:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return prev;
    }

public:
    bool hasCycle(ListNode *head) {
        if (head && head->next) { // at least two nodes
            // cycle -> reverse -> the same head
            if (head == reverse(head)) {
                return true;
            }
        }
        /*
            1. original
                3 -> 2 -> 0 -> -4
                     ^----------
            2. after reverse
                3 -> 2 <- 0 <- -4
                     ----------^
         */
        return false;
    }
};
// @lc code=end
