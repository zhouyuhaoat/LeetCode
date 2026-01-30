/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 10:31:47
 *   modified:  2026-01-18 10:36:16
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] 合并两个链表
 */

// @lc code=start
class Solution {
private:
    ListNode *advance(ListNode *node, int dis) {
        for (int i = 0; i < dis; ++i) {
            node = node->next;
        }
        return node;
    }

    ListNode *getTail(ListNode *head) {
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        return tail;
    }

public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *pred = advance(list1, a - 1), *succ = advance(pred, (b - a + 1) + 1); // position
        pred->next = list2, getTail(list2)->next = succ; // connect
        return list1;
    }
};
// @lc code=end
