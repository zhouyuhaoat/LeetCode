/*
 *   author:    zhouyuhao
 *   created:   2024-12-22 22:15:11
 *   modified:  2025-12-13 23:15:49
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
class Solution {
public:
    Node *connect(Node *root) {
        if (!root) return nullptr;
        Node *leftmost = root; // leftmost node of each level
        while (leftmost->left) {
            Node *node = leftmost; // current level
            while (node) { // next level
                node->left->next = node->right; // same parent
                if (node->next) { // different parent
                    node->right->next = node->next->left;
                }
                node = node->next; // connected before
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};
// @lc code=end
