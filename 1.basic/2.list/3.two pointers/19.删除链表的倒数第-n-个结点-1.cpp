/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2025-02-27 20:39:39
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getSize(ListNode *head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n) { // n: 1-based index
        ListNode dummy(0, head), *prev = &dummy;
        int size = getSize(head);
        // previous node: [size - n - 1] -> deleted node: [size - n]
        for (int i = 0; i < size - n; i++) {
            prev = prev->next;
        }
        ListNode *node = prev->next;
        prev->next = prev->next->next; // bypass or shortcut
        delete node;
        return dummy.next;
    }
};
// @lc code=end
