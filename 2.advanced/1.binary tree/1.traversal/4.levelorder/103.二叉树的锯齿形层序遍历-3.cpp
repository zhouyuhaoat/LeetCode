/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:05:19
 *   modified:  2025-03-09 13:46:59
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (root) q.emplace(root);
        bool flag = true;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size); // reserve for reverse
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level[flag ? i : size - i - 1] = node->val;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            res.emplace_back(level);
            flag = !flag;
        }
        return res;
    }
};
// @lc code=end
