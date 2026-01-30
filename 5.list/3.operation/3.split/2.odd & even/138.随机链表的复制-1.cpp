/*
 *   author:    zhouyuhao
 *   created:   2025-12-23 21:56:53
 *   modified:  2026-01-20 21:22:34
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */

// @lc code=start
class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;

        for (Node *curr = head; curr; curr = curr->next->next) { // copy & interleaved
            curr->next = new Node(curr->val, curr->next, nullptr);
        }

        for (Node *curr = head; curr; curr = curr->next->next) { // assign random for each pair
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
        }

        Node *orig = head, *copy = head->next, *copyHead = copy; // original odd & copy even
        while (copy && copy->next) {
            orig = orig->next = copy->next;
            copy = copy->next = orig->next;
        }
        orig->next = nullptr; // restore
        return copyHead;
    }
};
// @lc code=end
