/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:24
 *   modified:  2025-02-22 11:48:21
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
        ListNode *end = tail->next, *pre = nullptr, *cur = head;
        while (cur != end) {
            // cur != tail->next is error
            // since when cur = tail, tail->next is changed
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head), *pre = dummy;
        while (head) {
            ListNode* tail = pre;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return dummy->next;
            }
            ListNode* next = tail->next;
            tie(head, tail) = reverse(head, tail);
            pre->next = head, tail->next = next;
            pre = tail, head = next;
        }
        return dummy->next;
    }
};
// @lc code=end
