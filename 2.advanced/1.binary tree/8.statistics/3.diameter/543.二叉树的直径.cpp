/*
 *   author:    zhouyuhao
 *   created:   2024-12-18 20:05:04
 *   modified:  2025-03-08 23:29:01
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
private:
    int dia = 0; // diameter: the longest path between any two nodes in a tree

    int dfs(TreeNode *root) { // depth or height: length from root to leaf
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        dia = max(dia, left + right); // diameter passes through
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return dia;
    }
};
// @lc code=end
