/*
 *   author:    zhouyuhao
 *   created:   2025-02-26 11:56:40
 *   modified:  2025-06-24 20:38:12
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
        if (!list1 || (list2 && list1->val > list2->val)) {
            swap(list1, list2); // ensure list1 is the smaller one
        }
        if (list1) list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
};
// @lc code=end
