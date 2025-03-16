/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:13:25
 *   modified:  2025-03-09 13:47:30
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
            deque<int> level; // double-ended queue
            for (int i = q.size(); i > 0; i--) {
                TreeNode* node = q.front();
                q.pop();
                flag ? level.emplace_back(node->val) : level.emplace_front(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            res.emplace_back(vector<int>(level.begin(), level.end()));
            flag = !flag;
        }
        return res;
    }
};
// @lc code=end
