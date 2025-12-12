/*
 *   author:    zhouyuhao
 *   created:   2025-03-09 10:21:52
 *   modified:  2025-03-09 10:23:00
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root) return {};
        vector<int> res = {root->val};
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        res.insert(res.end(), left.begin(), left.end());
        res.insert(res.end(), right.begin(), right.end());
        return res;
    }
};
// @lc code=end
