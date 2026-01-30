/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:37:39
 *   modified:  2026-01-18 18:47:03
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 *
 * [2816] 翻倍以链表形式表示的数字
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
    ListNode *doubleIt(ListNode *head) {
        head = reverse(head);
        return reverse(add(head, head));
    }
};
// @lc code=end
