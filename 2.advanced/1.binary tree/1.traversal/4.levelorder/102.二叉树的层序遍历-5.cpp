/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:16:20
 *   modified:  2025-03-16 10:02:37
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
private:
    void levelorder(TreeNode* root, int level, vector<vector<int>>& res) {
        if (!root) return;
        if (level >= (int)res.size()) { // new level
            // ensure 'res[level]' exists when 'level == res.size()'
            res.emplace_back();
        }
        res[level].emplace_back(root->val);
        levelorder(root->left, level + 1, res);
        levelorder(root->right, level + 1, res);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        // must start from level 0, since 'res.size()' is 0 at the beginning
        return res;
    }
};
// @lc code=end
