/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2025-02-27 19:01:13
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
        ListNode dummy, *curr = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr = curr->next = list1;
                list1 = list1->next;
            } else {
                curr = curr->next = list2;
                list2 = list2->next;
            }
        }
        curr->next = list1 ? list1 : list2;
        return dummy.next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        // iterative: from bottom to up
        for (int stride = 1; stride < n; stride *= 2) {
            for (int i = 0; i + stride < n; i += stride * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + stride]);
            }
        }
        return lists[0];
    }
};
// @lc code=end
