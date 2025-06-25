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
public:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return prev;
    }

    bool hasCycle(ListNode *head) {
        ListNode *reverseHead = reverse(head);
        if (head && head->next && reverseHead == head) {
            /*
                loop -> reverse -> the same head pointer
                - original
                    3 -> 2 -> 0 -> -4
                         ^----------
                - after reverse
                    3 -> 2 <- 0 <- -4
                         ----------^
            */
            return true;
        }
        return false;
    }
};
// @lc code=end
