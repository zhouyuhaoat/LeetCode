/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 01:19:44
 * 	 modified: 	2024-11-03 01:22:18
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while (head) {
            v.emplace_back(head->val);
            head = head->next;
        }
        for (int i = 0, j = (int)v.size() - 1; i < j; ++i, --j) {
            if (v[i] != v[j]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
