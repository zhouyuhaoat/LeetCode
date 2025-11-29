/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:59
 *   modified:  2025-02-26 11:47:32
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode *partition(ListNode *head, int x) {
        ListNode less, nonLess, *ptrLess = &less, *ptrNonLess = &nonLess; // small, large
        while (head) {
            if (head->val < x) {
                ptrLess = ptrLess->next = head;
            } else {
                ptrNonLess = ptrNonLess->next = head;
            }
            head = head->next;
        }
        ptrLess->next = nonLess.next, ptrNonLess->next = nullptr;
        return less.next;
    }
};
// @lc code=end
