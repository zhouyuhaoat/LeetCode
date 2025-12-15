/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:50:56
 *   modified:  2025-03-10 17:15:45
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode *root) {
        int depth = 0;
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            depth++;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
        }
        return depth;
    }
};
// @lc code=end
