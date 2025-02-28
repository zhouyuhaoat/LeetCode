/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 23:36:53
 *   modified:  2025-02-25 12:24:35
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while (l1) {
            st1.emplace(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            st2.emplace(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* head = nullptr;
        while (!st1.empty() || !st2.empty() || carry) {
            int sum = (st1.empty() ? 0 : st1.top()) + (st2.empty() ? 0 : st2.top()) + carry;
            carry = sum / 10;
            if (!st1.empty()) st1.pop();
            if (!st2.empty()) st2.pop();
            ListNode* cur = new ListNode(sum % 10);
            cur->next = head, head = cur; // head insertion
        }
        return head;
    }
};
// @lc code=end
