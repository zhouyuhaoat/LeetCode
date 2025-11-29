/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:01
 *   modified:  2025-02-27 20:56:23
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
class Solution {
private:
    ListNode *middleNode(ListNode *head) { // (right) median
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return prev;
    }

    bool compare(ListNode *head1, ListNode *head2) {
        /*
            head1 -> ... -> median <- ... <- head2
                              |
                              v
                           nullptr
         */
        while (head1 && head2) {
            if (head1->val != head2->val) return false;
            head1 = head1->next, head2 = head2->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head) {
        ListNode *mi = middleNode(head);
        ListNode *reverseHead = reverse(mi);
        return compare(head, reverseHead);
    }
};
// @lc code=end
