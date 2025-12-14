/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 15:02:43
 *   modified:  2025-12-13 17:44:52
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
class Solution {
private:
    void dfs(Node *root) {
        if (!root) return;
        Node *left = root->left, *right = root->right;
        while (left) {
            left->next = right;
            left = left->right; // rightmost vine of left subtree
            right = right->left; // leftmost vine of right subtree
        }
        dfs(root->left), dfs(root->right);
    }

public:
    Node *connect(Node *root) {
        dfs(root);
        return root;
    }
};
// @lc code=end
