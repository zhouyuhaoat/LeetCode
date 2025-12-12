/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 19:20:24
 *   modified:  2025-03-09 10:33:36
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) return {};
        vector<int> res;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        res.emplace_back(root->val);
        return res;
    }
};
// @lc code=end
