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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *pre = dummy, *cur = head;
        while (cur && cur->next) { // pairs
            ListNode* next = cur->next->next; // backup for next pair
            // from left ro right
            // pre -> cur -> cur->next -> next
            pre->next = cur->next;
            //      ----------->
            // 1. pre   cur -> cur->next -> next
            cur->next->next = cur;
            //      ------------>
            // 2. pre   cur <-> cur->next -> next
            cur->next = next;
            // 3. pre -> cur->next -> cur -> next
            pre = cur, cur = next; // next pair: shift right 2 steps
        }
        return dummy->next;
    }
};
// @lc code=end
