/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-22 11:56:32
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode *pre = nullptr, *cur = head;
        while (pre != tail) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        return {tail, head};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head), *pre = &dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode *l = pre->next, *r = pre;
        for (int i = left; i < right + 1; i++) {
            r = r->next;
        }
        ListNode* succ = r->next;
        // pre -> l -> ... -> r -> succ
        tie(l, r) = reverse(l, r);
        pre->next = l, r->next = succ;
        return dummy.next;
    }
};
// @lc code=end
