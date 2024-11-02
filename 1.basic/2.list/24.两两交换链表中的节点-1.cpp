/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 22:54:16
 * 	 modified: 	2024-11-02 23:06:41
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
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
            ListNode* next = cur->next->next;
            pre->next = cur->next;
            pre->next->next = cur;
            cur->next = next;
            pre = cur;
            cur = next;
        }
        return dummy->next;
    }
};
// @lc code=end
