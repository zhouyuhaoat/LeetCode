/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-25 11:41:05
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
    void reverse(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
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
        // predecessor & successor
        // pre -> l -> ... -> r -> succ
        r->next = nullptr; // cut for reverse
        reverse(l);
        pre->next = r, l->next = succ; // reconnect
        return dummy.next;
    }
};
// @lc code=end
