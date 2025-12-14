/*
 *   author:    zhouyuhao
 *   created:   2025-04-01 16:31:57
 *   modified:  2025-04-02 19:14:10
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
    unordered_map<TreeNode *, TreeNode *> par;
    unordered_map<TreeNode *, bool> vis;

    void dfs(TreeNode *root, TreeNode *parent) { // parent in parameter
        if (!root) return;
        par[root] = parent;
        dfs(root->left, root), dfs(root->right, root);
    }

    TreeNode *getFirstCommonNode(TreeNode *p, TreeNode *q) {
        while (p) {
            vis[p] = true;
            p = par[p];
        }
        while (q) {
            if (vis[q]) return q;
            q = par[q];
        }
        return nullptr;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, nullptr);
        return getFirstCommonNode(p, q);
    }
};
// @lc code=end
