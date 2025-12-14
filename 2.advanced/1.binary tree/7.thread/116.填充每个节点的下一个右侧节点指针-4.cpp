/*
 *   author:    zhouyuhao
 *   created:   2024-12-22 22:15:11
 *   modified:  2025-12-13 17:37:47
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
    void dfs(Node *left, Node *right) {
        if (!(left && right)) return;
        left->next = right;
        dfs(left->left, left->right);
        dfs(left->right, right->left); // different parent
        dfs(right->left, right->right);
    }

public:
    Node *connect(Node *root) {
        if (!root) return nullptr;
        dfs(root->left, root->right);
        return root;
    }
};
// @lc code=end
