/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 09:44:17
 *   modified:  2025-03-04 14:08:22
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (true) {
            if (root) {
                stk.emplace(root);
                root = root->left;
            } else if (!stk.empty()) {
                root = stk.top();
                stk.pop();
                res.emplace_back(root->val);
                root = root->right;
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end
