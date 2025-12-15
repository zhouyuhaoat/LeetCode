/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:43:42
 *   modified:  2025-03-09 15:51:00
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode *root) {
        queue<TreeNode *> q;
        q.emplace(root);
        int res = 0;
        while (!q.empty()) {
            int sum = 0;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            res = sum;
        }
        return res;
    }
};
// @lc code=end
