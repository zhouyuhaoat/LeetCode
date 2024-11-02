/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-03 00:41:31
 * 	 modified: 	2024-11-03 00:49:12
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        ListNode dummy(0, head), *cur = &dummy;
        while (cur->next && cur->next->next) { // pairs
            int val = cur->next->val;
            if (cur->next->next->val == val) { // repeat
                while (cur->next && cur->next->val == val) { // multiple
                    ListNode* next = cur->next;
                    cur->next = cur->next->next;
                    delete next;
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end
