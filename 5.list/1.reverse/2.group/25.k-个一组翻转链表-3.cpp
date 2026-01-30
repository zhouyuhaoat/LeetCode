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

    void reverse(ListNode *& prev, ListNode *& curr, int size) {
        for (int i = 0; i < size; i++) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0, head), *pred = &dummy;
        ListNode *prev = nullptr, *curr = head;
        for (int size = getSize(head); size >= k; size -= k) {
            ListNode *head = pred->next;
            reverse(prev, curr, k);
            ListNode *tail = prev, *succ = curr;
            head->next = succ, pred->next = tail; // from right to left
            pred = head;
        }
        return dummy.next;
    }
};
// @lc code=end
