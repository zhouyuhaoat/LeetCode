/*
 * 	 author: 	zhouyuhao
 * 	 created: 	2024-11-02 18:13:35
 * 	 modified: 	2024-11-02 18:47:18
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
    struct cmp {
        int val;
        ListNode* next;
        bool operator<(const cmp& a) const {
            return val > a.val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<cmp> q;
        for (ListNode* head : lists) {
            if (head) {
                q.emplace(head->val, head);
            }
        }
        ListNode dummy, *cur = &dummy;
        while (!q.empty()) {
            cmp t = q.top();
            q.pop();
            if (t.next->next) {
                q.emplace(t.next->next->val, t.next->next);
            }
            cur->next = t.next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
// @lc code=end
