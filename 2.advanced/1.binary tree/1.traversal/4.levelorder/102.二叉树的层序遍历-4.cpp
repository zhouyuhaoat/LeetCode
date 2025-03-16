/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 15:14:21
 *   modified:  2025-03-15 23:34:04
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<TreeNode*> cur = {root}; // current level
        while (!cur.empty()) {
            vector<TreeNode*> next; // next level
            res.emplace_back();
            for (TreeNode* node : cur) {
                res.back().emplace_back(node->val);
                if (node->left) next.emplace_back(node->left);
                if (node->right) next.emplace_back(node->right);
            }
            cur = move(next); // move next to cur
        }
        return res;
    }
};
// @lc code=end
