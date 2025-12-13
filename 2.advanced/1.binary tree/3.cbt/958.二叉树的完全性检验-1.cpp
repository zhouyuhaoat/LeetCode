/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:36:28
 *   modified:  2025-03-19 14:06:52
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    int count(TreeNode *root) {
        int size = 0;
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            size++;
            TreeNode *node = q.front();
            q.pop();
            if (node->left) q.emplace(node->left);
            if (node->right) q.emplace(node->right);
        }
        return size;
    }

public:
    bool isCompleteTree(TreeNode *root) {
        int size = count(root), cnt = 0;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (!node) break; // until the first nullptr
            cnt++;
            q.emplace(node->left);
            q.emplace(node->right);
        }
        return cnt == size;
    }
};
// @lc code=end
