/*
 *   author:    zhouyuhao
 *   created:   2025-03-06 22:34:41
 *   modified:  2025-03-15 23:16:21
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* pre = nullptr;
        while (root || !stk.empty()) {
            while (root) { // goAlongVine -> leftmost
                stk.emplace(root);
                root = root->left; // as left as possible
            }
            root = stk.top();
            if (root->right && root->right != pre) {
                root = root->right; // only right if necessary
            } else {
                res.emplace_back(root->val);
                pre = root;
                stk.pop();
                root = nullptr;
            }
        }
        return res;
    }
};
// @lc code=end
