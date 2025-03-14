/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 09:36:52
 *   modified:  2025-03-07 22:35:34
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
private:
    void goAlongVine(TreeNode* root, stack<TreeNode*>& stk) {
        while (root) {
            stk.emplace(root); // maintain recursion stack for root and right child
            root = root->left; // leftmost
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk; // recursion stack
        while (true) {
            goAlongVine(root, stk);
            if (stk.empty()) break;
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val); // inorder: visit root after left child, before left child
            root = root->right; // recursion
        }
        return res;
    }
};
// @lc code=end
