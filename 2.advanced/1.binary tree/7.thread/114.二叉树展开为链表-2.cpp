/*
 *   author:    zhouyuhao
 *   created:   2024-12-22 20:00:01
 *   modified:  2025-12-14 09:48:53
 *   project:   LeetCode of labuladong
 *   venue:     914, Harbin
 */

/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
class Solution {
private:
    TreeNode dummy, *tail = &dummy; // tail insertion

    void preorder(TreeNode *root) {
        stack<TreeNode *> stk;
        if (root) stk.emplace(root);
        while (!stk.empty()) {
            root = stk.top();
            stk.pop();
            tail->left = nullptr; // (delayed) cut
            tail = tail->right = root; // connect
            if (root->right) stk.emplace(root->right);
            if (root->left) stk.emplace(root->left);
        }
    }

public:
    void flatten(TreeNode *root) {
        preorder(root);
    }
};
// @lc code=end
