/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:10:25
 *   modified:  2025-03-09 15:46:09
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            res.emplace_back();
            for (int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                res.back().emplace_back(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            if (res.size() % 2 == 0) ranges::reverse(res.back()); // use size as the flag
        }
        return res;
    }
};
// @lc code=end
