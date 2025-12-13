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
    int countLeftHeight(TreeNode *root) {
        int leftH = 0;
        while (root) {
            leftH++;
            root = root->left;
        }
        return leftH;
    }

    int countRightHeight(TreeNode *root) {
        int rightH = 0;
        while (root) {
            rightH++;
            root = root->right;
        }
        return rightH;
    }

    int count(TreeNode *root) {
        if (!root) return 0;
        int leftH = countLeftHeight(root), rightH = countRightHeight(root); // height of subtree
        if (leftH == rightH) return pow(2, leftH) - 1; // size of complete binary tree
        return count(root->left) + count(root->right) + 1;
    }

public:
    int countNodes(TreeNode *root) {
        return count(root);
    }
};
// @lc code=end
