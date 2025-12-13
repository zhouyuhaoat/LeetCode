/*
 *   author:    zhouyuhao
 *   created:   2025-03-19 12:16:10
 *   modified:  2025-03-19 21:20:00
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
    int countHeight(TreeNode *root) { // [0, height)
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int count(TreeNode *root) {
        if (!root) return 0;
        int height = countHeight(root);
        if (height == 1) return 1; // avoid negative shift
        return upper_bound(root, height) - 1; // the last exist node
    }

    int upper_bound(TreeNode *root, int height) {
        // the id (1-based index) of the first node of height h in complete binary tree is 2^(h-1)
        int lo = pow(2, height - 1), hi = pow(2, height);
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (!exist(root, height, mi)) { // the first non-exist node
                hi = mi;
            } else {
                lo = mi + 1;
            }
        }
        return hi;
    }

    bool exist(TreeNode *root, int height, int id) { // whether the node exists
        int hiBit = height - 1; // the highest bit
        int bits = 1 << (hiBit - 1); // hiBit - 1 since root, also the length of path
        TreeNode *node = root;
        while (node && bits) {
            if (id & bits) {
                node = node->right;
            } else {
                node = node->left;
            }
            bits >>= 1;
        }
        return node;
    }

public:
    int countNodes(TreeNode *root) {
        return count(root);
    }
};
// @lc code=end
