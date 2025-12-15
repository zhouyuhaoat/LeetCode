/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 14:05:25
 *   modified:  2025-03-08 23:10:45
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start
class Solution {
private:
    int res = 0;

    void dfs(TreeNode *root, int depth) { // from top down-to bottom
        if (!root) return;
        res = max(res, depth + 1);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

public:
    int maxDepth(TreeNode *root) {
        dfs(root, 0);
        return res;
    }
};
// @lc code=end
