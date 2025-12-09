/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-22 11:53:29
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
private:
    ListNode *reverse(ListNode *head) {
        // reverse a singly linked list
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next; // backup
            curr->next = prev; // reverse
            prev = curr, curr = next; // shift
        }
        return prev;
    }

    ListNode *add(ListNode *l1, ListNode *l2) {
        ListNode dummy, *curr = &dummy;
        int carry = 0;
        while (l1 || l2 || carry > 0) {
            int sum = carry;
            if (l1) sum += l1->val, l1 = l1->next;
            if (l2) sum += l2->val, l2 = l2->next;
            carry = sum / 10;
            curr = curr->next = new ListNode(sum % 10);
        }
        return dummy.next;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        return reverse(add(l1, l2));
    }
};
// @lc code=end
