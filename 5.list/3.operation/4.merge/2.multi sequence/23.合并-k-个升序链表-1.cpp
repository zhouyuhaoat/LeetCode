/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2025-02-27 18:59:27
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start
class Solution {
private:
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

public:
    ListNode *mergeKLists(vector<ListNode *>& lists) {
        ListNode *res = nullptr;
        for (ListNode *list : lists) {
            res = mergeTwoLists(res, list);
        }
        return res;
    }
};
// @lc code=end
