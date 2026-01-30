/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:36:43
 *   modified:  2026-01-22 16:09:58
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] 链表最大孪生和
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

    int maxTwinSum(ListNode *head1, ListNode *head2) {
        int sum = -1;
        while (head2) {
            sum = max(sum, head1->val + head2->val);
            head1 = head1->next, head2 = head2->next;
        }
        return sum;
    }

public:
    int pairSum(ListNode *head) {
        ListNode *median = getMedian(head);
        ListNode *tail = reverse(median);
        return maxTwinSum(head, tail);
    }
};
// @lc code=end
