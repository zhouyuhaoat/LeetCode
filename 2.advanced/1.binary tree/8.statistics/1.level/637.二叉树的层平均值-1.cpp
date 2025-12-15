/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:14:55
 *   modified:  2025-03-09 15:50:17
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode *root) {
        vector<double> res;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            int size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            res.emplace_back(sum / size);
        }
        return res;
    }
};
// @lc code=end
