/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:37:33
 *   modified:  2026-01-22 13:49:02
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
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = evenHead;
        return head;
    }
};
// @lc code=end
