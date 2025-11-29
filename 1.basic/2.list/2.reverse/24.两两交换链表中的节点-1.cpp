/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:26
 *   modified:  2025-02-22 11:45:07
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
private:
    pair<ListNode *, ListNode *> reverse(ListNode *head, ListNode *tail) {
        ListNode *prev = nullptr, *curr = head;
        while (prev != tail) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr, curr = next;
        }
        return {tail, head};
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummy(0, head), *pred = &dummy;
        while (head) {
            ListNode *tail = pred;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return dummy.next;
            }
            ListNode *succ = tail->next;
            tie(head, tail) = reverse(head, tail);
            pred->next = head, tail->next = succ;
            pred = tail, head = succ;
        }
        return dummy.next;
    }

public:
    ListNode *swapPairs(ListNode *head) {
        return reverseKGroup(head, 2); // k = 2
    }
};
// @lc code=end
