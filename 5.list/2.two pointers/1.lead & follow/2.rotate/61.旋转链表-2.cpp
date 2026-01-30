/*
 *   author:    zhouyuhao
 *   created:   2026-01-18 14:35:44
 *   modified:  2026-01-20 10:00:03
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
    pair<int, ListNode *> getSizeAndTail(ListNode *head) {
        int size = 1;
        ListNode *tail = head;
        while (tail->next) {
            size++;
            tail = tail->next;
        }
        return {size, tail};
    }

    ListNode *advance(ListNode *node, int dis) {
        for (int i = 0; i < dis; i++) {
            node = node->next;
        }
        return node;
    }

public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !head->next) return head;
        auto [size, tail] = getSizeAndTail(head);
        k %= size;
        if (k == 0) return head;
        ListNode *newTail = advance(head, (size - 1) - k), *newHead = newTail->next;
        tail->next = head, newTail->next = nullptr;
        return newHead;
    }
};
// @lc code=end
