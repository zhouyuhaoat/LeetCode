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
    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
        /*
            reverse a singly linked list [head, tail]
            - until the previous node is the tail
            - return [tail, head] as the new head and tail of the reversed list
        */
        ListNode *prev = nullptr, *curr = head;
        while (prev != tail) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *dummy = new ListNode(0, head), *prev = dummy;
        while (head) {
            ListNode *tail = prev;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return dummy->next;
            }
            ListNode *nextGroup = tail->next;
            // prev -> head -> ... -> tail -> nextGroup
            tie(head, tail) = reverse(head, tail);
            prev->next = head, tail->next = nextGroup; // connect
            prev = tail, head = nextGroup; // move to next group
        }
        return dummy->next;
    }
};
// @lc code=end
