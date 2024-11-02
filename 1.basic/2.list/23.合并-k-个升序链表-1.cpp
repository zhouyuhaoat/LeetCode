/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 18:22:10
 * 	 modified: 	2024-11-02 18:24:29
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* cur = &dummy;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        cur->next = list1 ? list1 : list2;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = nullptr; // space: O(1)
        for (size_t i = 0; i < lists.size(); i++) {
            res = mergeTwoLists(res, lists[i]);
        }
        return res;
    }
};
// @lc code=end
