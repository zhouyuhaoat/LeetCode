/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:49:00
 *   modified:  2025-03-09 16:15:49
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
 */

// @lc code=start
class Solution {
private:
    int sum = 0, maxLevel = -1;

    void dfs(TreeNode *root, int level) {
        if (!root) return;
        if (level > maxLevel) { // new deeper level
            maxLevel = level;
            sum = root->val;
        } else if (level == maxLevel) { // the deepest level
            sum += root->val;
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

public:
    int deepestLeavesSum(TreeNode *root) {
        dfs(root, 0);
        return sum;
    }
};
// @lc code=end
