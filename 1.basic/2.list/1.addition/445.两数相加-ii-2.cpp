/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-25 12:22:12
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
    ListNode* reverse(ListNode* head) {
        if (!head->next) return head; // single node
        ListNode* newHead = reverse(head->next); // head->next <=> newTail
        /*
                  newHead
                     |
                     v
                    ...
                     |
                     v
                  newTail
                    <=>
        head -> head->next -> ... -> tail
        */
        head->next->next = head; // head <- newTail->next
        head->next = nullptr;
        return newHead;
    }
    ListNode* add(ListNode* l1, ListNode* l2) {
        ListNode dummy, *cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            cur = cur->next = new ListNode(sum % 10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return dummy.next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1), l2 = reverse(l2);
        return reverse(add(l1, l2));
    }
};
// @lc code=end
