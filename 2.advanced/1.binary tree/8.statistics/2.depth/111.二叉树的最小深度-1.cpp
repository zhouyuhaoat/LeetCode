/*
 *   author:    zhouyuhao
 *   created:   2024-12-21 14:28:37
 *   modified:  2025-03-10 17:19:32
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root) {
        int depth = 0;
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            depth++;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                // first leaf node in level order with the minimum depth
                if (!node->left && !node->right) return depth;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
        }
        return 0;
    }
};
// @lc code=end
