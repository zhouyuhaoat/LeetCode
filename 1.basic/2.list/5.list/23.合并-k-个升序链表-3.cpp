/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:00
 *   modified:  2025-02-28 10:16:33
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
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
    struct node {
        int val;
        ListNode* next;
        bool operator<(const node& a) const {
            return val > a.val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority queue is simply an improvement over the native multi-pointer merging approach
        priority_queue<node> q;
        for (ListNode* head : lists) {
            if (head) q.emplace(head->val, head);
        }
        ListNode dummy, *cur = &dummy;
        while (!q.empty()) {
            node t = q.top();
            q.pop();
            if (t.next->next) {
                q.emplace(t.next->next->val, t.next->next);
            }
            cur = cur->next = t.next;
        }
        return dummy.next;
    }
};
// @lc code=end
