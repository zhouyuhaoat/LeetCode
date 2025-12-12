/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 10:24:57
 *   modified:  2025-03-16 10:40:48
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

// @lc code=start
class Solution {
private:
    int getLevel(TreeNode *root) {
        if (!root) return 0;
        return max(getLevel(root->left), getLevel(root->right)) + 1;
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        int level = getLevel(root);
        vector<vector<int>> res(level); // reserve for reverse
        queue<TreeNode *> q;
        if (root) q.emplace(root);
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                res[level - 1].emplace_back(node->val);
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            level--;
        }
        return res;
    }
};
// @lc code=end
