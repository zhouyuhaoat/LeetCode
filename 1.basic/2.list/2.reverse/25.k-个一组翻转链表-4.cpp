/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-22 11:48:04
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0, head), *pred = &dummy;
        ListNode *prev = nullptr, *curr = head;
        for (int n = getSize(head); n >= k; n -= k) {
            head = pred->next;
            for (int i = 0; i < k; i++) {
                ListNode *next = curr->next;
                curr->next = prev;
                prev = curr, curr = next;
            }
            pred->next->next = curr, pred->next = prev; // from right to left
            pred = head;
        }
        return dummy.next;
    }
};
// @lc code=end
