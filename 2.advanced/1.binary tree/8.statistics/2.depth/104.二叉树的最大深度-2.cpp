/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:49:10
 *   modified:  2025-03-08 23:07:06
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
    int dfs(TreeNode *root) { // from bottom up-to top
        if (!root) return 0;
        return max(dfs(root->left), dfs(root->right)) + 1;
    }

public:
    int maxDepth(TreeNode *root) {
        return dfs(root);
    }
};
// @lc code=end
