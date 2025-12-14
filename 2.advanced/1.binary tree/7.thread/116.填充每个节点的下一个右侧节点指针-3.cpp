/*
 *   author:    zhouyuhao
 *   created:   2024-12-23 15:00:26
 *   modified:  2025-12-13 17:26:34
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
        if (root->left) {
            root->left->next = root->right;
            if (root->next) {
                root->right->next = root->next->left;
            }
            dfs(root->left), dfs(root->right);
        }
    }

public:
    Node *connect(Node *root) {
        dfs(root);
        return root;
    }
};
// @lc code=end
