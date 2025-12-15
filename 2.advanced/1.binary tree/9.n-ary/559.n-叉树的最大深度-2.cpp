/*
 *   author:    zhouyuhao
 *   created:   2024-12-18 20:18:37
 *   modified:  2025-03-10 17:22:47
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
class Solution {
private:
    int dfs(Node *root) { // from bottom up-to top
        if (!root) return 0;
        int depth = 1;
        for (Node *child : root->children) {
            depth = max(depth, dfs(child) + 1);
        }
        return depth;
    }

public:
    int maxDepth(Node *root) {
        return dfs(root);
    }
};
// @lc code=end
