/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:37:33
 *   modified:  2026-01-22 14:29:33
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
        ListNode dummy1, dummy2, *odd = &dummy1, *even = &dummy2;
        int idx = 0;
        while (head) {
            if (++idx % 2 == 1) {
                odd = odd->next = head;
            } else {
                even = even->next = head;
            }
            head = head->next;
        }
        odd->next = dummy2.next, even->next = nullptr; // connect & cut
        return dummy1.next;
    }
};
// @lc code=end
