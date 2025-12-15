/*
 *   author:    zhouyuhao
 *   created:   2024-12-22 19:14:52
 *   modified:  2025-03-10 17:57:04
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
class Solution {
private:
    int res = INT_MAX;

    void dfs(TreeNode *root, int depth) { // from top down-to bottom
        if (!root || depth + 1 >= res) return; // pruning
        if (!root->left && !root->right) { // leaf node
            res = min(res, depth + 1);
            return;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

public:
    int minDepth(TreeNode *root) {
        dfs(root, 0);
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end
