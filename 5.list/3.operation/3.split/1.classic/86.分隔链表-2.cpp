/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:59
 *   modified:  2026-01-22 14:16:06
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */

// @lc code=start
class Solution {
private:
    struct List {
        ListNode *head, *tail;
    };

    pair<List, List> splitByValue(ListNode *head, int val) {
        ListNode dummy1, dummy2, *tail1 = &dummy1, *tail2 = &dummy2;
        while (head) {
            if (head->val < val) {
                tail1 = tail1->next = head;
            } else {
                tail2 = tail2->next = head;
            }
            head = head->next;
        }
        tail1->next = nullptr, tail2->next = nullptr; // cut
        return {{dummy1.next, tail1}, {dummy2.next, tail2}};
    }

public:
    ListNode *partition(ListNode *head, int x) {
        auto [list1, list2] = splitByValue(head, x);
        if (list1.head) {
            list1.tail->next = list2.head; // connect
            return list1.head;
        } else {
            return list2.head;
        }
    }
};
// @lc code=end
