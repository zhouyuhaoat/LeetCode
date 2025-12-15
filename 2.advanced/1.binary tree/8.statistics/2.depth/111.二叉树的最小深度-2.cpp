/*
 *   author:    zhouyuhao
 *   created:   2024-12-21 14:28:37
 *   modified:  2025-03-10 17:53:30
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
    int dfs(TreeNode *root) { // from bottom up-to top
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (left && right) { // non-leaf node
            return min(left, right) + 1;
        } else { // at most one child
            return max(left, right) + 1;
        }
    }

public:
    int minDepth(TreeNode *root) {
        return dfs(root);
    }
};
// @lc code=end
