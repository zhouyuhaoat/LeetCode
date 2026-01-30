/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 10:46:21
 *   modified:  2026-01-19 22:00:37
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 *
 * [2074] 反转偶数长度组的节点
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

    ListNode *advance(ListNode *node, int dis) {
        for (int i = 0; i < dis; i++) {
            node = node->next;
        }
        return node;
    }

public:
    ListNode *reverseEvenLengthGroups(ListNode *head) {
        ListNode dummy(0, head), *pred = &dummy;
        int group = 0;
        for (int size = getSize(head); size > 0; size -= group) {
            int len = min(++group, size); // actual size
            if (len % 2 == 0) {
                ListNode *head = pred->next;
                ListNode *prev = nullptr, *curr = head;
                reverse(prev, curr, len);
                ListNode *tail = prev, *succ = curr;
                // pred -> head <- ... <- tail   succ
                pred->next = tail, head->next = succ;
                pred = head;
            } else {
                pred = advance(pred, len);
            }
        }
        return dummy.next;
    }
};
// @lc code=end
