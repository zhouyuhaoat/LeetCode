/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:29:08
 *   modified:  2025-03-09 16:05:09
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode *root) {
        queue<TreeNode *> q;
        q.emplace(root);
        int res = -1, level = 0, maxSum = INT_MIN;
        while (!q.empty()) {
            int sum = 0;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                res = level;
            }
            level++;
        }
        return res + 1;
    }
};
// @lc code=end
