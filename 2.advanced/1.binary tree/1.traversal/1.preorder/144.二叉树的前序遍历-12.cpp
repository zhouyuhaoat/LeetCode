/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 12:15:35
 *   modified:  2025-03-15 23:04:43
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            if (root) {
                if (root->right) stk.emplace(root->right);
                if (root->left) stk.emplace(root->left);
                stk.emplace(root), stk.emplace(nullptr); // separator or mark
            } else {
                res.emplace_back(stk.top()->val); // next to separator/mark
                stk.pop();
            }
        }
        return res;
    }
};
// @lc code=end
