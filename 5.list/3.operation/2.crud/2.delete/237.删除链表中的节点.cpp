/*
 *   author:    zhouyuhao
 *   created:   2025-12-16 15:23:55
 *   modified:  2025-12-16 15:52:16
 *   project:   LeetCode of 0x3f
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 */

// @lc code=start
class Solution {
public:
    void deleteNode(ListNode *node) {
        ListNode *next = node->next; // 李代桃僵
        *node = *next; // node->val = next->val, node->next = next->next;
        delete next;
    }
};
// @lc code=end
