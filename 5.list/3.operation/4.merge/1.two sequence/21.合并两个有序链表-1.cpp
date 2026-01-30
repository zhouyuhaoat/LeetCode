/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2025-02-23 13:15:22
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummy, *tail = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail = tail->next = list1;
                list1 = list1->next;
            } else {
                tail = tail->next = list2;
                list2 = list2->next;
            }
        }
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};
// @lc code=end
