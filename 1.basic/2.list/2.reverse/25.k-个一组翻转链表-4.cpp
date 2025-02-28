/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:24
 *   modified:  2025-02-22 11:51:21
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            if (!cur) return head;
            cur = cur->next;
        }
        ListNode* pre = nullptr;
        cur = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        head->next = reverseKGroup(cur, k);
        return pre;
    }
};
// @lc code=end
