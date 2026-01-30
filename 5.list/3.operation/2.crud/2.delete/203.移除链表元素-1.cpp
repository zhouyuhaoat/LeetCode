/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 18:32:40
 *   modified:  2026-01-17 21:29:09
 *   project:   LeetCode
 *   venue:     A20, Harbin
 */

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode dummy(0, head), *pred = &dummy;
        while (pred->next) {
            ListNode *curr = pred->next;
            if (curr->val == val) {
                pred->next = curr->next; // bypass or shortcut
                delete curr;
            } else {
                pred = curr;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
