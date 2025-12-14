/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 18:52:20
 *   modified:  2025-12-13 22:19:56
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
class Solution {
private:
    vector<Node *> prev; // previous node of each level

    void levelorder(Node *node, int level) {
        if (!node) return;
        if (level == (int)prev.size()) { // new level
            prev.emplace_back(node); // leftmost node
        } else {
            prev[level] = prev[level]->next = node; // connect
        }
        levelorder(node->left, level + 1);
        levelorder(node->right, level + 1);
    }

public:
    Node *connect(Node *root) {
        levelorder(root, 0);
        return root;
    }
};
// @lc code=end
