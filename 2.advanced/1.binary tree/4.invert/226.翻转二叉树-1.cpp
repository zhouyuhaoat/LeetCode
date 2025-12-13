/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 10:27:21
 *   modified:  2025-03-09 17:09:13
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return nullptr;
        swap(root->left, root->right); // from top down-to bottom
        invertTree(root->left), invertTree(root->right);
        return root;
    }
};
// @lc code=end
