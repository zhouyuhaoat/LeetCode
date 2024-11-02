/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-01 23:07:59
 * 	 modified: 	2024-11-01 23:20:15
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) { // base
            return nullptr;
        } else if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        int sum = l1->val + l2->val;
        ListNode* head = new ListNode(sum % 10);
        head->next = addTwoNumbers(l1->next, l2->next); // recursion
        if (sum >= 10) {
            head->next = addTwoNumbers(head->next, new ListNode(sum / 10)); // carry
        }
        return head;
    }
};
// @lc code=end
