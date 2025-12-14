/*
 *   author:    zhouyuhao
 *   created:   2025-04-01 16:20:26
 *   modified:  2025-04-02 19:39:08
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
private:
    TreeNode *res;

    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q) { // whether the subtree contains p or q
        if (!root) return false;
        bool left = dfs(root->left, p, q), right = dfs(root->right, p, q);
        if ((left && right) || ((left || right) && (root->val == p->val || root->val == q->val))) {
            // different subtrees || (same subtree && root itself is p or q)
            res = root;
        }
        return left || right || (root->val == p->val || root->val == q->val);
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return res;
    }
};
// @lc code=end
