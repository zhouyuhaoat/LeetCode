/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 10:32:26
 *   modified:  2025-04-01 13:17:17
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            swap(node->left, node->right); // from top down-to bottom
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
        return root;
    }
};
// @lc code=end
