/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:24:57
 *   modified:  2025-03-16 10:40:48
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
    int depth(TreeNode* root) {
        if (!root) return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> res(d);
        queue<TreeNode*> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                res[d - 1].emplace_back(node->val); // from bottom to top
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            d--;
        }
        return res;
    }
};
// @lc code=end
