/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 18:13:35
 * 	 modified: 	2024-11-02 18:31:28
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* a, const ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q;
        for (ListNode* head : lists) {
            if (head) q.emplace(head);
        }
        ListNode dummy;
        ListNode* cur = &dummy;
        while (!q.empty()) {
            ListNode* t = q.top();
            q.pop();
            if (t->next) q.emplace(t->next);
            cur->next = t;
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end
