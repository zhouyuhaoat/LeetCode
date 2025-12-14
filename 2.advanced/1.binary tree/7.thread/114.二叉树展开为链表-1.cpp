/*
 *   author:    zhouyuhao
 *   created:   2024-12-22 21:59:46
 *   modified:  2025-12-13 18:58:14
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    vector<TreeNode *> pre;

    void preorder(TreeNode *root) {
        stack<TreeNode *> stk;
        while (root || !stk.empty()) {
            while (root) {
                stk.emplace(root);
                pre.emplace_back(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
    }

    void construct() {
        for (int i = 1; i < (int)pre.size(); i++) {
            pre[i - 1]->left = nullptr, pre[i - 1]->right = pre[i];
        }
        pre.back()->left = nullptr, pre.back()->right = nullptr;
    }

public:
    void flatten(TreeNode *root) {
        preorder(root);
        if (!pre.empty()) construct();
    }
};
// @lc code=end
