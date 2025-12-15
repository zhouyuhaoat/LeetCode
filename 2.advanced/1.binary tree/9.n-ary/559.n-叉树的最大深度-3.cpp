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
    int res = 0;

    void dfs(Node *root, int depth) { // from top down-to bottom
        if (!root) return;
        res = max(res, depth + 1);
        for (Node *child : root->children) {
            dfs(child, depth + 1);
        }
    }

public:
    int maxDepth(Node *root) {
        dfs(root, 0);
        return res;
    }
};
// @lc code=end
