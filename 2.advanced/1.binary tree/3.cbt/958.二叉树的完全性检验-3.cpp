/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:41:40
 *   modified:  2025-03-19 18:20:38
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
 */

// @lc code=start
class Solution {
public:
    bool isCompleteTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.emplace(root);
        bool flag = false; // whether we have seen a nullptr
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node) {
                // if nullptr, then all nodes after it must be nullptr
                if (flag) return false; // there is a nullptr before non-empty node
                q.emplace(node->left);
                q.emplace(node->right);
            } else {
                flag = true;
            }
        }
        return true;
    }
};
// @lc code=end
