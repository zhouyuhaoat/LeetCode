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

    ListNode *merge(vector<ListNode *>& lists, int lo, int hi) { // [lo, hi)
        if (lo == hi) return nullptr;
        if (hi - lo == 1) return lists[lo];
        int mi = lo + (hi - lo) / 2;
        // recursive: from top down-to bottom
        ListNode *left = merge(lists, lo, mi), *right = merge(lists, mi, hi);
        return mergeTwoLists(left, right);
    }

public:
    ListNode *mergeKLists(vector<ListNode *>& lists) {
        return merge(lists, 0, lists.size()); // divide and conquer
    }
};
// @lc code=end
