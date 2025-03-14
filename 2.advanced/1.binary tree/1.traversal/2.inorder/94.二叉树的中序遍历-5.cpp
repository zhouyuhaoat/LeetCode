/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 11:12:00
 *   modified:  2025-03-07 11:12:49
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
        while (root || !stk.empty()) {
            if (root) {
                stk.emplace(root);
                root = root->left;
            } else {
                root = stk.top();
                stk.pop();
                res.emplace_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end
