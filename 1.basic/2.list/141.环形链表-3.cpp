/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 11:07:32
 * 	 modified: 	2024-11-02 11:13:14
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
    bool hasCycle(ListNode* head) {
        ListNode* rev = reverseList(head);
        if (head && head->next && rev == head) {
            // loop -> reverse -> the same head pointer
            return true;
        }
        return false;
    }
};
// @lc code=end
