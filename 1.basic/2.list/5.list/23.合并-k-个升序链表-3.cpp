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
class Solution {
public:
    struct cmp {
        bool operator()(const ListNode *a, const ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for (ListNode *head : lists) {
            if (head) q.emplace(head);
        }
        ListNode dummy, *curr = &dummy;
        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            if (node->next) q.emplace(node->next);
            curr = curr->next = node;
        }
        return dummy.next;
    }
};
// @lc code=end
