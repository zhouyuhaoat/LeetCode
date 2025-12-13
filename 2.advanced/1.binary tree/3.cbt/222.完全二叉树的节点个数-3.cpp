/*
 *   author:    zhouyuhao
 *   created:   2025-03-19 12:16:10
 *   modified:  2025-03-19 12:24:12
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
    int size = 0;

    void count(TreeNode *root) {
        if (!root) return;
        size++;
        count(root->left), count(root->right);
    }

public:
    int countNodes(TreeNode *root) {
        count(root);
        return size;
    }
};
// @lc code=end
