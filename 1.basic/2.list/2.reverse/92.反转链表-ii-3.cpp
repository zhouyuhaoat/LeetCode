/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:25
 *   modified:  2025-02-28 09:43:23
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head), *ptr = &dummy;
        for (int i = 0; i < left - 1; i++) {
            ptr = ptr->next;
        }
        // two pass -> one pass: online
        ListNode *pre = nullptr, *cur = ptr->next;
        // ptr -> left = cur -> ... -> right
        for (int i = left; i < right + 1; i++) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        // nullptr <-
        // ptr -> left <- ... <- right = pre, cur = right + 1
        ptr->next->next = cur, ptr->next = pre; // from right to left
        // ptr -> right -> ... -> left
        return dummy.next;
    }
};
// @lc code=end
