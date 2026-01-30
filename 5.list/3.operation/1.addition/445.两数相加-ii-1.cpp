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
class Solution {
private:
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return prev;
    }

    ListNode *add(ListNode *l1, ListNode *l2) {
        ListNode dummy, *tail = &dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) sum += l1->val, l1 = l1->next;
            if (l2) sum += l2->val, l2 = l2->next;
            tail = tail->next = new ListNode(sum % 10);
            carry = sum / 10;
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
