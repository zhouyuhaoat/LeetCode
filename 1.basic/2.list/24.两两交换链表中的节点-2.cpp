/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 23:07:24
 * 	 modified: 	2024-11-02 23:14:39
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
        if (head == nullptr || head->next == nullptr) { // pairs
            return head;
        }
        ListNode* newHead = head->next;
        head->next = swapPairs(head->next->next);
        newHead->next = head;
        return newHead;
    }
};
// @lc code=end
