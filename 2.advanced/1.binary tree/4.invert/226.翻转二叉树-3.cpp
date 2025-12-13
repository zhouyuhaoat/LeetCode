/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 10:30:40
 *   modified:  2025-03-08 22:58:52
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
        if (!root) return nullptr;
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right, root->right = left; // from bottom up-to top
        return root;
    }
};
// @lc code=end
