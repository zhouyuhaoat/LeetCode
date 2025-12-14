/*
 *   author:    zhouyuhao
 *   created:   2025-04-01 16:31:57
 *   modified:  2025-04-02 19:11:14
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode *, TreeNode *> par; // parent
    unordered_map<TreeNode *, bool> vis;

    void dfs(TreeNode *root) {
        if (root->left) {
            par[root->left] = root;
            dfs(root->left);
        }
        if (root->right) {
            par[root->right] = root;
            dfs(root->right);
        }
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
        par[root] = nullptr;
        dfs(root); // parent mapping
        return getFirstCommonNode(p, q);
    }
};
// @lc code=end
