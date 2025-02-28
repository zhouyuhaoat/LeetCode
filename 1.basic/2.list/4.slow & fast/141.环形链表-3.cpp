/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-27 18:51:06
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        return pre;
    }
    bool hasCycle(ListNode* head) {
        ListNode* rev = reverse(head);
        if (head && head->next && rev == head) {
            // loop -> reverse -> the same head pointer
            /*
            3 -> 2 -> 0 -> -4
                 ^----------
            after reverse the entry point of the loop
            3 <- 2 -> 0 -> -4
                 ^----------
            */
            return true;
        }
        return false;
    }
};
// @lc code=end
