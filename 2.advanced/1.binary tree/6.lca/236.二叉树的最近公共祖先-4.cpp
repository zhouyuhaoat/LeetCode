/*
 *   author:    zhouyuhao
 *   created:   2025-04-01 16:20:26
 *   modified:  2025-04-02 19:33:38
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // candidate of LCA, also can indicate whether the subtree contains p or q
        if (!root) return nullptr;
        if (root == p || root == q) return root; // root itself
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root; // different subtrees
        if (!left && right) return right; // right subtree
        if (left && !right) return left; // left subtree
        return nullptr; // not found
    }
};
// @lc code=end
