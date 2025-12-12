/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 14:56:54
 *   modified:  2025-03-15 23:31:44
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        vector<int> level;
        if (root) q.emplace(root), q.emplace(nullptr); // separator
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) {
                res.emplace_back(move(level));
                if (!q.empty()) q.emplace(nullptr);
            } else {
                level.emplace_back(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
        }
        return res;
    }
};
// @lc code=end
