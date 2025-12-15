/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:18:04
 *   modified:  2025-03-09 16:10:29
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
class Solution {
private:
    vector<int> cnt;
    vector<double> sum;

    void dfs(TreeNode *root, int level) {
        if (!root) return;
        if (level < (int)sum.size()) {
            sum[level] += root->val;
            cnt[level]++;
        } else { // new level
            sum.emplace_back(root->val);
            cnt.emplace_back(1);
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

public:
    vector<double> averageOfLevels(TreeNode *root) {
        dfs(root, 0);
        vector<double> res;
        for (int i = 0; i < (int)sum.size(); i++) {
            res.emplace_back(sum[i] / cnt[i]);
        }
        return res;
    }
};
// @lc code=end
