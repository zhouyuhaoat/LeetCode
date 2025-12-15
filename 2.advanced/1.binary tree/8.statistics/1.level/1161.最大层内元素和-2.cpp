/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:39:50
 *   modified:  2025-03-05 12:53:50
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
 */

// @lc code=start
class Solution {
private:
    vector<int> sum;

    void dfs(TreeNode *root, int level) {
        if (!root) return;
        if (level < (int)sum.size()) {
            sum[level] += root->val;
        } else { // new level
            sum.emplace_back(root->val);
        }
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

public:
    int maxLevelSum(TreeNode *root) {
        dfs(root, 0);
        int res = distance(sum.begin(), ranges::max_element(sum));
        return res + 1;
    }
};
// @lc code=end
