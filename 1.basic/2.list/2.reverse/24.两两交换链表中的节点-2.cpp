/*
 *   author:    zhouyuhao
 *   created:   2025-02-25 12:33:08
 *   modified:  2025-02-25 12:38:53
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
        /*
            for each pair, adjust pointers
                - from right to left
                0. prev -> curr -> next -> nextPair
                1.            ------------>
                   prev -> curr   next -> nextPair
                2.            ------------->
                   prev -> curr <- next -> nextPair
                3. prev -> next -> curr -> nextPair
        */
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy, *curr = head;
        while (curr && curr->next) {
            ListNode *next = curr->next;
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            prev = curr, curr = curr->next;
        }
        return dummy->next;
    }
};
// @lc code=end
