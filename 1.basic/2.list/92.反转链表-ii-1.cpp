/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 00:55:07
 * 	 modified: 	2024-11-03 00:58:19
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
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
        ListNode dummy(0, head), *ps = &dummy;
        for (int i = 0; i < left - 1; i++) {
            ps = ps->next;
        }
        ListNode *pre = nullptr, *cur = ps->next;
        for (int i = left; i < right + 1; i++) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        ps->next->next = cur;
        ps->next = pre;
        return dummy.next;
    }
};
// @lc code=end
