/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 18:53:25
 * 	 modified: 	2024-11-02 19:02:52
 * 	 project: 	LeetCode
 * 	 venue: 	226, Harbin
 */

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode ds, db, *s = &ds, *b = &db;
        while (head) {
            if (head->val < x) {
                s->next = head;
                s = s->next;
            } else {
                b->next = head;
                b = b->next;
            }
            head = head->next;
        }
        s->next = db.next;
        b->next = nullptr; // end of list
        return ds.next;
    }
};
// @lc code=end
