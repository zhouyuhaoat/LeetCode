/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-28 09:43:45
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head), *pre = &dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        // two pass -> one pass: head insertion
        ListNode* cur = pre->next; // first node
        // head insertion from second node to the last node
        for (int i = left; i < right; i++) {
            ListNode* next = cur->next; // backup
            // pre -> head = pre->next -> ... -> cur -> next -> next->next
            cur->next = next->next;
            next->next = pre->next, pre->next = next; // insert to head
            // pre -> head = pre->next = next -> ... -> cur -> next->next
        }
        return dummy.next;
    }
};
// @lc code=end
