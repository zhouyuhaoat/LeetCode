/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 10:28:42
 *   modified:  2025-03-09 16:35:13
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
        invertTree(root->left), invertTree(root->right);
        swap(root->left, root->right); // from bottom up-to top
        return root;
    }
};
// @lc code=end
