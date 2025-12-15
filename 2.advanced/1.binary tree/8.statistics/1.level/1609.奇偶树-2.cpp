/*
 *   author:    zhouyuhao
 *   created:   2024-12-17 13:11:58
 *   modified:  2025-03-09 15:54:24
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
 */

// @lc code=start
class Solution {
public:
    bool isEvenOddTree(TreeNode *root) {
        queue<TreeNode *> q;
        q.emplace(root);
        int level = 0;
        while (!q.empty()) {
            bool even = level % 2 == 0;
            int prev = even ? INT_MIN : INT_MAX;
            for (int i = q.size(); i > 0; i--) {
                TreeNode *node = q.front();
                q.pop();
                if (node->val % 2 == level % 2) return false;
                if (even) {
                    if (node->val <= prev) return false;
                } else {
                    if (node->val >= prev) return false;
                }
                prev = node->val;
                if (node->left) q.emplace(node->left);
                if (node->right) q.emplace(node->right);
            }
            level++;
        }
        return true;
    }
};
// @lc code=end
