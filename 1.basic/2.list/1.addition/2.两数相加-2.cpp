/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:57
 *   modified:  2025-02-22 10:52:06
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
        if (!l1 && !l2) { // base cases
            return nullptr;
        } else if (!l1) {
            return l2;
        } else if (!l2) {
            return l1;
        }
        int sum = l1->val + l2->val;
        ListNode* head = new ListNode(sum % 10);
        head->next = addTwoNumbers(l1->next, l2->next); // recursion
        if (sum >= 10) { // carry to next
            head->next = addTwoNumbers(head->next, new ListNode(1));
        }
        return head;
    }
};
// @lc code=end
