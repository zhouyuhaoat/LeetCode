/*
 *   author:    zhouyuhao
 *   created:   2024-12-18 19:44:34
 *   modified:  2025-03-07 11:11:04
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
        vector<int> res;
        stack<TreeNode *> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
            // tail recursion: right child first, then left child
            if (root->right) stk.emplace(root->right);
            if (root->left) stk.emplace(root->left);
        }
        return res;
    }
};
// @lc code=end
