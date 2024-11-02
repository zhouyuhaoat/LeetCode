/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-10-31 17:15:07
 * 	 modified: 	2024-11-02 19:05:55
 * 	 project: 	LeetCode
 * 	 venue: 	914, Harbin
 */

/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> A = {head}; // initial
        while (A.back()->next) {
            A.emplace_back(A.back()->next);
        }
        return A[A.size() / 2];
    }
};
// @lc code=end
