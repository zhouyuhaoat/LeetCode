/*
 *   author:    zhouyuhao
 *   created:   2026-01-17 22:30:47
 *   modified:  2026-01-18 10:15:45
 *   project:   LeetCode
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
 */

// @lc code=start
class Solution {
private:
    int getSize(ListNode *head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

    ListNode *advance(ListNode *node, int dis) {
        for (int i = 0; i < dis; i++) {
            node = node->next;
        }
        return node;
    }

public:
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        vector<ListNode *> parts(k);
        int size = getSize(head), base = size / k, extra = size % k;
        for (int i = 0; i < k && head; i++) {
            parts[i] = head;
            int group = base + (i < extra ? 1 : 0); // group size
            ListNode *tail = advance(head, group - 1), *succ = tail->next;
            tail->next = nullptr; // cut
            head = succ;
        }
        return parts;
    }
};
// @lc code=end
