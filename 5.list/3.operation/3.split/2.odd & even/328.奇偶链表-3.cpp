/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:37:33
 *   modified:  2026-01-22 15:32:55
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

// @lc code=start
class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head) return nullptr;
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (odd->next && odd->next->next) { // stride = 2
            odd = odd->next = odd->next->next;
            even = even->next = even->next->next;
        }
        odd->next = evenHead; // connect
        return head;
    }
};
// @lc code=end
