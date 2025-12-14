/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 16:46:24
 *   modified:  2025-12-13 18:43:35
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    vector<TreeNode *> in;

    void inorder(TreeNode *root) {
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            in.emplace_back(root);
            root = root->right;
        }
    }

    void construct() {
        for (int i = 1; i < (int)in.size(); i++) {
            in[i - 1]->left = nullptr, in[i - 1]->right = in[i];
        }
        in.back()->left = nullptr, in.back()->right = nullptr;
    }

public:
    TreeNode *increasingBST(TreeNode *root) {
        inorder(root);
        construct();
        return in[0];
    }
};
// @lc code=end
