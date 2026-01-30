/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:01
 *   modified:  2025-02-27 21:00:41
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
    ListNode *getMedian(ListNode *head) {
        ListNode *lo = head, *hi = head;
        while (hi && hi->next) {
            lo = lo->next;
            hi = hi->next->next;
        }
        return lo;
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
        while (head2) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next, head2 = head2->next;
        }
        return true;
    }

public:
    bool isPalindrome(ListNode *head) {
        ListNode *median = getMedian(head);
        ListNode *tail = reverse(median);
        bool res = compare(head, tail);
        reverse(tail); // restore
        return res;
    }
};
// @lc code=end
