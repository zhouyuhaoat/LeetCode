/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:37:39
 *   modified:  2026-01-18 22:26:24
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 *
 * [2816] 翻倍以链表形式表示的数字
 */

// @lc code=start
class Solution {
public:
    ListNode *doubleIt(ListNode *head) {
        if (head->val >= 5) {
            head = new ListNode(0, head);
        }
        for (ListNode *curr = head; curr; curr = curr->next) {
            curr->val = (curr->val * 2) % 10;
            if (curr->next && curr->next->val >= 5) { // carry
                curr->val++;
            }
        }
        return head;
    }
};
// @lc code=end
