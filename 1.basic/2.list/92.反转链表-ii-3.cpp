/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 01:07:35
 * 	 modified: 	2024-11-03 01:18:51
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
        ListNode dummy(0, head), *pre = &dummy;
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        ListNode* cur = pre->next; // head insertion
        for (int i = left; i < right; i++) {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy.next;
    }
};
// @lc code=end
