/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2025-02-27 20:41:00
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0, head), *ptr = &dummy;
        stack<ListNode *> stk;
        while (ptr) {
            stk.emplace(ptr);
            ptr = ptr->next;
        }
        while (n--) { // from end
            stk.pop();
        }
        ListNode *prev = stk.top(), *node = prev->next;
        prev->next = prev->next->next;
        delete node;
        return dummy.next;
    }
};
// @lc code=end
