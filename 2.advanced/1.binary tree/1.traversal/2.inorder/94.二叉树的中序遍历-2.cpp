/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 09:52:45
 *   modified:  2025-03-04 14:10:41
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root) return {};
        vector<int> res;
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.emplace_back(root->val);
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};
// @lc code=end
