/*
 *   author:    zhouyuhao
 *   created:   2024-12-16 14:29:11
 *   modified:  2025-03-09 17:17:17
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q) return p == q; // at least one is nullptr
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
// @lc code=end
