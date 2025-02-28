/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:26
 *   modified:  2025-02-25 12:24:52
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
        string a, b;
        while (l1) {
            a.push_back(l1->val + '0');
            l1 = l1->next;
        }
        while (l2) {
            b.push_back(l2->val + '0');
            l2 = l2->next;
        }
        ListNode* head = nullptr;
        int lo = a.size() - 1, hi = b.size() - 1, carry = 0;
        while (lo >= 0 || hi >= 0 || carry) {
            int sum = (lo >= 0 ? a[lo--] - '0' : 0) + (hi >= 0 ? b[hi--] - '0' : 0) + carry;
            carry = sum / 10;
            ListNode* cur = new ListNode(sum % 10);
            cur->next = head, head = cur; // head insertion
        }
        return head;
    }
};
// @lc code=end
