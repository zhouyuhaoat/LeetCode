/*
 *   author:    zhouyuhao
 *   created:   2025-03-19 12:16:10
 *   modified:  2025-03-19 12:20:28
 *   project:   LeetCode of labuladong
 *   venue:     226, Harbin
 */

/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */

// @lc code=start
class Solution {
private:
    int count(TreeNode *root) {
        if (!root) return 0;
        return count(root->left) + count(root->right) + 1;
    }

public:
    int countNodes(TreeNode *root) {
        return count(root);
    }
};
// @lc code=end
