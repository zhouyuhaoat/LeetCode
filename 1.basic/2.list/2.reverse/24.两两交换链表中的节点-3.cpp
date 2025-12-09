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
        ListNode dummy(0, head), *pred = &dummy;
        ListNode *curr = head;
        while (curr && curr->next) {
            ListNode *next = curr->next, *succ = curr->next->next;
            curr->next = succ, next->next = curr, pred->next = next;
            /*
                from right to left
                1. right: curr->next = succ
                    pred -> curr   next -> succ
                               ------------>
                2. middle: next->next = curr
                    pred -> curr <- next   succ
                               ------------>
                3. left: pred->next = next
                       ------------>
                    pred   curr <- next   succ
                               ----------->
             */
            pred = curr, curr = succ;
        }
        return dummy.next;
    }
};
// @lc code=end
