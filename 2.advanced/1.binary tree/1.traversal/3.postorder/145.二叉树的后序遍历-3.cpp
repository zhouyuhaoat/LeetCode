/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 19:20:24
 *   modified:  2025-03-07 12:43:18
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
        vector<int> res;
        stack<TreeNode *> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);
            // variant of preorder: root, right, left
            // tail recursion: left child last, then right child
            if (root->left) stk.emplace(root->left);
            if (root->right) stk.emplace(root->right);
        }
        // variant of preorder -> reverse -> postorder
        ranges::reverse(res);
        return res;
    }
};
// @lc code=end
