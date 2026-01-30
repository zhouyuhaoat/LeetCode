/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:35:44
 *   modified:  2026-01-18 18:19:18
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

// @lc code=start
class Solution {
private:
    int getSize(ListNode *head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode *getNthFromEnd(ListNode *head, int n) {
        ListNode *lo = head, *hi = head;
        while (n--) {
            hi = hi->next;
        }
        while (hi) {
            lo = lo->next, hi = hi->next;
        }
        return lo;
    }

    ListNode *getTail(ListNode *head) {
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        return tail;
    }

public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head; // empty list or single node
        k %= getSize(head);
        if (k == 0) return head;
        ListNode *newTail = getNthFromEnd(head, k + 1), *newHead = newTail->next;
        getTail(newHead)->next = head, newTail->next = nullptr; // cycle & break
        return newHead;
    }
};
// @lc code=end
