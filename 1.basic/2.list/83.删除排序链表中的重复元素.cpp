/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 00:49:32
 * 	 modified: 	2024-11-03 00:54:33
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* cur = head;
        while (cur->next) {
            if (cur->next->val == cur->val) {
                ListNode* next = cur->next;
                cur->next = cur->next->next;
                delete next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end
