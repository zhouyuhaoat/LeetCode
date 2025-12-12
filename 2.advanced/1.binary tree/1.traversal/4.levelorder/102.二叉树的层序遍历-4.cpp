/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 15:12:00
 *   modified:  2025-03-15 23:33:26
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            res.emplace_back();
            for (int i = q.size(); i > 0; i--) { // reverse
                TreeNode *node = q.front();
                q.pop();
                res.back().emplace_back(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
        }
        return res;
    }
};
// @lc code=end
