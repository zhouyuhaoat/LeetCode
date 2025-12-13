/*
 *   author:    zhouyuhao
 *   created:   2025-03-19 12:16:10
 *   modified:  2025-03-19 12:18:12
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode *root) {
        int size = 0;
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            size++;
            TreeNode *node = q.front();
            q.pop();
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
        return size;
    }
};
// @lc code=end
