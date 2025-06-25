/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2025-06-25 16:06:53
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
        ListNode dummy{0, head};
        ListNode *lo = &dummy, *hi = &dummy;
        /*
            lead and follow pointers
            - lo = dummy
                - ensure lo->next is not null
                - for access lo->next->next if only one node
            - same start
                - distance between lo and hi
                - hi is n nodes ahead of lo
            - hi stops at the tail of the list
        */
        while (n--) {
            hi = hi->next;
        }
        while (hi->next) {
            lo = lo->next, hi = hi->next;
        }
        ListNode *node = lo->next;
        lo->next = lo->next->next;
        delete node;
        return dummy.next;
    }
};
// @lc code=end
