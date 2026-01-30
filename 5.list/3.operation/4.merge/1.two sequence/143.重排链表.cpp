/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 15:22:53
 *   modified:  2025-12-17 09:17:34
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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

    void merge(ListNode *head1, ListNode *head2) {
        /*
            head1 -> ... -> median <- ... <- head2
                              |
                              v
                           nullptr
         */
        while (head2->next) { // head2 <= head1
            ListNode *next1 = head1->next, *next2 = head2->next;
            head1->next = head2, head2->next = next1;
            head1 = next1, head2 = next2;
        }
    }

public:
    void reorderList(ListNode *head) {
        ListNode *median = getMedian(head);
        ListNode *tail = reverse(median);
        merge(head, tail);
    }
};
// @lc code=end
