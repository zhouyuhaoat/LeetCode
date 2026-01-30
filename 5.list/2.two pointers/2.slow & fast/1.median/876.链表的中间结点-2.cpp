/*
 *   author:    zhouyuhao
 *   created:   2025-01-18 10:38:58
 *   modified:  2025-02-27 18:40:42
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
    ListNode *middleNode(ListNode *head) {
        return advance(head, getSize(head) / 2);
    }
};
// @lc code=end
