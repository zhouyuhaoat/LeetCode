/*
 *   author:    zhouyuhao
 *   created:   2025-03-07 10:38:47
 *   modified:  2025-03-08 18:04:11
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
private:
    void addPath(TreeNode* root, vector<int>& res) {
        int cnt = 0;
        while (root) {
            res.emplace_back(root->val);
            root = root->right;
            cnt++;
        }
        reverse(res.end() - cnt, res.end());
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode dummy(0, root, nullptr); // dummy or sentinel of tree
        root = &dummy;
        while (root) {
            if (root->left) {
                TreeNode* pre = root->left;
                while (pre->right && pre->right != root) {
                    pre = pre->right;
                }
                if (!pre->right) {
                    pre->right = root;
                    root = root->left;
                } else {
                    pre->right = nullptr;
                    addPath(root->left, res);
                    root = root->right;
                }
            } else {
                root = root->right;
            }
        }
        return res;
    }
};
// @lc code=end
