/*
 *   author:    zhouyuhao
 *   created:   2025-03-19 12:16:10
 *   modified:  2025-03-19 18:18:49
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
    int countHeight(TreeNode *root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int count(TreeNode *root) {
        if (!root) return 0;
        int leftSubH = countHeight(root->left), rightSubH = countHeight(root->right);
        if (leftSubH == rightSubH) { // left subtree is full
            return (pow(2, leftSubH) - 1) + count(root->right) + 1;
        } else { // right subtree is full
            return count(root->left) + (pow(2, rightSubH) - 1) + 1;
        }
    }

public:
    int countNodes(TreeNode *root) {
        return count(root);
    }
};
// @lc code=end
