/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:26
 *   modified:  2025-02-25 12:36:53
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
public:
    ListNode *swapPairs(ListNode *head) {
        /*
            swap pairs of nodes in a linked list
            - pairs, backup, move
            - for each pair, adjust pointers
                - from left to right
                0. prev -> curr -> next -> nextPair
                1.    ------------>
                   prev   curr -> next -> nextPair
                2.    ------------->
                   prev   curr <-> next -> nextPair
                3. prev -> next -> curr -> nextPair
        */
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy, *curr = head;
        while (curr && curr->next) {
            ListNode *nextPair = curr->next->next;
            prev->next = curr->next;
            curr->next->next = curr;
            curr->next = nextPair;
            prev = curr, curr = nextPair;
        }
        return dummy->next;
    }
};
// @lc code=end
