/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:39:01
 *   modified:  2025-02-28 10:16:22
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
    ListNode *mergeKLists(vector<ListNode *>& lists) {
        auto cmp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (ListNode *head : lists) { // native multi-way merge + optimize with min-heap
            if (head) {
                pq.push(head);
            }
        }
        ListNode dummy, *tail = &dummy;
        while (!pq.empty()) {
            ListNode *node = pq.top();
            pq.pop();
            if (node->next) {
                pq.push(node->next);
            }
            tail = tail->next = node;
        }
        return dummy.next;
    }
};
// @lc code=end
